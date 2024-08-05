-- PARA ESTA ATIVIDADE, EFETUE AS SEGUINTES ETAPAS:
--	1. EFETUE A CRIAÇÃO DAS TABELAS, LINHAS 5 A 62
-- 	2. EFETUE A INSERÇÃO DOS REGISTROS, LINAS 66 A 114
-- 	3. EFETUE A CRIAÇÃO DE FUNÇÕES PARA CADA UM DOS EXERCICIOS A PARTIR DA LINHA 120

/* clinica veterinaria lógico */
CREATE SCHEMA IF NOT EXISTS clinica_vet;

SET SEARCH_PATH = clinica_vet
-- DROP SCHEMA clinica_vet;
-- DROP TABLE Endereco;

CREATE TABLE Endereco (
    cod integer PRIMARY KEY,
    logradouro varchar(100),
    numero integer,
    complemento varchar(50),
    cep varchar(12),
    cidade varchar(50),
    uf varchar(2)
);

CREATE TABLE Responsavel (
    cod integer PRIMARY KEY,
    nome varchar(100) NOT NULL,
    cpf varchar(12) NOT NULL,
    fone varchar(50) NOT NULL,
    email varchar(100) NOT NULL,
    cod_end integer,
    UNIQUE (cpf, email),
    FOREIGN KEY (cod_end) REFERENCES Endereco (cod) 
);

CREATE TABLE Pet (
    cod integer PRIMARY KEY,
    nome varchar(100),
    raca varchar(50),
    peso decimal(5,2),
    data_nasc date,
    cod_resp integer,
    FOREIGN KEY (cod_resp) REFERENCES Responsavel (cod) 
);

CREATE TABLE Veterinario (
    cod integer PRIMARY KEY,
    nome varchar(100),
    crmv numeric(10),
    especialidade varchar(50),
    fone varchar(50),
    email varchar(100),
    cod_end integer,
	FOREIGN KEY (cod_end) REFERENCES Endereco (cod) 
);

CREATE TABLE Consulta (
    cod integer PRIMARY KEY,
    dt date,
    horario time,
    cod_vet integer,
    cod_pet integer,
    FOREIGN KEY (cod_vet) REFERENCES Veterinario (cod), 
    FOREIGN KEY (cod_pet) REFERENCES Pet (cod) 
	ON UPDATE CASCADE
    ON DELETE CASCADE
);

-- inserindo enderecos
INSERT INTO endereco(cod,logradouro,numero,complemento,cep,cidade,uf) 
	VALUES 	(1, 'Rua Tenente-Coronel Cardoso', '501', 'ap 1001','28035042','Campos dos Goytacazes','RJ'),
			(2, 'Rua Serra de Bragança', '980', null,'03318000','São Paulo','SP'),
			(3, 'Rua Barão de Vitória', '50', 'loja A','09961660','Diadema','SP'),
			(4, 'Rua Pereira Estéfano', '700', 'ap 202 a','04144070','São Paulo','SP'),
			(5, 'Avenida Afonso Pena', '60', null,'30130005','São Paulo','SP'),
			(6, 'Rua das Fiandeiras', '123', 'Sala 501','04545005','São Paulo','SP'),
			(7, 'Rua Cristiano Olsen', '2549', 'ap 506','16015244','Araçatuba','SP'),
			(8, 'Avenida Desembargador Moreira', '908', 'Ap 405','60170001','Fortaleza','CE'),
			(9, 'Avenida Almirante Maximiano Fonseca', '362', null,'88113350','Rio Grande','RS'),
			(10, 'Rua Arlindo Nogueira', '219', 'ap 104','64000290','Teresina','PI');

