--Questão A
CREATE USER usuario_admin WITH PASSWORD '123456';
CREATE USER usuario_leitura WITH PASSWORD '654321';
CREATE USER usuario_escrita WITH PASSWORD '456123';

--Questão B
CREATE TABLE dados_importantes (
    id SERIAL PRIMARY KEY,
    informacao TEXT
);

--Questão C
INSERT INTO dados_importantes (informacao) 
VALUES 
('Exemplo de informação 1'),
('Exemplo de informação 2'),
('Exemplo de informação 3'),
('Exemplo de informação 4'),
('Exemplo de informação 5'),
('Exemplo de informação 6');    

GRANT ALL ON dados_importantes TO usuario_admin;

GRANT SELECT ON dados_importantes TO usuario_leitura;

GRANT INSERT, UPDATE ON dados_importantes TO usuario_escrita;

--Questão D
-- Login como usuario_leitura e teste em seguida.
INSERT INTO dados_importantes (informacao) VALUES ('Teste1');
-- ERRO:permission denied for table dados_importantes

-- Login como usuario_escrita e teste em seguida.
SELECT * FROM dados_importantes;
-- ERRO:permission denied for table dados_importantes

--Questão E
REVOKE UPDATE ON dados_importantes FROM usuario_escrita;
GRANT SELECT ON dados_importantes TO usuario_escrita;
REVOKE ALL PRIVILEGES ON dados_importantes FROM usuario_admin;

--Questão F
-- Login como usuario_escrita e teste em seguida.
UPDATE dados_importantes SET informacao = 'Novo texto' WHERE id = 1;
-- ERRO: permission denied for table dados_importantes
SELECT * FROM dados_importantes;
-- Mensagem: SELECT successfully executed. 
-- Login como usuario_admin e teste em seguida.
SELECT * FROM dados_importantes;
-- ERRO: permission denied for table dados_importantes
