from posixpath import sep
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

'''
  Código desenvolvido por Matheus Baron Lauritzen, Gustavo Baron Lauritzen e Gabriel Bósio
'''

#lendo arquivo csv
olimpiadas = pd.read_csv("/content/drive/MyDrive/Databases/Olimpiadas2021/Tokyo 2021 dataset v4.csv")

#filtro de coluna
valores = olimpiadas['Gold Medal']
#Salvando em csv
valores.to_csv("filtro_coluna.csv", index=False)

#1 operação com filtro
filtro = olimpiadas['Team/NOC'].str.contains("Brazil")
brasil = olimpiadas[filtro]
#Salvando em csv
brasil.to_csv("filtro_brasil.csv", index=False)

#2 operação com filtro, utilizados para exibir o 1 gráfico
filtro_menor_20_ouro = olimpiadas['Gold Medal'] < 20
filtro_maior_10_ouro = olimpiadas['Gold Medal'] > 10
#Filtro para pegar os paises com menos de 20 medalhas de ouro
paises_com_menos_20_ouro = olimpiadas[filtro_menor_20_ouro]
paises_com_mais_10_ouro = olimpiadas[filtro_maior_10_ouro]
paises_com_mais_10_qtd_ouro = paises_com_mais_10_ouro['Gold Medal'].values
paises_com_mais_10_nomes = paises_com_mais_10_ouro['NOCCode'].values
#Gráfico 1
print('\n')
plt.plot(paises_com_mais_10_nomes,paises_com_mais_10_qtd_ouro, color="#FFDF00", marker="o") 
plt.title('Países com mais de 10 medalhas de ouro:') 
plt.xlabel('Países') 
plt.ylabel('Quantidade') 
plt.legend(['Medalhas de Ouro'])
plt.axis(ymin = 10, ymax = 40)
#Salvando em pdf
plt.savefig("grafico1.pdf")
plt.show()
#Filtro para pegar os paises que possuem entre 10 a 20 medalhas de ouro
paises_entre_10_20 = paises_com_menos_20_ouro[paises_com_menos_20_ouro['Gold Medal'] > 10]
#Salvando em csv
paises_entre_10_20.to_csv("entre_10_20.csv", index=False)
paises_com_mais_10_ouro.to_csv("maior_10.csv", index=False)
paises_com_menos_20_ouro.to_csv("menor_20.csv", index=False)

#3 operação com filtro, utilizados na contrução do 2 gráfico
prata_filtro = olimpiadas['Silver Medal'] > 20
paises_prata = olimpiadas[prata_filtro]
prataa = paises_prata['Silver Medal'].values
nomes_paisess_prata = paises_prata['NOCCode'].values
#Salvando em csv
paises_prata.to_csv("paises_prata.csv", index=False)
#Gráfico 2
print('\n')
plt.plot(nomes_paisess_prata,prataa, color="#aaa9ad", marker="o") 
plt.title('Países com mais de 20 medalhas de prata:') 
plt.xlabel('Países') 
plt.ylabel('Quantidade') 
plt.legend(['Medalhas de Prata'])
plt.axis(ymin = 20, ymax = 45)
#Salvando em pdf
plt.savefig("grafico2.pdf")
plt.show()

#4 operação com filtro, utilizados na contrução do 3 gráfico
bronze_filtro = olimpiadas['Bronze Medal'] > 20
paises_bronze = olimpiadas[bronze_filtro]
bronzee = paises_bronze['Bronze Medal'].values
nomes_paisess_bronze = paises_bronze['NOCCode'].values
#Salvando em csv
paises_bronze.to_csv("paises_bronze.csv", index=False)
#Gráfico 3
print('\n')
plt.plot(nomes_paisess_bronze,bronzee, color="#cd7f32", marker="o") 
plt.title('Países com mais de 20 medalhas de bronze:') 
plt.xlabel('Países') 
plt.ylabel('Quantidade') 
plt.legend(['Medalhas de Bronze'])
plt.axis(ymin = 20, ymax = 35)
#Salvando em pdf
plt.savefig("grafico3.pdf")
plt.show()

#1 operação com groupby
grupoPorContinente = olimpiadas.groupby('Continent')
#Média de medalhas entre os países de cada continente
media = grupoPorContinente['Total'].mean()
#Salvando em csv
media.to_csv("media_groupby.csv", index=False)

#2 operação com groupby
#Soma de medalhas de cada continente
soma = grupoPorContinente['Total'].sum()
#Salvando em csv
soma.to_csv("soma_groupby.csv", index=False)