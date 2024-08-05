--Escrito por Matheus Baron Lauritzen e Gustavo Baron Lauritzen
--Questao 1:
-- criando a database
CREATE DATABASE exercicio_aula_1;

--criando tabela de cliente
CREATE TABLE Cliente(
    ID_Cliente int PRIMARY KEY,
    nome_cliente varchar(100),
	data_nascimento_cliente date,
    endereco_cliente varchar(100),
    telefone_cliente varchar(25),
    email_cliente varchar(100)
);

--criando tabela de pedido
CREATE TABLE Pedido(
    ID_Pedido int PRIMARY KEY,
    data_hora_pedido date,
    ID_cliente_pedido int,
    status_pedido varchar(11),
    total_pedido numeric,
	CONSTRAINT fk_ID_cliente_pedido
      FOREIGN KEY(ID_cliente_pedido) 
        REFERENCES cliente(id_Cliente) ON DELETE CASCADE
);

--criando tabela do item para o cardapio
CREATE TABLE Item_Cardapio(
    ID_Item int PRIMARY KEY,
    nome_item varchar(100),
    descricao_item varchar(200),
    preco_item numeric
);

--criando a tabela associativa
CREATE TABLE item_pedido(
    ID_Pedido_assoc int,
    ID_Item_assoc int,
	quantidade_item_pedido int,
	CONSTRAINT fk_ID_pedido_assoc
      FOREIGN KEY(ID_pedido_assoc) 
        REFERENCES pedido(id_pedido) ON DELETE CASCADE,
	CONSTRAINT fk_ID_item_assoc
      FOREIGN KEY(ID_item_assoc) 
        REFERENCES item_cardapio(id_item) ON DELETE CASCADE
);

--Questao 2:
--inserindo dados na tabela cliente
INSERT INTO cliente (id_cliente, nome_cliente, data_nascimento_cliente, endereco_cliente, telefone_cliente, email_cliente)
VALUES (1,'Anna Briggs','2023-11-06','Lawson Square, 13356','732-864-7316','martinpatricia@cain-smith.com'),
(2,'Jeremy Thompson','1998-05-04','USS Medina, 21470','523-272-4776','kimberlycannon@quinn.info'),
(3,'Dakota Lloyd','1976-10-27','Reed Ferry, 305','01-566-218-0500','wmoore@gutierrez-cole.com'),
(4,'Danny Potter','1958-03-18','USS Gibson, 424','01-441-053-3778','joel28@thomas-rosales.org'),
(5,'Carolyn Stevens','1948-07-07', 'Willie Walks Suite 019','001-183-448-8354','williamgreen@gmail.com'),
(6,'Kara Perkins','1992-08-07','Esparza Pines, 86115','001-372.224.2758','melodyholt@yahoo.com'),
(7,'Luis Evans','1968-02-23','John Island Suite, 074','+1-894-341-5025','qtucker@gmail.com'),
(8,'Amber West','1999-07-10', 'Peters Mountain Suite, 063','(164)470-2706','rhorton@wright-reed.biz'),
(9,'Stephanie Fox','1998-05-04','Myers Field, 385','001-391-492-3087','halljessica@yahoo.com'),
(10,'Tamara Schwartz','2010-01-20','USNS Long, 58200','+1-942-840-1333','charlotte91@gmail.com');

--inserindo dados na tabela pedido
INSERT INTO pedido (id_pedido, data_hora_pedido, id_cliente_pedido, status_pedido, total_pedido)
VALUES (1,'2024-02-14 03:53:23.704596',4,'Cancelado',45.76),
(2,'2024-01-31 19:50:23.704699',10,'Finalizado',57.11),
(3,'2024-01-28 11:32:23.704728',4,'Finalizado',25.19),
(4,'2024-02-20 10:08:23.704749',2,'Cancelado',88.64),
(5,'2024-02-11 10:40:23.704769',3,'Finalizado',54.01),
(6,'2024-02-10 02:06:23.704789',5,'Pendente',63.14),
(7,'2024-02-13 10:44:23.704807',10,'Finalizado',33.45),
(8,'2024-02-01 07:15:23.704826',3,'Pendente',20.43),
(9,'2024-02-01 02:02:23.704845',9,'Pendente',87.72),
(10,'2024-02-04 04:23:23.704864',2,'Cancelado',21.87);

--inserindo dados na tabela item_cardapio
INSERT INTO item_cardapio (id_item, nome_item, descricao_item, preco_item)
VALUES (1,'Pizza Margherita','Tradicional pizza com molho de tomate, queijo mozzarella e manjericão',44.21),
(2,'Hambúrguer Gourmet','Hambúrguer de carne bovina com queijo, alface, tomate e molho especial',16.95),
(3,'Salada Caesar','Salada com alface romana, croutons, queijo parmesão e molho Caesar', 47.67),
(4,'Sushi Sashimi','Variedade de sashimi de salmão, atum e peixe branco',14.70),
(5,'Spaghetti Carbonara','Espaguete com molho cremoso de ovos, queijo parmesão, bacon e pimenta preta',20.92),
(6,'Frango Assado','Frango assado com ervas e especiarias, servido com vegetais',45.45),
(7,'Tacos Mexicanos','Tacos com carne moída, alface, queijo, tomate e molho picante',19.79),
(8,'Sorvete de Baunilha','Sorvete cremoso de baunilha com opções de cobertura',35.38),
(9,'Lasanha à Bolonhesa','Camadas de massa, carne moída, molho de tomate e queijo',40.56),
(10,'Pad Thai','Macarrão tailandês frito com camarões, amendoim, broto de feijão e limão',46.65);