-- inserindo responsaveis
INSERT INTO responsavel(cod,nome,cpf,email,fone,cod_end) 
	VALUES 	(1, 'Márcia Luna Duarte', '1111111111', 'marcia.luna.duarte@deere.com','(63) 2980-8765',1),
			(2, 'Benício Meyer Azevedo','23101771056', 'beniciomeyer@gmail.com.br','(63) 99931-8289',2),
			(3, 'Ana Beatriz Albergaria Bochimpani Trindade','61426227400','anabeatriz@ohms.com.br', '(87) 2743-5198',3),
			(4, 'Thiago Edson das Neves','31716341124','thiago_edson_dasneves@paulistadovale.org.br','(85) 3635-5560',4),
			(5, 'Luna Cecília Alves','79107398','luna_alves@orthoi.com.br','(67) 2738-7166',5);

-- inserindo veterinarios
INSERT INTO veterinario(cod,nome,crmv,especialidade,email,fone,cod_end) 
	VALUES 	(1, 'Renan Bruno Diego Oliveira','35062','clinico geral','renanbrunooliveira@edu.uniso.br','(67) 99203-9967',6),
			(2, 'Clara Bárbara da Cruz','64121','dermatologista','clarabarbaradacruz@band.com.br','(63) 3973-7873',7),
			(3, 'Heloise Cristiane Emilly Moreira','80079','clinico geral','heloisemoreira@igoralcantara.com.br','(69) 2799-7715',8),
			(4, 'Laís Elaine Catarina Costa','62025','animais selvagens','lais-costa84@campanati.com.br','(79) 98607-4656',9),
			(5, 'Juliana Andrea Cardoso','00491','dermatologista','juliana_cardoso@br.ibn.com','(87) 98439-9604',10);

-- inserindo animais
INSERT INTO pet(cod,cod_resp,nome,peso,raca,data_nasc) 
	VALUES 	(1, 1, 'Mike', 12, 'pincher', '2010-12-20'),
			(2, 1, 'Nike', 20, 'pincher', '2010-12-20'),
			(3, 2, 'Bombom', 10, 'shitzu', '2022-07-15'),
 			(4, 3, 'Niro', 70, 'pastor alemao', '2018-10-12'),
			(5, 4, 'Milorde', 5, 'doberman', '2019-11-16'),
 			(6, 4, 'Laide', 4, 'coker spaniel','2018-02-27'),
 			(7, 4, 'Lorde', 3, 'dogue alemão', '2019-05-15'),
			(8, 5, 'Joe', 50, 'indefinido', '2020-01-01'),
			(9, 5, 'Felicia', 5, 'indefinido', '2017-06-07');

-- inserindo consultas
INSERT INTO consulta(cod,cod_pet, cod_vet, horario, dt) 
	VALUES 	(1,2,1,'14:30','2023-10-05'),
			(2,4,1,'15:00','2023-10-05'),
			(3,5,5,'16:30','2023-10-15'),
			(4,3,4,'14:30','2023-10-12'),
			(5,2,3,'18:00','2023-10-17'),
			(6,5,3,'14:10','2023-10-20'),
			(7,5,3,'10:30','2023-10-28');
			
			
-- EXERCÍCIOS:

-- 1. Calcular Idade do Pet: Escreva uma função que calcule a idade atual de um pet com base em sua data de nascimento.

-- 2. Contar Pets por Raça: Crie uma função que retorne a quantidade de pets de uma determinada raça.

-- 3. Listar Pets por Responsável: Desenvolva uma função que liste todos os pets associados a um responsável específico.

-- 4. Validar CPF: Implemente uma função que valide o CPF dos responsáveis.

-- 5. Formatar Telefone: Escreva uma função para formatar o número de telefone dos responsáveis e veterinários.

-- 6. Encontrar Endereço do Responsável: Crie uma função que retorne o endereço completo de um responsável.
CREATE FUNCTION endereco_responsavel( responsavel_id integer)
RETURNS varchar(255)
AS $$
    SELECT 
        CONCAT(e.logradouro, ', ', e.numero,
               COALESCE(', ' || e.complemento, ''), ', ',
               e.cep, ', ', e.cidade, ' - ', e.uf) AS endereco_completo
    FROM Responsavel r
    INNER JOIN Endereco e ON r.cod_end = e.cod
    WHERE r.cod = responsavel_id;
$$ LANGUAGE SQL;

DROP FUNCTION endereco_responsavel();
SELECT * FROM endereco_responsavel(1);

