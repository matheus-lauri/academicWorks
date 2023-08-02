# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 03 – Programação de Procedimentos
# Programa 01
# Grupo: - Gabriel Bosio
# 	 	 - Gustavo Baron Lauritzen
#	 	 - Matheus Baron Lauritzen

.data

	vetor: .word 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99

	cout: .asciz "Valor da soma dos numeros do vetor: "
	cout2: .asciz"Digite a posicao(2-100): "
.text

	jal zero, main

soma_vetor:
	loop1:
		addi a1, a1, -1 #a1 = posicoes, subtrai para usar como indice
		
		slli t0, a1, 2 #calculo de enderecamento e carregamento do valor
		add t1, t0, a0
		lw s0, 0(t1)
				
		add s1, s1, s0 #soma = soma + s0"v[i]"
		
		bgt a1, zero, loop1
	
	addi sp, sp, -4 #guardando a soma na pilha
	sw s1, 0(sp)
		
	jalr ra, 0

main:
	addi t5, zero, 2#utilizado como parametro de condicao
	addi t6, zero, 100#utilizado como parametro de condicao

	while1:
		
		addi a7, zero, 4 #impressao da descricao
		la a0, cout2
		ecall
		
		addi a7, zero, 5
		ecall
		add t4, zero, a0 
		
		blt t4,t5,while1
		bgt t4,t6,while1
	
	la a0, vetor
	add a1, zero, t4
	jal ra, soma_vetor #chamada de procedimento
	
	addi a7, zero, 4 #impressao da descricao
	la a0, cout
	ecall
	
	lw s1, 0(sp) #lendo a soma da pilha
	addi sp, sp, 4
	
	addi a7, zero, 1#impressao do resultado soma
	add a0, zero, s1
	ecall
