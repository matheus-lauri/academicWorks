--ESCRITO POR: GUSTAVO BARON LAURITZEN E MATHEUS BARON LAURITZEN

-- PARA ESTA ATIVIDADE, EFETUE AS SEGUINTES ETAPAS:
--	1. EFETUE A CRIAÇÃO DAS TABELAS, LINHAS 5 A 62
-- 	2. EFETUE A INSERÇÃO DOS REGISTROS, LINAS 66 A 114
-- 	3. EFETUE A CRIAÇÃO DE FUNÇÕES PARA CADA UM DOS EXERCICIOS A PARTIR DA LINHA 120

/* clinica veterinaria lógico */
CREATE SCHEMA IF NOT EXISTS clinicaveterinaria2;
SET SEARCH_PATH = clinicaveterinaria2;

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

-- 1 Crie uma função que insira um novo registro na tabela Endereco e retorne o código do endereço inserido.
CREATE OR REPLACE FUNCTION inserir_endereco(
    logradouro varchar(100),
    numero integer,
    complemento varchar(50),
    cep varchar(12),
    cidade varchar(50),
    uf varchar(2)
)
RETURNS integer AS $$
DECLARE
    novo_cod integer;
BEGIN
    SELECT COALESCE(MAX(cod), 0) + 1 INTO novo_cod FROM Endereco;
    
    INSERT INTO Endereco (cod, logradouro, numero, complemento, cep, cidade, uf)
    VALUES (novo_cod, logradouro, numero, complemento, cep, cidade, uf);
    
    RETURN novo_cod;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION inserir_endereco(varchar, integer, varchar, varchar, varchar, varchar);
--Exemplo de uso da funcao
SELECT inserir_endereco('Rua Exemplo', 123, 'Apto 101', '12345-678', 'Cidade Exemplo', 'UF');

-- 2 Crie um procedimento que atualize o email de um responsável com base no seu código.
CREATE FUNCTION atualizar_email_responsavel(
    codigo_responsavel integer,
    novo_email varchar(100)
)
RETURNS void AS
$$
BEGIN
    UPDATE Responsavel
    SET email = novo_email
    WHERE cod = codigo_responsavel;
END;
$$
LANGUAGE plpgsql;

--DROP FUNCTION atualizar_email_responsavel();
SELECT atualizar_email_responsavel(1, 'novo_email@example.com');

-- 3 Escreva uma função que retorne todos os pets de uma determinada raça.
CREATE FUNCTION listar_pets_por_raca(
    raca_busca varchar
) 
RETURNS TABLE (
    cod_pet integer,
    nome varchar,
    peso decimal,
    raca varchar,
    data_nasc date,
    cod_resp integer
) AS $$
BEGIN
    RETURN QUERY 
    SELECT 
        cod,
        Pet.nome,
        Pet.peso,
        Pet.raca,
        Pet.data_nasc,
        Pet.cod_resp
    FROM 
        Pet
    WHERE 
        Pet.raca = raca_busca;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION listar_pets_por_raca();
SELECT * FROM listar_pets_por_raca('pincher');

-- 4 Faça uma função para excluir um responsável. Excluir seus pets e endereços.
CREATE FUNCTION excluir_responsavel(_cod_resp integer)
RETURNS void AS
$$
DECLARE
    _cod_end integer;
BEGIN
    -- Obter o código do endereço do responsável
    SELECT cod_end INTO _cod_end FROM responsavel WHERE cod = _cod_resp;
    
    -- Excluir os pets associados ao responsável
    DELETE FROM pet WHERE cod_resp = _cod_resp;
    
    -- Excluir o responsável
    DELETE FROM responsavel WHERE cod = _cod_resp;
    
    -- Excluir o endereço associado ao responsável
    DELETE FROM endereco WHERE cod = _cod_end;
    
    -- Retornar
    RETURN;
END;
$$
LANGUAGE plpgsql;

--DROP FUNCTION excluir_responsavel();
SELECT excluir_responsavel(1);

-- 5 Faça uma função que liste todas as consultas agendadas para uma data específica.
CREATE FUNCTION listar_consultas_por_data(data_consulta date) RETURNS TABLE (
    consulta_id integer,
    pet_nome varchar(100),
    veterinario_nome varchar(100),
    horario_consulta time
) AS $$
BEGIN
    RETURN QUERY
    SELECT c.cod, p.nome AS pet_nome, v.nome AS veterinario_nome, c.horario
    FROM Consulta c
    INNER JOIN Pet p ON c.cod_pet = p.cod
    INNER JOIN Veterinario v ON c.cod_vet = v.cod
    WHERE c.dt = data_consulta;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION listar_consultas_por_data();
SELECT * FROM listar_consultas_por_data('2023-10-05');

