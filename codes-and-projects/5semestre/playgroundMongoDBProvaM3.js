// DESENVOLVIDO POR: Gustavo Baron Lauritzen e Matheus Baron Lauritzen

// Parte 1; 2 e 3 (Criação das coleções, seus relacionamentos e a validação de esquema):
// Criação da coleção de autores com validação de schema
db.getSiblingDB('ecommerce').createCollection("autores", {
    validator: {
        $jsonSchema: {
            bsonType: "object",
            required: ["autor_id", "nome", "data_nascimento", "nacionalidade"],
            properties: {
                autor_id: {
                    bsonType: "int",
                    description: "Identificador único do autor, campo obrigatório."
                },
                nome: {
                    bsonType: "string",
                    description: "Nome do autor, campo obrigatório."
                },
                data_nascimento: {
                    bsonType: "date",
                    description: "Data de nascimento do autor, campo obrigatório."
                },
                nacionalidade: {
                    bsonType: "string",
                    description: "Nacionalidade do autor, campo obrigatório."
                }
            }
        }
    }
});

// Criação da coleção de editoras com validação de schema
db.getSiblingDB('ecommerce').createCollection("editoras", {
    validator: {
        $jsonSchema: {
            bsonType: "object",
            required: ["editora_id", "nome", "endereco"],
            properties: {
                editora_id: {
                    bsonType: "int",
                    description: "Identificador único da editora, campo obrigatório."
                },
                nome: {
                    bsonType: "string",
                    description: "Nome da editora, campo obrigatório."
                },
                endereco: {
                    bsonType: "string",
                    description: "Endereço da editora, campo obrigatório."
                }
            }
        }
    }
});

// Criação da coleção de livros com validação de schema
db.getSiblingDB('ecommerce').createCollection("livros", {
    validator: {
        $jsonSchema: {
            bsonType: "object",
            required: ["livro_id", "titulo", "data_publicacao", "genero", "preco", "autores_id", "editora_id"],
            properties: {
                livro_id: {
                    bsonType: "int",
                    description: "Identificador único do livro, campo obrigatório."
                },
                titulo: {
                    bsonType: "string",
                    description: "Título do livro, campo obrigatório."
                },
                data_publicacao: {
                    bsonType: "date",
                    description: "Data de publicação do livro, campo obrigatório."
                },
                genero: {
                    bsonType: "string",
                    description: "Gênero do livro, campo obrigatório."
                },
                preco: {
                    bsonType: "double",
                    description: "Preço do livro, campo obrigatório."
                },
                autores_id: {
                    bsonType: "array",
                    items: {
                        bsonType: "int"
                    },
                    description: "Lista de IDs dos autores, campo obrigatório."
                },
                editora_id: {
                    bsonType: "int",
                    description: "ID da editora, campo obrigatório."
                }
            }
        }
    }
});

// Inserção de autores
db.getSiblingDB('ecommerce').autores.insertMany([
    { autor_id: 1, nome: "Autor Um", data_nascimento: ISODate("1960-01-01T00:00:00Z"), nacionalidade: "Brasileira" },
    { autor_id: 2, nome: "Autor Dois", data_nascimento: ISODate("1970-02-02T00:00:00Z"), nacionalidade: "Portuguesa" },
    { autor_id: 3, nome: "Autor Três", data_nascimento: ISODate("1980-03-03T00:00:00Z"), nacionalidade: "Angolana" }
]);

// Inserção de editoras
db.getSiblingDB('ecommerce').editoras.insertMany([
    { editora_id: 1, nome: "Editora A", endereco: "Rua A, 100" },
    { editora_id: 2, nome: "Editora B", endereco: "Rua B, 200" },
    { editora_id: 3, nome: "Editora C", endereco: "Rua C, 300" }
]);

