/*ESCRITO POR: Gustavo Baron Lauritzen e Matheus Baron Lauritzen*/

/*CRIACAO DO SCHEMA DA BIBLIOTECA*/
CREATE SCHEMA IF NOT EXISTS biblioteca;
SET SEARCH_PATH = biblioteca;

/*CRIACAO DAS TABELAS*/
/*tabela livros*/
CREATE TABLE livros (
    id_livro SERIAL PRIMARY KEY,
    titulo TEXT NOT NULL,
    autor TEXT NOT NULL,
    ano_publicacao INTEGER,
    disponivel BOOLEAN DEFAULT TRUE
);

/*tabela membros*/
CREATE TABLE membros (
    id_membro SERIAL PRIMARY KEY,
    nome TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    data_cadastro DATE NOT NULL
);

/*tabela emprestimos*/
CREATE TABLE emprestimos (
    id_emprestimo SERIAL PRIMARY KEY,
    id_livro INTEGER REFERENCES Livros(id_livro),
    id_membro INTEGER REFERENCES Membros(id_membro),
    data_emprestimo DATE NOT NULL,
    data_devolucao DATE
);

/*INSERCAO DOS DADOS DE TESTES NAS TABELAS*/
/*tabela livros*/
INSERT INTO livros (titulo, autor, ano_publicacao) VALUES 
('Dom Quixote', 'Miguel de Cervantes', 1605),
('O Pequeno Príncipe', 'Antoine de Saint-Exupéry', 1943),
('Hamlet', 'William Shakespeare', 1603),
('Cem Anos de Solidão', 'Gabriel Garcia Márquez', 1967),
('Orgulho e Preconceito', 'Jane Austen', 1813),
('1984', 'George Orwell', 1949),
('O Senhor dos Anéis', 'J.R.R. Tolkien', 1954),
('A Divina Comédia', 'Dante Alighieri', 1320);

/*tabela membros*/
INSERT INTO membros (nome, email, data_cadastro) VALUES
('Ana Silva', 'ana.silva@example.com', '2022-01-10'),
('Bruno Gomes', 'bruno.gomes@example.com', '2022-02-15'),
('Carlos Eduardo', 'carlos.eduardo@example.com', '2022-03-20'),
('Daniela Rocha', 'daniela.rocha@example.com', '2022-05-05'),
('Eduardo Lima', 'eduardo.lima@example.com', '2022-06-10'),
('Fernanda Martins', 'fernanda.martins@example.com', '2022-07-15'),
('Gustavo Henrique', 'gustavo.henrique@example.com', '2022-08-20'),
('Helena Souza', 'helena.souza@example.com', '2022-09-25');

/*tabela emprestimos*/
INSERT INTO emprestimos (id_livro, id_membro, data_emprestimo, data_devolucao) VALUES
(1, 1, '2022-04-01', NULL),
(2, 2, '2022-04-03', '2022-04-10'),
(3, 3, '2022-04-05', NULL),
(4, 4, '2022-10-01', NULL),
(5, 5, '2022-10-03', '2022-10-17'),
(2, 3, '2022-10-06', NULL),
(1, 2, '2022-10-08', '2022-10-15'),
(3, 1, '2022-10-10', NULL),
(3, 2, '2022-11-01', NULL),
(2, 3, '2022-11-03', NULL),
(1, 4, '2022-11-05', NULL),
(5, 1, '2022-11-07', '2022-11-21'),
(4, 5, '2022-11-09', '2022-11-23'),
(2, 1, '2022-11-12', NULL),
(3, 4, '2022-11-14', '2022-11-28'),
(1, 3, '2022-11-16', NULL),
(5, 2, '2022-11-18', '2022-11-25'),
(4, 1, '2022-11-20', '2022-12-04');

/*RESOLUCAO DOS TRIGGERS*/
/*a. Trigger de Atualização de Disponibilidade: Após um empréstimo ser efetivado, atualizar 
a disponibilidade do livro para false.*/

CREATE OR REPLACE FUNCTION atualizar_disponibilidade()
RETURNS TRIGGER AS $$
BEGIN
	UPDATE Livros
	SET disponivel = FALSE
	WHERE id_livros = NEW.id_livros;
	
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER atualizar_disponibilidade_apos
AFTER INSERT ON Emprestimos
FOR EACH ROW
EXECUTE FUNCTION atualizar_disponibilidade();