-- 6 Crie uma função que receba os dados do veterinario por parâmetro, armazene na tabela “veterinario” e retorne todos os dados da tabela.
CREATE OR REPLACE FUNCTION inserir_veterinario(
    nome_vet varchar(100),
    crmv_vet numeric(10),
    especialidade_vet varchar(50),
    fone_vet varchar(50),
    email_vet varchar(100),
    cod_end_vet integer
) 
RETURNS SETOF Veterinario AS $$
DECLARE
    novo_vet Veterinario%ROWTYPE;
    novo_cod integer;
BEGIN
    SELECT COALESCE(MAX(cod), 0) + 1 INTO novo_cod FROM Veterinario;

    INSERT INTO Veterinario (cod, nome, crmv, especialidade, fone, email, cod_end)
    VALUES (novo_cod, nome_vet, crmv_vet, especialidade_vet, fone_vet, email_vet, cod_end_vet)
    RETURNING * INTO novo_vet;

    RETURN QUERY SELECT * FROM Veterinario;

    RETURN;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION inserir_veterinario(varchar, numeric, varchar, varchar, varchar, integer);
--Exemplo de uso da funcao
SELECT * FROM inserir_veterinario(
    'João da Silva Soares',
    1234567890, 
    'Especialidade do Veterinário',
    '(67)99999-9999',
    'joaosilvasoares@gmail.com',
    1 
);

-- 7 Crie uma função para adicionar um novo pet, associando-o a um responsável existente.
CREATE FUNCTION adicionar_pet(
    nome_pet varchar(100),
    peso_pet decimal(5,2),
    raca_pet varchar(50),
    data_nasc_pet date,
    cpf_resp varchar(12)
) RETURNS VOID AS $$
DECLARE
    resp_cod integer;
	novo_pet_cod integer;
BEGIN

	SELECT COALESCE(MAX(Pet.cod), 0) + 1 INTO novo_pet_cod FROM Pet;
    -- Obtendo o código do responsável pelo CPF fornecido
    SELECT r.cod INTO resp_cod FROM responsavel r WHERE r.cpf = cpf_resp;

    -- Verificando se o responsável existe
    IF resp_cod IS NULL THEN
        RAISE EXCEPTION 'Responsável não encontrado com o CPF fornecido';
    END IF;

    -- Inserindo o novo pet associado ao responsável
    INSERT INTO pet(cod, nome, raca, peso, data_nasc, cod_resp)
    VALUES (novo_pet_cod, nome_pet, raca_pet, peso_pet, data_nasc_pet, resp_cod);

    -- Verificando se o pet foi inserido corretamente
    IF novo_pet_cod IS NULL THEN
        RAISE EXCEPTION 'Não foi possível adicionar o pet';
    ELSE
        RAISE NOTICE 'Novo pet adicionado com sucesso. Código do pet: %', novo_pet_cod;
    END IF;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION adicionar_pet();
SELECT adicionar_pet('Mel', 7, 'Border Coller', '2023-03-10', '31716341124');
SELECT * FROM Pet;

-- 8 Escreva uma função que conte quantos pets um determinado responsável possui.
CREATE FUNCTION contar_pets_responsavel(cpf_responsavel varchar) 
RETURNS INTEGER AS $$
DECLARE
    num_pets INTEGER;
BEGIN
    SELECT COUNT(*) INTO num_pets
    FROM pet p
    INNER JOIN responsavel r ON p.cod_resp = r.cod
    WHERE r.cpf = cpf_responsavel;

    RETURN num_pets;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION contar_pets_responsavel();
SELECT contar_pets_responsavel('31716341124');

-- 9 Desenvolva uma função que retorne todos os veterinários com uma determinada especialidade.
CREATE OR REPLACE FUNCTION get_veterinarios_por_especialidade(p_especialidade varchar)
RETURNS TABLE (
    cod integer,
    nome varchar,
    crmv numeric,
    especialidade varchar,
    fone varchar,
    email varchar,
    cod_end integer
) AS $$
BEGIN
    RETURN QUERY
    SELECT * FROM Veterinario WHERE Veterinario.especialidade = p_especialidade;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION get_veterinarios_por_especialidade(varchar);
--Exemplo de uso da funcao
SELECT * FROM get_veterinarios_por_especialidade('dermatologista');

-- 10 Crie um procedimento que atualize o endereço de um veterinário.
CREATE OR REPLACE FUNCTION atualizar_endereco_veterinario(
    IN p_cod_vet INTEGER,
    IN p_cod_end INTEGER
)
RETURNS VOID AS $$
BEGIN
    UPDATE Veterinario
    SET cod_end = p_cod_end
    WHERE cod = p_cod_vet;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION atualizar_endereco_veterinario(integer, integer);
--Exemplo de uso da funcao
SELECT atualizar_endereco_veterinario(1, 2);

-- 11 Faça uma função que calcule a idade atual de um pet.
CREATE OR REPLACE FUNCTION calcular_idade_pet(cod_pet integer)
RETURNS integer AS $$
DECLARE
    idade integer;