// Inserção de livros com relacionamentos
db.getSiblingDB('ecommerce').livros.insertMany([
    { livro_id: 1, titulo: "Livro Um", autores_id: [1], editora_id: 1, data_publicacao: ISODate("2020-01-01T00:00:00Z"), genero: "Ficção", preco: 29.90 },
    { livro_id: 2, titulo: "Livro Dois", autores_id: [2, 3], editora_id: 2, data_publicacao: ISODate("2021-02-02T00:00:00Z"), genero: "Aventura", preco: 39.90 },
    { livro_id: 3, titulo: "Livro Três", autores_id: [1, 2], editora_id: 3, data_publicacao: ISODate("2022-03-03T00:00:00Z"), genero: "Drama", preco: 49.90 },
    { livro_id: 4, titulo: "Livro Quatro", autores_id: [3], editora_id: 1, data_publicacao: ISODate("2016-04-09T00:00:00Z"), genero: "Ficção", preco: 89.90 },
    { livro_id: 5, titulo: "Livro Cinco", autores_id: [2], editora_id: 2, data_publicacao: ISODate("2019-12-01T00:00:00Z"), genero: "Aventura", preco: 79.90 },
    { livro_id: 6, titulo: "Livro Seis", autores_id: [1], editora_id: 3, data_publicacao: ISODate("2013-06-08T00:00:00Z"), genero: "Drama", preco: 69.90 },
    { livro_id: 7, titulo: "Livro Sete", autores_id: [1], editora_id: 3, data_publicacao: ISODate("2012-08-19T00:00:00Z"), genero: "Ficção", preco: 39.90 },
    { livro_id: 8, titulo: "Livro Oito", autores_id: [2], editora_id: 2, data_publicacao: ISODate("2010-10-21T00:00:00Z"), genero: "Aventura", preco: 49.90 },
    { livro_id: 9, titulo: "Livro Nove", autores_id: [3], editora_id: 1, data_publicacao: ISODate("2023-03-18T00:00:00Z"), genero: "Drama", preco: 59.90 }
]);

// Atualização de relacionamentos dos autores com IDs dos livros
db.getSiblingDB('ecommerce').autores.updateOne(
    { autor_id: 1 },
    { $push: { livros: { $each: [1, 3, 6, 7] } } }
);

db.getSiblingDB('ecommerce').autores.updateOne(
    { autor_id: 2 },
    { $push: { livros: { $each: [2, 3, 5, 8] } } }
);

db.getSiblingDB('ecommerce').autores.updateOne(
    { autor_id: 3 },
    { $push: { livros: { $each: [2, 4, 9] } } }
);

// Atualização de relacionamentos das editoras com IDs dos livros
db.getSiblingDB('ecommerce').editoras.updateOne(
    { editora_id: 1 },
    { $push: { livros: { $each: [1, 4, 9] } } }
);

db.getSiblingDB('ecommerce').editoras.updateOne(
    { editora_id: 2 },
    { $push: { livros: { $each: [2, 5, 8] } } }
);

db.getSiblingDB('ecommerce').editoras.updateOne(
    { editora_id: 3 },
    { $push: { livros: { $each: [3, 6, 7] } } }
);

// Parte 4 (Buscas com find ou aggregate):
// a. Obter todos os livros de um determinado autor.
db.getSiblingDB('ecommerce').livros.find({ autores_id: 1 }).pretty();

// b. Obter a lista de livros e suas respectivas editoras.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Fazer um lookup na coleção 'editoras' para obter os dados da editora de cada livro
    {
        $lookup: {
            from: 'editoras',            // Coleção de onde queremos fazer o lookup
            localField: 'editora_id',    // Campo local na coleção 'livros' que será usado para o lookup
            foreignField: 'editora_id',  // Campo na coleção 'editoras' que corresponde ao campo local
            as: 'editora'                // Nome do campo que conterá os resultados do lookup
        }
    },
    // Etapa 2: Projeta os campos desejados do resultado
    {
        $project: {
            _id: 0,                   // Exclui o campo _id do resultado final
            livro_id: 1,              // Inclui o campo livro_id
            titulo: 1,                // Inclui o campo titulo
            editora: { $arrayElemAt: ['$editora', 0] }  // Seleciona o primeiro elemento do array 'editora'
        }
    }
]).pretty();

// c. Obter a Lista de Livros e Seus Respectivos Autores.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Fazer um lookup na coleção 'autores' para obter os dados dos autores de cada livro
    {
        $lookup: {
            from: 'autores',            // Coleção de onde queremos fazer o lookup
            localField: 'autores_id',   // Campo local na coleção 'livros' que será usado para o lookup
            foreignField: 'autor_id',   // Campo na coleção 'autores' que corresponde ao campo local
            as: 'autores'               // Nome do campo que conterá os resultados do lookup
        }
    },
    // Etapa 2: Projeta os campos desejados do resultado
    {
        $project: {
            _id: 0,                   // Exclui o campo _id do resultado final
            livro_id: 1,              // Inclui o campo livro_id
            titulo: 1,                // Inclui o campo titulo
            autores: 1                // Inclui o campo autores
        }
    }
]).pretty();

// d. Obter a Lista de Livros com Suas Respectivas Editoras e Autores.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Fazer um lookup na coleção 'editoras' para obter os dados da editora de cada livro
    {
        $lookup: {
            from: 'editoras',            // Coleção de onde queremos fazer o lookup
            localField: 'editora_id',    // Campo local na coleção 'livros' que será usado para o lookup
            foreignField: 'editora_id',  // Campo na coleção 'editoras' que corresponde ao campo local
            as: 'editora'                // Nome do campo que conterá os resultados do lookup da editora
        }
    },
    // Etapa 2: Fazer um lookup na coleção 'autores' para obter os dados dos autores de cada livro
    {
        $lookup: {
            from: 'autores',             // Coleção de onde queremos fazer o lookup
            localField: 'autores_id',    // Campo local na coleção 'livros' que será usado para o lookup
            foreignField: 'autor_id',    // Campo na coleção 'autores' que corresponde ao campo local
            as: 'autores'                // Nome do campo que conterá os resultados do lookup dos autores
        }
    },
    // Etapa 3: Projeta os campos desejados do resultado
    {
        $project: {
            _id: 0,                   // Exclui o campo _id do resultado final
            livro_id: 1,              // Inclui o campo livro_id
            titulo: 1,                // Inclui o campo titulo
            editora: { $arrayElemAt: ['$editora', 0] },  // Seleciona o primeiro elemento do array 'editora'
            autores: 1                // Inclui o campo autores
        }
    }
]).pretty();

// e. Encontrar o livro mais caro e o mais barato de cada gênero.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Agrupar por gênero e calcular o preço máximo e mínimo
    {
        $group: {
            _id: "$genero",
            livro_mais_caro: { $max: { preco: "$preco", titulo: "$titulo" } },
            livro_mais_barato: { $min: { preco: "$preco", titulo: "$titulo" } }
        }
    },
    // Etapa 2: Projetar os resultados finais para melhor legibilidade
    {
        $project: {
            genero: "$_id",
            livro_mais_caro: {
                titulo: "$livro_mais_caro.titulo",
                preco: "$livro_mais_caro.preco"
            },
            livro_mais_barato: {
                titulo: "$livro_mais_barato.titulo",
                preco: "$livro_mais_barato.preco"
            },
            _id: 0
        }
    }
]).pretty();

// f. Contar o número de livros publicados por cada editora.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Agrupar por editora e contar o número de livros por editora
    {
        $group: {
            _id: "$editora_id",          // Agrupa por editora_id
            totalLivros: { $sum: 1 }     // Conta o número de documentos em cada grupo (livros por editora)
        }
    },
    // Etapa 2: Fazer um lookup na coleção 'editoras' para obter os dados completos da editora
    {
        $lookup: {
            from: 'editoras',            // Coleção de onde queremos fazer o lookup
            localField: '_id',           // Campo local na coleção 'livros' que será usado para o lookup
            foreignField: 'editora_id',  // Campo na coleção 'editoras' que corresponde ao campo local
            as: 'editora'                // Nome do campo que conterá os resultados do lookup da editora
        }
    },
    // Etapa 3: Projetar os campos desejados do resultado
    {
        $project: {
            _id: 0,                      // Exclui o campo _id do resultado final
            editora: { $arrayElemAt: ['$editora', 0] },  // Seleciona o primeiro elemento do array 'editora'
            totalLivros: 1               // Inclui o campo 'totalLivros'
        }
    }
]).pretty();

// g. Calcular a média de preço dos livros por gênero.
db.getSiblingDB('ecommerce').livros.aggregate([
    // Etapa 1: Agrupar por gênero e calcular a média de preço
    {
        $group: {
            _id: "$genero",               // Agrupa por gênero
            media_preco: { $avg: "$preco" } // Calcula a média de preço para cada grupo
        }
    },
    // Etapa 2: Projetar os campos desejados do resultado
    {
        $project: {
            _id: 0,                       // Exclui o campo _id do resultado final
            genero: "$_id",               // Mantém o campo _id como 'genero'
            media_preco: { $round: ["$media_preco", 2] }  // Arredonda a média de preço para 2 casas decimais
        }
    }
]).pretty();
