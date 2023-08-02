# -*- coding: utf-8 -*-
"""
Trabalho M1.1
---
### Problema 1
---
Um posto está vendendo combustíveis com a seguinte tabela de descontos:

*   Álcool: até 20 litros, desconto de 3% por litro e acima de 20 litros, desconto de 5% por litro;
*   Gasolina: até 20 litros, desconto de 4% por litro e acima de 20 litros, desconto
de 6% por litro.

Escreva um algoritmo que leia o número de litros vendidos, o tipo de
combustível (A-álcool, G-gasolina) e imprima o valor a ser pago pelo cliente.
Considere que o preço do litro da gasolina é 2,49 e o preço do litro do álcool é R$ 1,69.
"""

tipo = input("Digite o tipo de combustível(A-álcool, G-gasolina): ")
qtd_litros = int(input("Digite a quantidade de litros: "))
desconto = 0
preco_final = 0
if(tipo == 'A'):
  if(qtd_litros <= 20):
    desconto = (qtd_litros*1.69) * 0.03
  else:
    desconto = (qtd_litros*1.69) * 0.05
  preco_final = (qtd_litros*1.69) - desconto
elif(tipo == 'G'):
  if(qtd_litros <= 20):
    desconto = (qtd_litros*2.49) * 0.04
  else:
    desconto = (qtd_litros*2.49) * 0.06    
  preco_final = (qtd_litros*2.49) - desconto
else:
  print("Valor inválido :(")
print("Valor a ser pago:", round(preco_final, 2))

"""### Problema 2
---
Escreva um algoritmo que solicite ao usuário um valor (total) em dinheiro, e informe a quantidade de notas de: 2 reais, 5 reais, 10 reais, 20 reais, 50 reais e 100 reais, e a quantidade de moedas de: 1 real, 50 centavos, 25 centavos, 10 centavos e 1 centavo que serão
necessárias para compor este valor, de forma que seja utilizado o menor número de notas e moedas possível.
"""

valor = float(input("Digite um valor: "))
nota = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00]
moeda = [1.00, 0.50, 0.25, 0.10, 0.01]
qtd_m = []
qtd_n = []
while valor >= 2.00:
  for i in range(6):
    qtd_n.append(valor // nota[i])
    valor = valor % nota[i]
while True:
  for i in range(5):
    qtd_m.append(valor // moeda[i])
    valor = valor % moeda[i]
  if(valor < 0.001):
    break
  else:
    qtd_m[4] = qtd_m[4] + 1
    break
      
print("Notas:","R$ 100.00:",qtd_n[0],"R$ 50.00:",qtd_n[1],"R$ 20.00:",qtd_n[2],"R$ 10.00:",qtd_n[3],"R$ 5.00:",qtd_n[4],"R$ 2.00:",qtd_n[5])
print("Moedas:","R$ 1.00:",qtd_m[0],"R$ 0.50:",qtd_m[1],"R$ 0.25:",qtd_m[2],"R$ 0.10:",qtd_m[3],"R$ 0.01:",qtd_m[4])

"""### Problema 3
---
Faça um algoritmo que verifique e escreva todos os números inteiros perfeitos entre 1 a 10000.

*Um número se diz perfeito se é igual à soma de seus divisores próprios. Divisores próprios de um número positivo N são todos os divisores inteiros positivos de N exceto o próprio N. Por exemplo, o número 6, seus divisores próprios são 1, 2 e 3, cuja soma é igual à 6. 28 também é um número perfeito, já que é divisível por 1, 2, 4, 7, 14*
"""

perfeitos = []
for n in range(1, 10001):
    soma = 0
    for i in range(1, n):
        if n % i == 0:
            soma += i
    if n == soma:
        perfeitos.append(n)
print("Os números perfeitos até 10000 são:",perfeitos)

"""### Problema 4
---
A cifra de César é uma cifra de substituição simples em que cada letra do texto é substituída por outra letra movendo `n` posições no alfabeto. Por exemplo, suponha que o texto simples de entrada seja o seguinte:

`abcd xyz bola`

Se o valor de deslocamento, n, for 4, o texto criptografado seria o seguinte:

`efgh bcd fspe`

Escreva uma programa que tenha uma mensagem de texto simples e um número de letras para deslocar na cifra. Ela deve fazer uma string criptografada com todas as letras transformadas e toda a pontuação e espaço em branco permanecendo inalterados.

Nota: Você pode presumir que o texto simples é todo em minúsculas, exceto para espaços em branco e pontuação.
Podem criam uma string `alfabeto="abcdefghijklmnopqrstuvwxyz"` para auxiliar.
"""

#encoding: utf-8
alfabeto="abcdefghijklmnopqrstuvwxyz"
msg = input("Digite uma mensagem: ")
msg = msg.lower()
d = int(input("Digite o deslocamento: "))
msg_final = ""
for n in msg:
    if(n in alfabeto):
        caracter = alfabeto.find(n)
        caracter += d
        if(caracter > len(alfabeto)):
            caracter = caracter - len(alfabeto)
        msg_final = msg_final + alfabeto[caracter]
    else:
            msg_final = msg_final + n

print(msg_final)