/*b. Trigger de Devolução de Livro: Quando um livro é devolvido, atualizar a disponibilidade 
do livro para true.*/

CREATE OR REPLACE FUNCTION devolver_livros()
RETURNS TRIGGER AS $$
BEGIN
	UPDATE Livros
	SET disponivel = TRUE
	WHERE id_livro = OLD.id_livros;
	
	RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER devolucao_livros
AFTER UPDATE OF data_devolucao ON Emprestimos
FOR EACH ROW
WHEN (OLD.data_devolucao IS NULL AND NEW.data_devolucao IS NOT NULL)
EXECUTE FUNCTION devolver_livros();

/*c. Trigger de Auditoria de Empréstimos: Criar um trigger que registre em uma tabela de 
auditoria cada vez que um empréstimo for realizado. Esta tabela deve armazenar: id 
da auditoria (serial), timestamp, usuário(current_user), id do empréstimo, data do 
empréstimo e ação ("Empréstimo Realizado").*/

CREATE TABLE Auditoria_Emprestimos (
    id_registro SERIAL PRIMARY KEY,
    data_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    usuario VARCHAR(100),
    id_emprestimo INTEGER,
    data_emprestimo DATE,
    acao VARCHAR(100)
);
CREATE OR REPLACE FUNCTION registrar_auditoria_emprestimo()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO Auditoria_Emprestimos (usuario, id_emprestimo, data_emprestimo, acao)
    VALUES (current_user, NEW.id_emprestimo, NEW.data_registro::DATE, 'Empréstimo Realizado');
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER auditoria_emprestimos
AFTER INSERT ON Emprestimos
FOR EACH ROW
EXECUTE FUNCTION registrar_auditoria_emprestimo();

/*d. Trigger de Verificação de Disponibilidade: Antes de um empréstimo ser efetivado, 
verificar se o livro está disponível. Caso o livro esteja indisponível, lançar uma exceção
com a informação 'O livro % está indisponível para empréstimo.*/

CREATE OR REPLACE FUNCTION verificar_disponibilidade_livro()
RETURNS TRIGGER AS $$
BEGIN
	IF NOT EXISTS (SELECT 1 FROM livro WHERE id_livro = NEW.id_livro AND disponivel = TRUE) THEN 
		RAISE EXCEPTION 'O livro % está indisponível para empréstimo.', NEW.id_livro;
	END IF;
	
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER verificacao_livro
BEFORE INSERT ON Emprestimos
FOR EACH ROW
EXECUTE FUNCTION verificar_disponibilidade_livro();

/*e. Trigger de Limite de Empréstimos: Impedir que um membro faça mais de 5 empréstimos 
simultâneos. Deve verificar a quantidade de empréstimos do membro. Considere 
empréstimos sem data de devolução como empréstimos em aberto.*/

CREATE OR REPLACE FUNCTION checar_emprestimos() RETURNS TRIGGER AS $check_emprestimos$
	BEGIN
		IF(	SELECT COUNT(*) FROM Emprestimos
			WHERE Emprestimos.id_membro = NEW.id_membro) > 5 THEN
			RAISE EXCEPTION 'Erro: O membro especificado atingiu o limite de 5 emprestimos!';
		END IF;
		RETURN NEW;
	END
$check_emprestimos$ LANGUAGE plpgsql;

CREATE TRIGGER check_emprestimos BEFORE INSERT ON Emprestimos
FOR EACH ROW
	EXECUTE FUNCTION checar_emprestimos();

/*f. Trigger de Atualização de Livros: Sempre que as informações de um livro forem 
atualizadas, registrar a alteração em uma tabela de histórico. Registrando as seguintes 
informações: id_historico, id_livro, titulo_antigo, autor_antigo, ano_publicacao_antigo e 
a data de alteração (timestamp).*/