-- 7. Obter Média de Peso por Raça: Implemente uma função que calcule a média de peso dos pets por raça.
CREATE FUNCTION media_peso_raca()
RETURNS TABLE (
	raca_pet varchar(50),
    media_peso decimal(5,2)
)
AS $$
	SELECT raca, AVG(peso) AS media_peso
    FROM Pet
    GROUP BY raca;
$$ LANGUAGE SQL;

DROP FUNCTION media_peso_raca();
SELECT * FROM media_peso_raca();

-- 8. Listar Veterinários por Especialidade: Desenvolva uma função que liste veterinários por uma especialidade específica.
CREATE FUNCTION listar_veterinarios_especialidade( especialidade_param varchar(50))
RETURNS TABLE (
    vet_cod integer,
    vet_nome varchar(100),
    vet_crmv numeric(10),
    vet_email varchar(100),
    vet_fone varchar(50),
	vet_especialidade varchar(50)
)
AS $$
    SELECT
        cod AS vet_cod,
        nome AS vet_nome,
        crmv AS vet_crmv,
        email AS vet_email,
        fone AS vet_fone,
		especialidade AS vet_especialidade
    FROM
        Veterinario
    WHERE
        especialidade = especialidade_param;
$$ LANGUAGE SQL;

DROP FUNCTION listar_veterinarios_especialidade();
SELECT * FROM listar_veterinarios_especialidade('clinico geral');

-- 9. Contar Consultas por Veterinário: Escreva uma função que conte o número de consultas realizadas por um veterinário específico.
CREATE FUNCTION contar_consultas_veterinario(vet_id integer)
RETURNS INTEGER
AS $$
    SELECT COUNT(*)
    FROM Consulta
    WHERE cod_vet = vet_id;
$$ LANGUAGE SQL;

DROP FUNCTION contar_consultas_veterinario();
SELECT contar_consultas_veterinario(5);

-- 10. Verificar Disponibilidade de Veterinário: Crie uma função que verifique a disponibilidade de um veterinário em uma data e horário específicos.
CREATE FUNCTION disponibilidade_veterinario(vet_id integer, data_consulta date, horario_consulta time)
RETURNS BOOLEAN
AS $$
    SELECT NOT EXISTS (
        SELECT 1
        FROM Consulta
        WHERE cod_vet = vet_id
          AND dt = data_consulta
          AND horario = horario_consulta
    );
$$ LANGUAGE SQL;

DROP FUNCTION disponibilidade_veterinario();
SELECT disponibilidade_veterinario(1, '2023-10-05', '15:00');

-- 11. Obter Histórico de Consultas do Pet: Implemente uma função que retorne todas as consultas de um pet específico.
CREATE FUNCTION consultas_pet( pet_id INTEGER)
RETURNS TABLE (
    consulta_cod integer,
    consulta_dt date,
    consulta_horario time,
    veterinario_nome varchar(100),
    veterinario_especialidade varchar(50)
)
AS $$
    SELECT
        c.cod AS consulta_cod,
        c.dt AS consulta_dt,
        c.horario AS consulta_horario,
        v.nome AS veterinario_nome,
        v.especialidade AS veterinario_especialidade
    FROM
        Consulta c
    INNER JOIN Veterinario v ON c.cod_vet = v.cod
    WHERE
        c.cod_pet = pet_id;
$$ LANGUAGE SQL;

DROP FUNCTION consultas_pet();
SELECT * FROM consultas_pet(2);

-- 12. Calcular Total de Consultas em um Período: Desenvolva uma função que calcule o total de consultas realizadas em um intervalo de datas.
CREATE FUNCTION total_consultas_intervalo( data_inicio date, data_fim date) RETURNS INTEGER
AS $$
    SELECT COUNT(*) AS total_consultas
    FROM Consulta
    WHERE dt BETWEEN data_inicio AND data_fim;
$$ LANGUAGE SQL;

DROP FUNCTION total_consultas_intervalo();
SELECT total_consultas_intervalo('2023-10-01', '2023-10-31');

