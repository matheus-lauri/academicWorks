/*ESCRITO POR: Gustavo Baron Lauritzen e Matheus Baron Lauritzen*/

/*CRIACAO DO SCHEMA UTILIZADO NO TRABALHO*/
CREATE SCHEMA IF NOT EXISTS trabalho1M1;
SET SEARCH_PATH = trabalho1M1;

/*CRIACAO DAS TABELAS*/
/*tabela cidade*/
CREATE TABLE cidade (
    id_cidade SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    uf VARCHAR(2) NOT NULL
);

/*tabela mae*/
CREATE TABLE mae (
    id_mae SERIAL PRIMARY KEY,
    id_cidade INTEGER REFERENCES cidade(id_cidade),
    nome VARCHAR(100) NOT NULL,
    celular VARCHAR(15) NOT NULL
);

/*tabela medico*/
CREATE TABLE medico (
    id_medico SERIAL PRIMARY KEY,
	crm INTEGER NOT NULL,
    id_cidade INTEGER REFERENCES cidade(id_cidade),
    nome VARCHAR(100) NOT NULL,
    celular VARCHAR(15) NOT NULL,
	salario DECIMAL(10,2),
	status INTEGER
);

/*tabela nascimento*/
CREATE TABLE nascimento (
    id_nascimento SERIAL PRIMARY KEY,
	id_mae INTEGER REFERENCES mae(id_mae),
	id_medico INTEGER REFERENCES medico(id_medico),
    nome VARCHAR(100) NOT NULL,
	data_nascimento DATE NOT NULL,
	peso DECIMAL(5,3),
	altura INTEGER
);

/*tabela agendamento*/
CREATE TABLE agendamento (
    id_agendamento SERIAL PRIMARY KEY,
	id_nascimento INTEGER REFERENCES nascimento(id_nascimento),
    inicio TIMESTAMP NOT NULL,
	fim TIMESTAMP NOT NULL
);

/*3/1: Crie um procedimento armazenado, utilizando a linguagem SQL, que 
receba por parâmetro o mês (inteiro) e o ano (inteiro), e retorne a quantidade de 
nascimentos no período por médico, e o nome do médico. Ordenar por quantidade
(decrescente) e por nome (alfabética).*/

CREATE OR REPLACE FUNCTION obter_quantidade_nascimentos_por_medico(
    mes_param INTEGER,
    ano_param INTEGER
)
RETURNS TABLE (
    nome_medico VARCHAR(100),
    quantidade_nascimentos INTEGER
) AS $$
    SELECT 
        m.nome AS nome_medico,
        COUNT(n.id_nascimento) AS quantidade_nascimentos
    FROM 
        medico m
    LEFT JOIN 
        nascimento n ON m.id_medico = n.id_medico
    WHERE 
        EXTRACT(MONTH FROM n.data_nascimento) = mes_param
        AND EXTRACT(YEAR FROM n.data_nascimento) = ano_param
    GROUP BY 
        m.nome
    ORDER BY 
        quantidade_nascimentos DESC,
        nome_medico;
$$ LANGUAGE sql;

--Comando para testar a função
SELECT * FROM obter_nascimentos_por_medico(3, 2024);


/*3/2: Crie um procedimento armazenado, utilizando a linguagem PL/pgSQL, 
que receba por parâmetro os dados do bebê, e insira um registro na tabela 
“nascimento”. Faça uma validação, antes de inserir, para lançar uma exceção
caso o ID da mãe não exista; e caso o CRM do médico informado não exista ou 
esteja inativo.*/

CREATE FUNCTION inserir_nascimento(
    nome_baby VARCHAR(100),
    id_mae_param INTEGER,
    id_medico_param INTEGER,
    data_nascimento_param DATE,
    peso_param DECIMAL,
    altura_param INTEGER
)
RETURNS VOID AS $$
BEGIN
    -- Verificar se o ID da mãe existe
    IF NOT EXISTS (SELECT 1 FROM mae WHERE id_mae = id_mae_param) THEN
        RAISE EXCEPTION 'ID da mãe não existe';
    END IF;

    -- Verificar se o CRM do médico existe e está ativo
    IF NOT EXISTS (SELECT 1 FROM medico WHERE id_medico = id_medico_param AND status = 1) THEN
        RAISE EXCEPTION 'CRM do médico não existe ou está inativo';
    END IF;

    -- Inserir o registro na tabela de nascimento
    INSERT INTO nascimento (id_mae, id_medico, nome, data_nascimento, peso, altura)
    VALUES (id_mae_param, id_medico_param, nome_baby, data_nascimento_param, peso_param, altura_param);
    
    -- Se a inserção for bem sucedida, o procedimento termina sem exceções sendo lançadas
