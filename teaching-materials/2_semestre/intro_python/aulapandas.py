# -*- coding: utf-8 -*-
"""AulaPandas.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Bii4mMlZaqbDBDvdlkoJauhEqiSajiN5

Bibliotecas

---
"""

pip install pandas

import matplotlib.pyplot as plt 
import pandas as pd 
import numpy as np

"""# Pandas

---

## Datasets - Kaggle

---

Kaggle é a maior plataforma de hospedagem para projetos e competições de Data Science que existe atualmente. Kaggle disponibiliza datasets, kernels, plataforma de aprendizado e fórum para perguntas. 

[Kaggle](https://www.kaggle.com/) 

Ele também tem uma API que permite manipular informações e fazer download dessas bases de dados. 

[API Kaggle](https://github.com/Kaggle/kaggle-api)

## Leitura de CSV

---

Ao invés de lermos os arquivos de texto, podemos ler o .CSV diretamente com o Pandas.
"""

filmes = pd.read_csv("filmes.csv")
print(filmes)

"""## DataFrame

---

O comando `read_csv` retorna um `Dataframe` do Pandas (que é o tipo padrão mais importante dentro da Pandas), então já podemos trabalhar diretamente com ele, como o comando columns para retornar o cabeçalho de cada coluna.
"""

print(filmes.columns)

print(filmes.dtypes)

"""Podemos também analisar as diferentes categorias de um atributo, vendo somente as instâncias únicas de cada coluna.Podemos também analisar as diferentes categorias de um atributo, vendo somente as instâncias de cada coluna."""

print(filmes['year'])
teste = filmes['year']

"""Com o `unique()` ele retorna uma lista com os nomes únicos daquela coluna. """

filmes['year'].values

filmes['year'].unique()

if 1910 in filmes['year'].unique():
  print("Existem filmes desse ano")
else:
  print("Não existem filmes desse ano")

"""Podemos fazer limpeza dos dados, e modificações para padronização, com os comandos `dropna`, para cada dado, conseguimos verificar se algum dado falta com o comandos `isna`. Também podemos utilizar condicionais dentro dos colchetes."""

print(filmes)
print()
print(filmes['year'])
print()
print(filmes['year'] == 1930)
print()

filtro = filmes['year'] == 1930

filmes1930 = filmes[filtro]
print(filmes1930)
print()
print(filmes1930['title'].values)
#print(filmes['title'].values)

filtroAntes1930 = filmes['year'] < 1930
filtroDepois1924 = filmes['year'] > 1924

filmesAntes1930 = filmes[filtroAntes1930]
filmesdepois1924 = filmes[filtroDepois1924]
filmesEntre1925e1929 = filmesAntes1930[filmesAntes1930['year'] > 1924]


print(filmesAntes1930['title'].values)
print(filmesdepois1924['title'].values)
print(filmesEntre1925e1929['title'].values)

filtroAntes1930 = filmes['year'] < 1930
filtroDepois1924 = filmes['year'] > 1924

filmesAntes1930 = filmes[filtroAntes1930]
filmesdepois1924 = filmes[filtroDepois1924]
filmesEntre1925e1929 = filmesAntes1930[filtroDepois1924]


print(filmesAntes1930['title'].values)
print(filmesdepois1924['title'].values)
print(filmesEntre1925e1929['title'].values)

filtro = filmes['title'] == 'Toy Story '

toyStory = filmes[filtro]
print(filmes)
print(toyStory)

filtro = filmes['title'].str.contains("Star Wars")

filmesToyStory = filmes[filtro]
print(filmesToyStory)

filmesAnimacao = filmes[filmes['genres'].str.contains("Animation")]
filmesAnimacao = filmesAnimacao[filmesAnimacao['genres'].str.contains("Fantasy")]
filmesAnimacaoDepois1995 = filmesAnimacao[filmesAnimacao['year'] >= 1995]
filmesAnimacaoDepois1995 = filmesAnimacaoDepois1995[filmesAnimacaoDepois1995['year'] <= 2005]


filmesAnimacaoDepois1995 = filmesAnimacaoDepois1995.filter(['title', 'year'])
print(filmesAnimacaoDepois1995)

filmesFiltrado = filmes.filter(['title', 'year'])
print(filmesFiltrado)

"""Salvar para o CSV"""

from posixpath import sep
filmesAnimacao = filmes[filmes['genres'].str.contains("Animation")]
filmesAnimacao = filmesAnimacao[filmesAnimacao['genres'].str.contains("Fantasy")]
filmesAnimacaoDepois1995 = filmesAnimacao[filmesAnimacao['year'] >= 1995]
filmesAnimacaoDepois1995 = filmesAnimacaoDepois1995[filmesAnimacaoDepois1995['year'] <= 2005]
filmesAnimacaoDepois1995 = filmesAnimacaoDepois1995.filter(['title', 'year'])
print(filmesAnimacaoDepois1995)
filmesAnimacaoDepois1995.to_csv("FilmesAnimacaoDepois1995.csv", index=False)

"""Podemos agrupo dados a partir do `groupby` para agrupar os dados a partir de um atributo, ele vai reunir os valores, podemos a partir dele pegar dataframes, como a partir do número de elementos(count), média(mean) e desvio padrão(std)"""

grupoPorAno = filmes.groupby('genres')

for ano, filmesAno in grupoPorAno:
  print(ano)
  print(filmesAno)
  filmesAno.to_csv("Filmes" + str(ano) + ".csv", index=False)

#filmesAnimacao = filmes[filmes['genres'].str.contains("Animation")]
#grupoPorAnoAnimacao = filmesAnimacao.groupby(by=['year'])
print(grupoPorAno.count())

print(grupoPorAno['year'].mean())
print(grupoPorAno['title'].count())

filmesTeste = filmes[filmes['year'] > 2010]

grupoPorAno = filmesTeste.groupby(by=['year'])

for ano, filmesAno in grupoPorAno:
  print(ano)
  filmesAno = filmesAno.filter(items=['title', 'genres'])
  filmesAno.to_csv('FilmesDe' + str(ano) + '.csv', index=False)

"""## Exemplo com notas

---

Podemos unir duas tabelas e fazer algumas operações com elas.
"""

notas = pd.read_csv("notas.csv")
filmesComNotas = filmes.join(notas.set_index("movieId"), on="movieId")
print(filmes.columns)
print(notas.columns)
print(filmesComNotas.columns)
print(filmesComNotas)

grupoFilmes = filmesComNotas.groupby("title")

print(grupoFilmes['rating'].mean())
print(grupoFilmes['rating'].count())

"""## Exibindo os Resultados"""

filmes = pd.read_csv("filmes.csv")

filmesLegais = filmes[filmes['year'] < 2016]

gp = filmesLegais.groupby('year')
contagemFilmes = gp['title'].count()
contagemFilmes.plot()

plt.show()

filmes = pd.read_csv("filmes.csv")

filmesLegais = filmes[filmes['year'] < 2016]

gp = filmesLegais.groupby('year')
contagemFilmes = gp['title'].count()
contagemFilmes.plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Comedy')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Animation')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Drama')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Children')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Sci-Fi')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('War')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Western')]
gpa = filmesAnima.groupby('year')
gpa['title'].count().plot()

plt.legend(['Total', 'Comédia', 'Animação', 'Drama', 'Infantil', 'Ficção Científica', 'Guerra', 'Faroeste'])
plt.savefig("grafico_anos.svg")
plt.show()

gp = filmesComNotas.groupby('rating')
gp['title'].count().plot()

filmesLegais = filmesComNotas

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Comedy')]
gpa = filmesAnima.groupby('rating')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Animation')]
gpa = filmesAnima.groupby('rating')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Drama')]
gpa = filmesAnima.groupby('rating')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Children')]
gpa = filmesAnima.groupby('rating')
gpa['title'].count().plot()

filmesAnima = filmesLegais[filmesLegais['genres'].str.contains('Thriller')]
gpa = filmesAnima.groupby('rating')
gpa['title'].count().plot()

plt.legend(['Total', 'Comédia', 'Animação', 'Drama', 'Infantil', 'Ficção Científica'])
plt.show()

filmesComNotas = filmesComNotas[filmesComNotas['year'] > 1950]
gp = filmesComNotas.groupby('year')
plt.plot(gp['rating'].mean())
plt.axis(ymin=3, ymax=4)
plt.show()

gp = filmesComNotas.groupby('rating')
dataframe = gp.count()
series = dataframe["title"]
plt.plot(series)
plt.show()

print(gp)
print(dataframe)
print(series)

"""# Subplot - Matplotlib

---

Quando queremos dividir o gráfico dentro do matplotlib, normalmente utilizamos a função de subplot, ela vai determinar uma região para o gráfico dentro de um grid, pode ser por um único número de 3 dígitos, ou 3 parâmetros inteiros. Eles representam o tamanho do grid em linhas e colunas, e o índice dentro desse grid que o gráfico ocupa.
"""

np.random.seed(19680801) 
x = np.random.rand(10) 
y = np.random.rand(10) 
z = np.sqrt(x**2 + y**2)

plt.subplot(3,2,1) 
plt.scatter(x, y, s=80, c=z, marker=">") 

plt.subplot(3,2,2) 
plt.scatter(x, y, s=80, c=z, marker=(5, 0)) 

verts = np.array([[-1, -1], [1, -1], [1, 1], [-1, -1]]) 
plt.subplot(3,1,2) 
plt.scatter(x, y, s=80, c=z, marker=verts) 

plt.subplot(3,2,5) 
plt.scatter(x, y, s=80, c=z, marker=(5, 1)) 

plt.subplot(3,2,6)
plt.scatter(x, y, s=80, c=z, marker='+') 

plt.show()