CREATE TABLE historico_livros (
    id_historico SERIAL PRIMARY KEY,
    id_livro INTEGER REFERENCES Livros(id_livro),
    titulo_antigo TEXT NOT NULL,
    autor_antigo TEXT NOT NULL,
    ano_publicacao_antigo INTEGER,
    data_update TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE OR REPLACE FUNCTION quandoAtualizarLivro() RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO Historico_Livros(
        id_livro,
        titulo_antigo,
        autor_antigo,
        ano_publicacao_antigo,
        data_update
    ) VALUES (
        OLD.id_livro,
        OLD.titulo,
        OLD.autor,
        OLD.ano_publicacao,
        now()
    );
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER quandoAtualizarLivro AFTER UPDATE ON Livros
FOR EACH ROW
EXECUTE FUNCTION quandoAtualizarLivro();

/*g. Trigger de Exclusão de Membro: Quando um membro for excluído, verificar se todos os 
livros foram devolvidos antes de permitir a exclusão. Caso ainda existam livros com data 
de devolução em aberto relacionados ao membro, apresentar a mensagem: 'Não é 
possível excluir o membro %, pois possui empréstimos pendentes.'*/

CREATE OR REPLACE FUNCTION quandoExlcuirMembro() RETURNS TRIGGER AS $quandoExlcuirMembro$
    BEGIN
        IF EXISTS (
            SELECT 1 FROM Emprestimos
            INNER JOIN livros ON livros.id_livro = Emprestimos.id_livro
            WHERE Emprestimos.id_membro = OLD.id_membro
            AND livros.disponivel = false
        ) THEN
            RAISE EXCEPTION 'Não é possível excluir o membro %, pois possui empréstimos pendentes.', OLD.id_membro;
        ELSE
            RETURN OLD;
        END IF;
    END;
$quandoExlcuirMembro$ LANGUAGE plpgsql;

CREATE TRIGGER quandoExlcuirMembro BEFORE DELETE ON Membros
FOR EACH ROW
    EXECUTE FUNCTION quandoExlcuirMembro();

/*h. Trigger de Auditoria para Inserção, Atualização e Deleção de Livros: Crie um trigger que 
registre em uma tabela de auditoria (AuditoriaLivros) toda vez que um novo livro for 
inserido, modificado, ou deletado, incluindo as seguintes informações: id_audit_livro 
(serial), current_user, a operação ('I' inserção, 'U' update, e 'D' delete) informações 
como o título do livro, autor, e a data e hora da operação.*/

CREATE TABLE AuditoriaLivros (
    id_audit_livro SERIAL PRIMARY KEY,
    usuario TEXT,
    operacao CHAR(1),
    titulo TEXT,
    autor TEXT,
    data_hora_operacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE OR REPLACE FUNCTION auditar_livro()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        INSERT INTO AuditoriaLivros (usuario, operacao, titulo, autor)
        VALUES (current_user, 'I', NEW.titulo, NEW.autor);
    ELSIF TG_OP = 'UPDATE' THEN
        INSERT INTO AuditoriaLivros (usuario, operacao, titulo, autor)
        VALUES (current_user, 'U', NEW.titulo, NEW.autor);
    ELSIF TG_OP = 'DELETE' THEN
        INSERT INTO AuditoriaLivros (usuario, operacao, titulo, autor)
        VALUES (current_user, 'D', OLD.titulo, OLD.autor);
    END IF;
    RETURN NULL;
END;
$$ LANGUAGE plpgsql;

/*Trigger para inserção de auditoria*/
CREATE TRIGGER auditar_insercao_livro
AFTER INSERT ON Livros
FOR EACH ROW
EXECUTE FUNCTION auditar_livro();

/*Trigger para atualização de auditoria*/
CREATE TRIGGER auditar_atualizacao_livro
AFTER UPDATE ON Livros
FOR EACH ROW
EXECUTE FUNCTION auditar_livro();

/*Trigger para deleção de auditoria*/
CREATE TRIGGER auditar_delecao_livro
AFTER DELETE ON Livros
FOR EACH ROW
EXECUTE FUNCTION auditar_livro();

/*i. Trigger para Verificar a Exclusão de Livros: Crie um trigger que previna a exclusão de 
um livro da tabela Livros se ele estiver atualmente emprestado.*/

CREATE OR REPLACE FUNCTION verificar_exclusao_livro()
RETURNS TRIGGER AS $$
DECLARE
    livro_emprestado BOOLEAN;
BEGIN
    SELECT EXISTS (SELECT 1 FROM emprestimos WHERE id_livro = OLD.id_livro AND data_devolucao IS NULL)
    INTO livro_emprestado;
    
    IF livro_emprestado THEN
        RAISE EXCEPTION 'O livro está atualmente emprestado e não pode ser excluído.';
    END IF;
    
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER verificar_exclusao_trigger
BEFORE DELETE ON livros
FOR EACH ROW
EXECUTE FUNCTION verificar_exclusao_livro();