# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Programa 01
# Grupo: - Matheus Baron Lauritzen
#        - Gustavo Baron Lauritzen
#        - Gabriel Bosio

.data
Vetor_A: .word 0,0,0,0,0,0,0,0
Vetor_B: .word 0,0,0,0,0,0,0,0

msg1: .asciz "||Preenchimento dos vetores||\n\n"
msg2: .asciz "\n||Trocando valores do mesmo índice||\n\n"
msg3: .asciz "\n||Vetores após a troca||\n\n"

en_A: .asciz "\nInsira os dados do Vetor_A:"
req_A: .asciz "\nVetor_A["

en_B: .asciz "\nInsira os dados do Vetor_B:"
req_B:.asciz "\nVetor_B["

fim_req: .asciz "]: " 

er: .asciz "\nValor errado, digite novamente..."

quebra: .asciz "\n"

.text

#parametros do laço de contagem
addi t0, zero, 0
addi s0, zero, 8

#inicialização dos vetores
la s1, Vetor_A
la s2, Vetor_B

#mensagem de inicio de preenchimento
addi a7, zero, 4
la a0, msg1
ecall

#enunciado do Vetor_A
addi a7, zero, 4
la a0, en_A
ecall

for1:

#impressão do requerimento do Vetor_A
addi a7, zero, 4
la a0, req_A
ecall

addi a7, zero, 1
add a0, zero, t0
ecall

addi a7, zero, 4
la a0, fim_req
ecall

#cin Vetor_A
addi a7, zero, 5
ecall
add t1, zero, a0

#mostrará mensagem de erro caso t1 <= 0 ou t1 > 8
addi s5, zero, 0
ble t1, s5 , erro1
bgt t1, s0, erro1

#armazenamento no vetor_A
slli t2, t0, 2
add s3, s1, t2
sw t1, 0(s3)

#cont++
addi t0, t0, 1

#sair caso chegue ao fim do laço ou repetir caso não
bge t0, s0, fim_1
jal zero, for1

erro1:

#mensagem de erro e repetição do último cin 
addi a7, zero, 4
la a0, er
ecall
jal zero, for1

fim_1:

#enunciado do Vetor_B
addi a7, zero, 4
la a0, en_B
ecall

#zerando novamente o contador
addi t0, zero, 0

for2:

#impressão do requerimento do Vetor_B
addi a7, zero, 4
la a0, req_B
ecall

addi a7, zero, 1
add a0, zero, t0
ecall

addi a7, zero, 4
la a0, fim_req
ecall

#cin Vetor_B
addi a7, zero, 5
ecall
add t1, zero, a0

#mostrará mensagem de erro caso t1 <= 0 ou t1 > 8
ble t1, s5, erro2
bgt t1, s0, erro2

#armazenamento no vetor_B
slli t2, t0, 2
add s3, s2, t2
sw t1, 0(s3)

#cont++
addi t0, t0, 1

#sair caso chegue ao fim do laço ou repetir caso não
bge t0, s0, fim_2
jal zero, for2

erro2:

#mensagem de erro e repetição do último cin 
addi a7, zero, 4
la a0, er
ecall
jal zero, for2

fim_2:

#mensagem de inicio de troca
addi a7, zero, 4
la a0, msg2
ecall

#zerando contador
addi t0, zero, 0

for_troca:

#pegando o endereço do índice
slli t2, t0, 2
add s3, s1, t2
add s4, s2, t2

#guardando o dado do Vetor_A num registrador temporário
lw a0, 0(s3)
add t3, zero, a0

#passa o valor do Vetor_B para o Vetor_A
lw a0, 0(s4)
add t4, zero, a0
sw t4, 0(s3)

#passa valor no registrador temp e passa para o Vetor_B
sw t3, 0(s4)

addi t0, t0, 1

#repete até que termine a contagem
bge t0, s0, troca_fim
jal zero, for_troca

troca_fim:

#mensagem de inicio de impressão
addi a7, zero, 4
la a0, msg3
ecall

addi t0, zero, 0

for_imp1:

#impressão da mensagem de amostragem
addi a7, zero, 4
la a0, req_A
ecall

addi a7, zero, 1
add a0, zero, t0
ecall

addi a7, zero, 4
la a0, fim_req
ecall

#encontrando o índice
slli t2, t0, 2
add s3, s1, t2
lw a0, 0(s3)

#imprimindo o valor
addi a7, zero, 1
ecall

#repetição do laço até o fim da contagem
addi t0, t0, 1
bge t0, s0, for_imp1_fim
jal zero, for_imp1

for_imp1_fim:

addi a7, zero, 4
la a0, quebra
ecall

addi t0, zero, 0

for_imp2:

#impressão da mensagem de amostragem
addi a7, zero, 4
la a0, req_B
ecall

addi a7, zero, 1
add a0, zero, t0
ecall

addi a7, zero, 4
la a0, fim_req
ecall

#encontrando o índice
slli t2, t0, 2
add s3, s2, t2
lw a0, 0(s3)

#imprimindo o valor
addi a7, zero, 1
ecall

#repetiçaõ do laço até o fim da contagem
addi t0, t0, 1
bge t0, s0, for_imp2_fim
jal zero, for_imp2

for_imp2_fim:
