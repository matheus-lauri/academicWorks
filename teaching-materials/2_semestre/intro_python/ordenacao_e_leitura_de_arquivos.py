# -*- coding: utf-8 -*-
"""Ordenacao e Leitura de Arquivos.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1FqPwGMJOCDw2ABGd_X7E_WnpmV1DXF6S

# Ordenação

---

### Uso

---

Quando o método `sort` é chamado em uma lista, a ordem dos itens é alterada. Se nenhum parâmetro for especificado, os itens serão organizados de acordo com a ordem natural do tipo de item. Por exemplo, se os itens forem todos números inteiros, números menores serão exibidos anteriormente na lista. Se os itens forem todos strings, eles serão organizados em ordem alfabética.
"""

numeros = [10.2, 1.88, 5, 5, 2] 
texto = ["za", "gs", "ad", "we", "2"] 

print(numeros) 
print(texto)

numeros.sort() 
texto.sort() 

print(numeros) 
print(texto)

"""O método `sort` só funciona com variáveis de tipos compatíveis, não funcionando com int e string na mesma lista por exemplo."""

mixed = [5, 1, "x", 3, "a"] #a lista tem que ter somente um tipo de item, ou de tipos onde o operador < seja compatível
mixed.sort()

boolean = [True, 1, False, True, 2, 8, 0.1, 0.0000001, 0.999999, 1.000000001]

boolean.sort()

print(boolean)

"""Outro detalhe é que o método `sort` não retorna um vetor novo, e sim modifica o antigo, o que pode gerar efeitos colaterais no código. 

Uma forma de contornar isso é utilizar o método `sorted` que utiliza o vetor original como parâmetro e retorna o vetor ordenado, sem alterar o original.
"""

numeros = [10, 1, 4, 5, 2]

numeros_ord = sorted(numeros)

print(numeros) 
print(numeros_ord)

"""Um exemplo do que pode gerar um efeito colateral."""

numeros = [3, 2, 5, 1]

ord = numeros
ord.sort()

print(numeros)
print(ord)

numeros = [3, 2, 5, 1]

ord = numeros
ord = sorted(ord)

print(numeros)
print(ord)

"""### Parâmetros Opcicionais

---

A função `sorted` (e a função `sort`) possuen alguns parâmetros opcionais. O primeiro parâmetro opcional é uma função `key`. O segundo parâmetro opcional é um valor booleano `reverse` que determina se os itens serão ordenados na ordem inversa. Por padrão esse valor é False, mas se você configurá-lo como True, a lista será ordenada em ordem inversa.
"""

lista = [10, 1, 4, 5, 2] 

listaOrdenada = sorted(lista) 
print(listaOrdenada)

listaOrdenadaI = sorted(lista, reverse=True) 
print(listaOrdenadaI)

"""Se você deseja classificar as coisas em alguma ordem que não seja a “natural” ou invertido, você pode fornecer um parâmetro adicional, o parâmetro `key`. 

Por exemplo, suponha que você queira classificar uma lista de números com base em seu valor absoluto, para que -4 venha depois de 3? Ou suponha que você tenha um dicionário com strings como chaves e números como valores. Em vez de classificá-los em ordem alfabética com base nas chaves, convém classificá-los em ordem com base em seus valores.

Primeiro, vamos ver um exemplo e, em seguida, veremos como isso funciona. 

Vamos definir uma função absoluta que pega um número e retorna seu valor absoluto. (Na verdade, o python fornece uma função interna `abs` que faz isso, mas vamos definir a nossa função)
"""

def absoluto(x): 
  if x >= 0: 
    return x 
  else: 
    return -x

"""Agora, podemos passar a função absoluta para a `sorted`, a fim de especificar que queremos que os itens sejam classificados na ordem de seu valor absoluto, em vez de na ordem de seu valor real."""

def absoluto(x): 
  if x >= 0: 
    return x 
  else: 
    return x * -1

lista = [1, -7, 4, -2, 3] 

lista_n = sorted(lista)
lista_l = sorted(lista, key=absoluto) 
print(lista_n)
print(lista_l)
 
#print(sorted(L1, reverse=True, key=absoluto))

"""Outro exemplo pode ser para ordernar texto e números inteiros."""

def string(x):
  return str(x)

lista = [5, 1, "x", 3, "a"] 
ordenada = sorted(lista, key=string)

print(ordenada)

"""# Arquivos

---

### Introdução

---

Até agora, os dados que usamos foram todos codificados diretamente no programa ou inseridos pelo usuário. Na vida real, os dados ficam em arquivos. Por exemplo: imagens, páginas da web, documentos de texto e músicas são outros exemplos de dados que vivem em arquivos. Aqui, serão apresentados conceitos de Python necessários para usar dados de arquivos em nossos programas.

No Python, precisamos abrir arquivos antes de poder usá-los e fechá-los quando terminarmos com eles. Como você pode esperar, uma vez que um arquivo é aberto, ele se torna um objeto Python, assim como todos os outros dados.

`open(nomeArquivo, "r")` - Abre um arquivo no endereço da sting nomeArquivo> para leitura. Retorna uma referencia para o arquivo

`open(nomeArquivo, "w")` - Abre um arquivo no endereço da sting nomeArquivo> para escrita. Retorna uma referencia para o arquivo

`arquivo.close()` - Finaliza o uso do arquivo

O parâmetro `nomeArquivo` é o nome do arquivo mais o seu caminho dentro do sistema de arquivos. Esse caminho pode ser o endereço completo no computador ou relativo à pasta do projeto. 

Por isso que caso o arquivo de texto esteja na mesma pasta do arquivo Python, precisamos somente do nome do arquivo.
"""

#arquivo = open("/content/drive/MyDrive/IntroducaoPython - Notebooks/Aula 4/Arquivos - Exercícios e Aula/olimpiadas.txt", "r") #esse arquivo precisa existir, 
#arquivo = open("olimpiadas.txt", "r")
arquivo = open("/content/drive/MyDrive/IntroducaoPython - Notebooks/Aula 4/Arquivos - Exercícios e Aula/testew.txt", "w")
#No Collaboratory ele pode ser arrastado para a guia arquivos na esquerda

#Código que trabalha com a variável arquivo 

arquivo.close()

"""### Leitura dos dados

---

Depois de ter um arquivo carregado em uma variável, o que foi retornado pela função `open`, o Python fornece três métodos para ler dados desse objeto: 

O método `read` retorna todo o conteúdo do arquivo como uma única string (ou apenas alguns caracteres se você fornecer um número como parâmetro de entrada).

O método `readlines` retorna todo o conteúdo do arquivo como uma lista de strings, onde cada elemento na lista é uma linha do arquivo. 

O método `readline` lê uma linha do arquivo e a retorna como uma string. 

As strings retornadas por `readlines` ou `readline` conterão o caractere de nova linha no final.
"""

arquivo = open("teste.txt", "r")

outrosDados = arquivo.readlines()
print(outrosDados)

outrosDados = arquivo.readlines()
print(outrosDados)

arquivo.close()

arquivo = open("teste.txt", "r")

dados = arquivo.read()
print(dados)

dados = arquivo.read()
print(dados)


arquivo.close()

arquivo = open("teste.txt", "r")

dados = arquivo.readlines()
print(dados)

for linha in dados:
  print(linha)

arquivo.close()

arquivo = open("teste.txt", "r")

dados = arquivo.readline()
print(dados)

dados = arquivo.readline()
print(dados)

dados = arquivo.read()
print(dados)



arquivo.close()

"""A função no objeto visto pelo `read()` traz somente uma string com todos os caracteres, por isso o len conta a quantidade de caracteres. Enquanto que o .`readlines()` traz um vetor onde cada posição é uma linha, portanto o len retorna o tamanho do vetor."""

arquivo = open("olimpiadas.txt", "r") 
texto = arquivo.read() 
print(len(texto))
print(texto) 
arquivo.close()

arquivo = open("olimpiadas.txt", "r") 
texto = arquivo.readlines() 
print(len(texto)) 
print(texto)
for index, linha in enumerate(texto):
  texto[index] = linha.strip()
print(texto)
arquivo.close()

print(list(enumerate(texto)))

arquivo = open("olimpiadas.txt", "r") 
texto = arquivo.readline() 
print(len(texto)) 
print(texto)

"""Agora vamos utilizar esse arquivo como entrada em um programa que fará algum processamento de dados. No programa, examinaremos cada linha do arquivo e a imprimiremos com algum texto adicional. Como `readlines()` retorna uma lista de linhas de texto, podemos usar o loop for para percorrer cada linha do arquivo.

Uma linha de um arquivo é definida como uma sequência de caracteres até e incluindo um caractere especial chamado caractere de nova linha. Se você avaliar uma sequência que contém um caractere de nova linha, verá o caractere representado como `\n`. Se você imprimir uma string que contém uma nova linha, não verá o `\n`, apenas os efeitos.
"""

texto = "\t\n\n\ntexto \n resto\n  \n  \t"
print(texto)
texto = texto.strip()
print(texto)

arquivo = open("olimpiadas.txt", "r") 

cabecalho = arquivo.readline()

atletas = arquivo.readlines()
#print(atletas)
for linha in atletas:
  #print(linha)
  linha = linha.strip()
  #print(linha)
  dado = linha.split(",")
  #print(dado)
  if dado[5] != "NA":
    print("O atleta", dado[0], "do país", dado[3], "competiu em", dado[4])
    if(dado[5] == "NA"):
      print("E não ganhou nenhuma medalha")
    else:
      print("E ganhou", dado[5])
    print()

arquivo.close()

arquivo = open("olimpiadas.txt", "r") 

cabecalho = arquivo.readline()

for linha in arquivo.readlines(): #aqui podemos utilizar somente a variável arquivo 
  #print(linha.strip())
  valores = linha.split(",") 
  #print(valores)
  if valores[5].strip() != "NA":
    print(valores[0], "é de", valores[3], "e ganhou", valores[5],"em", valores[4], "\n") 

arquivo.close()

"""O princípio de roteiro para trabalhar com arquivos pode seguir o seguinte roteiro (não está limitado a isso): 



*   Abrir o arquivo usando `open`;
*   Usar `readlines` para obter uma lista das linhas de texto no arquivo;
*   Usar um loop `for` para percorrer as strings na lista, cada uma sendo uma linha do arquivo;
*   Em cada iteração, processar essa linha de texto;
*   Quando terminar de extrair dados, fechar o arquivo usando `close`.

### Escrita de dados

---

Uma das tarefas de processamento de dados mais comumente executadas é ler dados de um arquivo, manipulá-los de alguma forma e gravar os dados resultantes em um novo arquivo de dados para ser usado para outros fins posteriormente. 

Para fazer isso, a função `open` discutida anteriormente também pode ser usada para criar um novo arquivo preparado para gravação. A única diferença entre abrir um arquivo para gravação e abrir um arquivo para leitura é o uso do caractere 'w' em vez do caractere 'r' como o segundo parâmetro. 

Quando abrimos um arquivo para gravação, um novo arquivo vazio com esse nome é criado e preparado para aceitar nossos dados. Se um arquivo existente tiver o mesmo nome, seu conteúdo será substituído. Como antes, a função retorna uma referência do arquivo para uma variável.

O método `write` permite adicionar dados à um arquivo de texto. Lembrando que os arquivos de texto contêm sequências de caracteres. Geralmente pensamos nessas sequências de caracteres como sendo as linhas do arquivo em que cada linha termina com o caractere nova linha `\n`. 

Tenha muito cuidado para perceber que o método write usa um parâmetro, uma string. Quando chamado, os caracteres da sequência serão adicionados ao final do arquivo. Isso significa que é tarefa do programador incluir os caracteres de nova linha como parte da sequência, se desejado.
"""

arquivo = open("quadrados.txt", "w")
for numero in range(2, 10): 
  quadrado = numero * numero
  arquivo.write(str(quadrado) + "\n") 
arquivo.close()

arquivo = open("quadrados.txt", "r")
dados = arquivo.readlines()
print(dados)
dados.insert(4, "legal\n")
print(dados)
arquivo.close()

arquivo = open("quadrados.txt", "w")
for linha in dados:
  arquivo.write(linha)
arquivo.close()

arquivo = open("quadrados.txt", "a") #ou 'a' caso queira continuar o arquivo anterior, e não sobreescrever
for numero in range(11, 101): 
  quadrado = numero * numero 
  arquivo.write(str(quadrado) + "\n") 
arquivo.close()

"""### Arquivos CSV

---

CSV significa *Comma Separated Values* (Valores Separados por Vírgula). 

Se organizar os dados tabulares no formato CSV, eles poderão ser facilmente importados para outros programas, como Excel, planilhas do Google ou um pacote de estatísticas (R, stata, SPSS, etc.). 

Por exemplo, podemos criar um arquivo com o conteúdo abaixo. Se você o salvar como um nome de arquivo grades.csv, poderá importá-lo para um desses programas. A primeira linha fornece os nomes das colunas e as linhas posteriores fornecem os dados para uma linha.
"""

arquivo = open("teste.csv", "w")

texto = "Name,score,grade\n"+ "Jamal,98,A+\n"+"Eloise,87,B+\n"+ "Madeline,99,A+\n"+ "Wei,94,A\n"

#texto = texto.replace(",", ";")

arquivo.write(texto)

arquivo.close()

"""Podemos ler arquivos CSV da mesma forma que outros arquivos de texto. Devido à estrutura padronizada dos dados, existe um padrão comum para processá-los. Normalmente, os arquivos CSV terão um cabeçalho como a primeira linha, que contém nomes de colunas. Em seguida, cada linha a seguir no arquivo conterá dados que correspondem às colunas apropriadas.

Todos os métodos de arquivo que mencionamos - `read`, `readline` e `readlines` e simplesmente trabalhar com a própria variável do arquivo, funcionarão em arquivos CSV. Nos nossos exemplos, iteraremos sobre as linhas. Como os valores em cada linha são separados por vírgulas, podemos usar o método `split` para analisar cada linha em uma coleção de valores separados.
"""

arquivo = open("notas.csv", 'r') 
cabecalho = arquivo.readline() 
colunas = cabecalho.strip().split(';') 
for linha in arquivo.readlines(): 
  valores = linha.strip().split(';') 
  if int(valores[1]) > 70: 
    print(valores[0], "passou com o conceito", valores[2])

"""O padrão típico para gravar dados em um arquivo CSV será escrever uma linha de cabeçalho e percorrer os itens de uma lista, produzindo uma linha para cada. Podemos fazer, por exemplo, uma lista de listas, cada uma representando um país, um subconjunto de linhas e colunas do arquivo do qual lemos."""

paises = [["Itália", 3, 20, 62, 155, 229, 322], 
          ["Espanha", 2, 2, 2, 2, 2, 6], 
          ["Alemanha", 16, 16, 16, 16, 17, 27], 
          ["Coréia do Sul", 104, 204, 433, 602, 833, 977]] 

corona = open("corona.csv", "w") 
cabecalho = "País;20;21;22;23;24;25"
cabecalho = cabecalho.replace(";",",")
corona.write(cabecalho) 
corona.write("\n") 
for pais in paises: 
  linha = "{};{};{};{};{};{};{}".format(pais[0], pais[1], pais[2], pais[3], pais[4], pais[5], pais[6]) 
  linha = linha.replace(";", ",")
  corona.write(linha) 
  corona.write("\n")
corona.close()