-- 13. Verificar Email Único: Escreva uma função que verifique se um email já está cadastrado no sistema.
CREATE FUNCTION verificar_email_cadastrado(email_param varchar(100)) RETURNS INTEGER
AS $$
    SELECT 1
    FROM Responsavel
    WHERE email = email_param
    UNION
    SELECT 1
    FROM Veterinario
    WHERE email = email_param
$$ LANGUAGE SQL;

DROP FUNCTION verificar_email_cadastrado();
SELECT verificar_email_cadastrado('marcia.luna.duarte@deere.com');

-- 14. Listar Pets Sem Consulta: Crie uma função que liste todos os pets que nunca tiveram uma consulta.
CREATE FUNCTION pets_sem_consulta() RETURNS 
TABLE (
    cod_pet integer,
    nome_pet varchar(100),
    cod_resp integer
)
AS $$
    SELECT p.cod AS cod_pet, p.nome AS nome_pet, p.cod_resp FROM Pet p
    WHERE
        p.cod NOT IN (
            SELECT DISTINCT
                c.cod_pet
            FROM
                Consulta c
        );
$$ LANGUAGE SQL;

DROP FUNCTION pets_sem_consulta();
SELECT pets_sem_consulta();
-- 15. Atualizar Peso do Pet: Implemente uma função para atualizar o peso de um pet.
CREATE FUNCTION atualizar_peso_pet(peso_novo INTEGER, cod_pet INTEGER) RETURNS record AS $$
    UPDATE pet
	SET peso = peso_novo
	WHERE
    pet.cod = cod_pet;
	SELECT * FROM pet;
$$ LANGUAGE SQL;

DROP FUNCTION atualizar_peso_pet();
SELECT atualizar_peso_pet(20,1);
-- 16. Encontrar Veterinário com Mais Consultas: Desenvolva uma função que encontre o veterinário com o maior número de consultas.
CREATE FUNCTION veterinario_mais_consultas() RETURNS record AS $$
    SELECT  count(Consulta.cod_vet) AS quantidade_consultas_veterinario FROM Consulta
	GROUP BY Consulta.cod_vet
	ORDER BY quantidade_consultas_veterinario DESC;
$$ LANGUAGE SQL;

DROP FUNCTION veterinario_mais_consultas();
SELECT veterinario_mais_consultas();
-- 17. Excluir Pets Sem Responsável: Escreva uma função que exclua todos os pets que não têm um responsável associado.

-- 18. Gerar Relatório de Consultas por Cidade: Crie uma função que gere um relatório de consultas realizadas em uma determinada cidade.
CREATE FUNCTION consultas_por_cidade() RETURNS record AS $$
    SELECT Consulta.cod, Consulta.cod_pet, Consulta.cod_vet, Consulta.horario, Consulta.dt, Endereco.cidade FROM Consulta
	INNER JOIN Veterinario ON Veterinario.cod = Consulta.cod_vet
	INNER JOIN Endereco ON Endereco.cod = Veterinario.cod_end
	WHERE Endereco.cidade = 'Teresina';
$$ LANGUAGE SQL;

DROP FUNCTION consultas_por_cidade();
SELECT consultas_por_cidade();
-- 19. Calcular Taxa de Crescimento do Pet: Implemente uma função que calcule a taxa de crescimento do peso do pet entre duas consultas.

-- 20. Listar Endereços de Veterinários por Cidade: Desenvolva uma função que liste os endereços de todos os veterinários
-- em uma cidade específica.
CREATE FUNCTION listar_enderecos() RETURNS record AS $$
    SELECT Endereco.cod, Endereco.logradouro, Endereco.numero, Endereco.complemento, Endereco.cep, Endereco.cidade, Endereco.uf, 
	Veterinario.nome FROM Endereco
	INNER JOIN Veterinario ON Veterinario.cod_end = Endereco.cod
	WHERE Endereco.cidade = 'Teresina';
$$ LANGUAGE SQL;

DROP FUNCTION listar_enderecos();
SELECT listar_enderecos();

