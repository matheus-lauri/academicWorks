import random as rd

'''
Código desenvolvido por Gustavo Baron Lauritzen e Matheus Baron Lauritzen
para a disciplina de Introdução a Python
'''

#Calcula as posições adjacentes
def calcular_adjacentes(m):
  for a in range(0, 9):
    for b in range(0, 9):
      if m[a][b][0] == '@': continue
      cont_adj = 0
      for c in range(a-1 if a>0 else 0, a+2 if a<8 else 9):
        for d in range(b-1 if b>0 else 0, b+2 if b<8 else 9):
          if m[c][d][0] == '@': 
            cont_adj += 1
      if(cont_adj == 0):
        m[a][b][0] = '-'
      else:
        m[a][b][0] = str(cont_adj)
  return m

#Exibe os valores adjacentes, se a posição digitada estiver vazia, e exibe os valores adjacentes vazios do lado, como no jogo original
def exibir_adjacentes_vazios(m):
  while True:
    edit = False
    for a in range(0, 9):
      for b in range(0, 9):
        for c in range(a-1 if a>0 else 0, a+2 if a<8 else 9):
          if len(m[a][b]) == 1: continue
          mostrar = False
          for d in range(b-1 if b>0 else 0, b+2 if b<8 else 9):
            if m[c][d][0] == '-' and len(m[c][d]) == 1:
              m[a][b].pop(1)
              mostrar = edit = True
              break
          if mostrar: 
            break
    if not edit: 
      return m

#Adiciona 10 bombas na matriz gabarito
def adicionar_bombas(m):
  for c in range(0, 10):
    while True:
      i = rd.randint(0, 8)
      j = rd.randint(0, 8)
      if m[i][j][0] != '@':
        m[i][j][0] = '@'
        break
  return m

#Exibe a matriz 'gabarito', a que contém as bombas e os números
def exibir_matriz_gabarito(m):
  for c in m:
    print(f'[{c[0][0]},', end='')
    for d in range(1, 8):
        print(f' {c[d][0]},', end='')
    print(f' {c[8][0]}]')

#Exibe a matriz jogo
def exibir_matriz_jogo(m):
  for i in m:
      print(f'[{i[0][-1]},', end='')
      for j in range(1, 8):
          print(f' {i[j][-1]},', end='')
      print(f' {i[8][-1]}]')
  print(" "*4, end="")

'''
Preenche a matriz que será utilizada no jogo, essa matriz contém 'duas' matrizes,
a matriz do indice '0' terá as bombas e os numeros dizendo se a bomba está perto
ou não. Já a matriz com índice '1' terá todas as suas posições preenchidas com os '#'
OBS: Utilizamos uma matriz 9x9 para fazer o jogo, com a adição de 10 bombas
'''
def preenche_matriz_jogo(m):
  m = [[['-', '#'] for i in range(0, 9)] for j in range(0, 9)]
  
  return m

#Início do jogo
jogar = True
matriz_jogo = []
matriz_jogo = preenche_matriz_jogo(matriz_jogo)
matriz_jogo = adicionar_bombas(matriz_jogo)
matriz_jogo = calcular_adjacentes(matriz_jogo)
#Laço principal do jogo
while(jogar == True):
  exibir_matriz_jogo(matriz_jogo)
  #Recebe linha e coluna
  i = 10
  while( i < 0 or i > 8):
    i = int(input("Digite a linha: ")) - 1
  j = 10
  while( j < 0 or j > 8):
    j = int(input("Digite a coluna: ")) - 1
  
  #Verifica se a posição digitada é uma bomba, se sim o jogador perde
  if matriz_jogo[i][j][0] == '@':
    exibir_matriz_gabarito(matriz_jogo)
    print("GAME OVER :(")
    jogar = False
    break
  #Exibe os valores adjacentes vazios, se o valor digitado estiver com '-', no caso não foi revelado
  elif matriz_jogo[i][j][0] == '-':
    if len(matriz_jogo[i][j]) == 2:
      matriz_jogo[i][j].pop(1) #O '.pop' susbtitui um item da lista, nesse caso ele substitui um item da lista com indice '1' pelo item de mesma posição da matrz com indice '0'
    matriz_jogo = exibir_adjacentes_vazios(matriz_jogo)
  #Exibe apenas uma posição se não estiver vazio e nem for uma bomba, ou seja tem uma bomba por perto...
  else:
    if len(matriz_jogo[i][j]) == 2: 
      matriz_jogo[i][j].pop(1)
  
  #Verifica a vitória
  posicoes_nao_abertas = 0
  for i in matriz_jogo:
    for j in i:
      if len(j) == 2:
        posicoes_nao_abertas += 1
  if(posicoes_nao_abertas <= 10):
    exibir_matriz_gabarito(matriz_jogo)
    print("GAME WIN :)")
    jogar = False
    break