BEGIN
    SELECT EXTRACT(YEAR FROM age(data_nasc)) INTO idade
    FROM Pet
    WHERE cod = cod_pet;
    
    RETURN idade;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION calcular_idade_pet(integer);
--Exemplo de uso da funcao
SELECT calcular_idade_pet(1);

-- 12 Crie uma função que retorne todos os endereços em uma cidade específica.
CREATE OR REPLACE FUNCTION get_enderecos_por_cidade(cidade_param varchar)
RETURNS TABLE (
    cod integer,
    logradouro varchar(100),
    numero integer,
    complemento varchar(50),
    cep varchar(12),
    cidade varchar(50),
    uf varchar(2)
) AS
$$
BEGIN
    RETURN QUERY
    SELECT * FROM Endereco
    WHERE Endereco.cidade = cidade_param;
END;
$$
LANGUAGE 'plpgsql';

--DROP FUNCTION get_enderecos_por_cidade(varchar);
--Exemplo de uso da funcao
SELECT * FROM get_enderecos_por_cidade('São Paulo');

-- 13 Desenvolva um procedimento que associe um pet existente a um novo responsável.
CREATE OR REPLACE FUNCTION associar_pet_a_responsavel(pet_id integer, responsavel_id integer) RETURNS void AS $$
BEGIN
    UPDATE Pet SET cod_resp = responsavel_id WHERE cod = pet_id;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION associar_pet_a_responsavel(integer, integer);
--Exemplo de uso da funcao
SELECT associar_pet_a_responsavel(1, 2);

-- 14 Elabore uma função que retorne todas as consultas agendadas de um determinado veterinário.
CREATE OR REPLACE FUNCTION consultas_agendadas_do_veterinario(codigo_veterinario_param integer)
RETURNS TABLE (
    codigo_consulta integer,
    data date,
    horario time,
    codigo_veterinario integer,
    codigo_pet integer
)
AS $$
DECLARE
    codigo_veterinario_interno integer := codigo_veterinario_param;
BEGIN
    RETURN QUERY
    SELECT
        Consulta.cod AS codigo_consulta,
        Consulta.dt AS data,
        Consulta.horario,
        Consulta.cod_vet AS codigo_veterinario,
        Consulta.cod_pet AS codigo_pet
    FROM
        Consulta
    WHERE
        Consulta.cod_vet = codigo_veterinario_interno;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION consultas_agendadas_do_veterinario(integer);
--Exemplo de uso da funcao
SELECT * FROM consultas_agendadas_do_veterinario(3);

-- 15 Função para Buscar Responsável pelo Nome do Pet: Desenvolva uma função que retorne o nome do responsável pelo nome do pet.
CREATE OR REPLACE FUNCTION buscar_responsavel_por_pet(nome_pet varchar)
RETURNS varchar AS $$
DECLARE
    responsavel_nome varchar;
BEGIN
    SELECT Responsavel.nome INTO responsavel_nome
    FROM Pet
    JOIN Responsavel ON Pet.cod_resp = Responsavel.cod
    WHERE Pet.nome = nome_pet;

    RETURN responsavel_nome;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION buscar_responsavel_por_pet(varchar);
--Exemplo de uso da funcao
SELECT buscar_responsavel_por_pet('Mike');

-- 16 Desenvolva uma função que recebe o CPF de um responsável e retorna seu nome se ele existir na base de dados; caso contrário, retorna uma mensagem "Responsável não encontrado".
CREATE OR REPLACE FUNCTION busca_responsavel_por_cpf(cpf_responsavel varchar(12))
RETURNS varchar(100) AS $$
DECLARE
    responsavel_nome varchar(100);
BEGIN
    SELECT nome INTO responsavel_nome
    FROM Responsavel
    WHERE cpf = cpf_responsavel;

    IF responsavel_nome IS NULL THEN
        RETURN 'Responsável não encontrado';
    ELSE
        RETURN responsavel_nome;
    END IF;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION busca_responsavel_por_cpf(varchar);
--Exemplo de uso da funcao
SELECT busca_responsavel_por_cpf('1111111111');

-- 17 Crie uma função que receba um código de veterinário e retorne o total de consultas realizadas por ele, utilizando um loop WHILE.
CREATE OR REPLACE FUNCTION total_consultas_por_veterinario(p_cod_vet integer)
RETURNS integer AS $$
DECLARE
    total_consultas integer := 0;
    consulta_cod integer;
BEGIN
    SELECT cod INTO consulta_cod FROM Consulta WHERE cod_vet = p_cod_vet LIMIT 1;

    WHILE consulta_cod IS NOT NULL LOOP
        total_consultas := total_consultas + 1;
        SELECT cod INTO consulta_cod FROM Consulta WHERE cod_vet = p_cod_vet AND cod > consulta_cod LIMIT 1;
    END LOOP;

    RETURN total_consultas;
END;
$$ LANGUAGE plpgsql;

--DROP FUNCTION total_consultas_por_veterinario(integer);
--Exemplo de uso da funcao
SELECT total_consultas_por_veterinario(1);