END;
$$ LANGUAGE plpgsql;

---Comando para testar a função
SELECT inserir_nascimento( 'Joãozinho',  1,  3, '2024-04-03', 3.2, 50);

/*3/3: Crie um procedimento armazenado, utilizando a linguagem PL/pgSQL, 
que receba por parâmetro o CRM do médico, o mês (inteiro) e o ano (inteiro), e 
retorne o valor do salário líquido. O salário do médico é composto pelo salário fixo 
do médico mais R$ 4.000,00 por nascimento realizado no período. Caso o 
nascimento tenha sido em uma cidade (considerar a cidade da mãe) diferente da 
cidade que o médico mora, há um custo de R$ 500,00 de descolamento por 
nascimento. Faça uma validação para lançar uma exceção caso o CRM do 
médico informado não exista ou esteja inativo.*/

CREATE FUNCTION calcular_salario_liquido(
    crm_medico_param INTEGER,
    mes_param INTEGER,
    ano_param INTEGER
)
RETURNS DECIMAL AS $$
DECLARE
    salario_fixo_medico DECIMAL;
    valor_adicional_nascimentos DECIMAL;
    valor_deslocamento DECIMAL := 0; -- Inicializa com 0 para caso não haja deslocamento
    salario_liquido DECIMAL;
BEGIN

    -- Verificar se o CRM do médico existe e está ativo
    IF NOT EXISTS (SELECT 1 FROM medico WHERE crm = crm_medico_param AND status = 1) THEN
        RAISE EXCEPTION 'CRM do médico não existe ou está inativo';
    END IF;

   -- Calcular o valor adicional por nascimento realizado no período
    valor_adicional_nascimentos := (
    SELECT COUNT(*) * 4000
    FROM nascimento
    WHERE EXTRACT(MONTH FROM data_nascimento) = mes_param
    AND EXTRACT(YEAR FROM data_nascimento) = ano_param
    AND id_medico = crm_medico_param
);

    -- Calcular o valor de deslocamento por nascimento em cidade diferente
    valor_deslocamento := (
    SELECT COUNT(*) * 500
    FROM nascimento n
    JOIN mae m ON n.id_mae = m.id_mae
    JOIN medico med ON n.id_medico = med.id_medico
    WHERE EXTRACT(MONTH FROM n.data_nascimento) = mes_param
    AND EXTRACT(YEAR FROM n.data_nascimento) = ano_param
    AND n.id_medico = crm_medico_param
    AND NOT EXISTS (
        SELECT 1
        FROM cidade c_medico
        JOIN cidade c_mae ON m.id_cidade = c_mae.id_cidade
        WHERE c_medico.id_cidade = c_mae.id_cidade
    )
);

    -- Calcular o salário líquido
    salario_liquido := salario_fixo_medico + valor_adicional_nascimentos - valor_deslocamento;

    RETURN salario_liquido;
END;
$$ LANGUAGE plpgsql;



-- Comando para testar a função
SELECT calcular_salario_liquido(123, 3, 2024) AS salario_liquido;



/*4/1: Crie uma função de gatilho que, ao inserir um registro na tabela 
“nascimento”, valide se o médico está ativo. Caso estiver inativo lançar uma 
mensagem de exceção: “médico inativo”.*/

/*4/2: Crie uma função de gatilho para não permitir valor nulo nas colunas nome, 
data_nascimento, peso e altura da tabela “nascimento”, ao atualizar um registro. 
Deve-se lançar uma exceção customizada para cada coluna.*/

/*4/3: Crie uma função de gatilho para não permitir agendamentos fora do 
expediente do hospital. Lance uma mensagem de exceção. Leve em 
consideração as seguintes regras de negócio:
a. Expediente: 08:00 até 12:00; 13:30 até 17:30;
b. Não há expediente no sábado e no domingo;
c. Não é permitido que um agendamento ultrapasse o horário do expediente 
(exemplo: o agendamento que inicia às 11:50 e finaliza às 12:10 não é válido).*/