--inserindo dados na tabela associativa item_pedido
INSERT INTO item_pedido (ID_Pedido_assoc, ID_Item_assoc, quantidade_item_pedido)
VALUES (1,8,2),(2,1,5),(3,2,1),(4,6,4),(5,1,5),(6,1,5),(7,6,1),
(8,3,1),(9,9,2),(10,4,1),(2,2,3),(2,7,2),(5,2,3),(5,7,3),
(7,5,2),(7,10,4),(8,5,3),(8,10,5),(8,9,1),(7,4,1);

--Questao 3:
--a. Apresentar todos os clientes em ordem alfabética:
SELECT ID_Cliente, nome_cliente FROM Cliente ORDER BY nome_cliente ASC;

--b. Torne a coluna Telefone como não nula e única:
ALTER TABLE Cliente
ALTER COLUMN telefone_cliente SET NOT NULL,
ADD CONSTRAINT telefone_unico UNIQUE (telefone_cliente);

--c. Apresentar os itens do cardápio que não contém “queijo”
SELECT nome_item, descricao_item FROM Item_Cardapio 
WHERE descricao_item NOT LIKE '%queijo%';

--d. Exibir todos os pedidos, incluindo os nomes dos respectivos clientes
SELECT pedido.id_pedido, pedido.data_hora_pedido, pedido.id_cliente_pedido, pedido.status_pedido,
pedido.total_pedido, cliente.nome_cliente FROM Pedido 
INNER JOIN Cliente ON id_cliente_pedido = id_cliente;

--e. Delete o pedido número 5.
DELETE FROM pedido WHERE ID_pedido = 5 ;

--f. Calcular a idade de cada cliente, e apresentá-los de forma crescente
SELECT id_cliente, nome_cliente, data_nascimento_cliente, AGE(data_nascimento_cliente) AS idade
FROM cliente ORDER BY idade;

--g. Excluir clientes menores de 18 anos
DELETE FROM cliente
WHERE DATE_PART('year', AGE(data_nascimento_cliente)) < 18;

--h. Crie a coluna Data_Cadastro na tabela Cliente, usando como valor Default a data atual
ALTER TABLE cliente 
ADD COLUMN Data_Cadastro DATE DEFAULT current_date;

--i. Crie a coluna "Gluten_Free" e "Is_Vegano" na tabela "Item_Cardapio", defina ambas as colunas como False
ALTER TABLE Item_cardapio 
ADD COLUMN Gluten_Free BOOLEAN DEFAULT FALSE,
ADD COLUMN Is_Vegano BOOLEAN DEFAULT FALSE;

--j. Apresente os pedidos, os respectivos clientes, nome do item pedido e a quantidade total deste item e o valor total. O resultado deve ser ordenado pelo número do pedido.
SELECT pedido.id_pedido, pedido.data_hora_pedido, pedido.status_pedido, 
cliente.id_cliente, cliente.nome_cliente, item_cardapio.nome_item,
item_pedido.quantidade_item_pedido, pedido.total_pedido FROM Pedido 
INNER JOIN cliente ON pedido.id_cliente_pedido = cliente.id_cliente
INNER JOIN item_pedido ON pedido.id_pedido = item_pedido.id_pedido_assoc
INNER JOIN item_cardapio ON item_pedido.id_item_assoc = item_cardapio.id_item
ORDER BY id_pedido ASC;

--k. Altere o nome da coluna "Data_Cadastro" da tabela "Cliente" para "Dt_Cadastro".
ALTER TABLE cliente 
RENAME COLUMN data_cadastro 
TO dt_cadastro;

--m. Apresentar o número de pedidos de cada cliente, apresentando os atributos código do 
--cliente, nome do cliente, número de pedidos e o valor total dos pedidos. Apresente o 
--resultado ordenado decrescente por gastos.
SELECT cliente.id_cliente, cliente.nome_cliente, COUNT(pedido.id_pedido) AS numero_pedidos, SUM(pedido.total_pedido) AS valor_total_pedidos
FROM cliente INNER JOIN pedido ON cliente.id_cliente = pedido.id_cliente_pedido
GROUP BY cliente.id_cliente, cliente.nome_cliente
ORDER BY valor_total_pedidos;

--n. Listar todos os itens de cada Pedido, incluindo o nome do item e a quantidade
SELECT item_pedido.id_pedido_assoc, item_cardapio.nome_item, item_pedido.quantidade_item_pedido
FROM item_pedido INNER JOIN item_cardapio ON item_pedido.id_item_assoc = item_cardapio.id_item;

--o. Apresentar os clientes que fizeram mais de 1 pedido, mostrando o número total de pedidos e o valor total correspondente
SELECT cliente.id_cliente, cliente.nome_cliente, COUNT(pedido.id_pedido) AS total_pedidos, 
SUM(pedido.total_pedido) AS total_valor
FROM cliente INNER JOIN pedido ON cliente.id_cliente = pedido.id_cliente_pedido
GROUP BY cliente.id_cliente HAVING COUNT(pedido.id_pedido) > 1;

--Questao 4:
--criando a view solicitada:
CREATE VIEW VisaoDetalhesPedidos AS
SELECT
    Cliente.nome_cliente AS Nome_Cliente,
    Pedido.data_hora_pedido AS Data_Hora,
    Pedido.total_pedido AS total,
    Item_Cardapio.nome_item AS Item,
    Item_Pedido.quantidade_item_pedido AS Quantidade
FROM
    Pedido
INNER JOIN
    Cliente ON Pedido.id_cliente_pedido= Cliente.id_cliente
INNER JOIN
    Item_Pedido ON Pedido.id_pedido = Item_Pedido.id_pedido_assoc
JOIN
    Item_Cardapio ON Item_Pedido.id_item_assoc = Item_Cardapio.id_item;