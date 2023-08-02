import keyword

import pygame as pyg
import pygame.font
from pygame.locals import *
import random as rd

#Código desenvolvido pelos alunos Gustavo Baron Lauritzen, Matheus Baron Lauritzen e Gabriel Bósio

# Verifica colisão entre a cobrinha e o item
def pegar_item(cobrinha, item):
    # Se a linha e coluna da cobrinha for igual a do item, retorna uma colisão
    if (cobrinha[0] == item[0]) and (cobrinha[1] == item[1]):
        return True

#Verifica colisão com as bordas e o resto do corpo
def colisao(cobrinha):
    if (cobrinha[0][0] > 390) or (cobrinha[0][0] < 0) or (cobrinha[0][1] > 390) or (cobrinha[0][1] < 0):
        return 1
    for i in range(1, len(cobrinha)-1):
        if (cobrinha[0][0] == cobrinha[i][0]) and (cobrinha[0][1] == cobrinha[i][1]):
            return 1
    return 0


# Gera um numero aleatório
def numero_aleatorio():
    # Variáveis com os numeros aleatórios entre 0 e 390
    i = rd.randint(0, 390)
    j = rd.randint(0, 390)
    # Retorna esses numeros na forma de inteiro em múltiplos de 10
    return i // 10 * 10, j // 10 * 10

# Função jogo
def jogo():
    # Iniciando os módulos da Pygame
    pyg.init()

    # Definindo a tela do jogo para o tamanho de 500x500
    tela = pyg.display.set_mode([400, 400])

    # Escrevendo o título do jogo que aparece na tela
    pyg.display.set_caption('Jogo da Cobrinha')

    # Inicializando a variável do 'corpo' da cobrinha
    cobrinha = [(100, 100), (110, 100), (120, 100)]

    # Inicializando a variável do 'pele' da cobrinha,
    # pois para poder mostrar na tela é preciso ser
    # em cima de alguma superfície, no caso, uma superfície 10x10
    pele_cobrinha = pyg.Surface([10, 10])

    # Colocando cor na pele da cobrinha em RGB
    pele_cobrinha.fill([255, 255, 255])

    # Inicializando as variáveis de direções
    esquerda = 3
    baixo = 2
    direita = 1
    cima = 0

    # Inicializando a variável do direção da cobrinha
    direcao = direita

    # Inicializando a variável do item que a cobrinha irá consumir
    item = pyg.Surface([10, 10])

    # Colocando cor nesse item em RGB
    item.fill([0, 0, 255])

    # Gerando uma posição aleatória para esse item
    item_posicao = numero_aleatorio()

    #pontuação inicial
    pontos = 0

    # Iniciando a variável responsável pela limitação do fps da tela
    relogio = pyg.time.Clock()


    #Preparação para as mensagens de texto
    fonte_placar = pygame.font.SysFont('arial', 20, False, False)
    fonte_GameOver = pygame.font.SysFont('arial', 50, True, False)
    GameOver = fonte_GameOver.render('Game Over', True, (255, 255, 255))

    while True:
        relogio.tick(10)

        placar = f'Pontuação: {pontos}'
        msg_placar = fonte_placar.render(placar, True, (255, 255, 255))

        # Verificando o eventos
        for evento in pyg.event.get():
            # Verifica evento de sair do jogo
            if evento.type == QUIT:
                pyg.quit()
            # Verifica evento de apertar tecla
            if evento.type == KEYDOWN:
                if evento.key == K_LEFT and direcao != direita:
                    direcao = esquerda
                if evento.key == K_DOWN and direcao != cima:
                    direcao = baixo
                if evento.key == K_RIGHT and direcao != esquerda:
                    direcao = direita
                if evento.key == K_UP and direcao != baixo:
                    direcao = cima

        # Verifica se houve colisão com um item, se sim então gera um novo lugar pro item e a cobrinha aumenta de tamanho
        if pegar_item(cobrinha[0], item_posicao):
            item_posicao = numero_aleatorio()
            cobrinha.append([0, 0])
            pontos += 1
            # Não importa o valor que colocar dentro do append, essa nova parte da cobrinha vai
            # tomar o lugar da "cauda"

        # Mexendo o restante do corpo da cobra de acordo com a cabeça
        # inicio incluso(-1) #fim n incluso(0) #decremento(-1)
        for i in range(len(cobrinha) - 1, 0, -1):  # Percorre o corpo da cobra de trás pra frente
            cobrinha[i] = (
                cobrinha[i - 1][0], cobrinha[i - 1][1])  # A posição anterior da cobrinha passa a ter posição da frente

        # Verificando a direção em que a cobrinha irá se movimentar(a partir da "cabeça" da cobrinha)
        if direcao == esquerda:
            cobrinha[0] = (cobrinha[0][0] - 10, cobrinha[0][1])
        if direcao == direita:
            cobrinha[0] = (cobrinha[0][0] + 10, cobrinha[0][1])
        if direcao == baixo:
            cobrinha[0] = (cobrinha[0][0], cobrinha[0][1] + 10)
        if direcao == cima:
            cobrinha[0] = (cobrinha[0][0], cobrinha[0][1] - 10)

        # Limpando a tela
        tela.fill([0, 0, 0])

        # Mostrando a cobrinha na tela
        for posicao in cobrinha:
            tela.blit(pele_cobrinha, posicao)

        # Mostrando o item na tela
        tela.blit(item, item_posicao)

        #Mostrando o placar
        tela.blit(msg_placar, (5,375))

        # checagem de colisao com o próprio corpo ou com as paredes
        if colisao(cobrinha):
            tela.blit(GameOver, (50, 200))
            pyg.display.update()
            while True:
                for evento in pygame.event.get():
                    if evento.type == QUIT:
                        pyg.quit()

        pyg.display.update()


jogo()
