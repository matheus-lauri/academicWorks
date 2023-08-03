.data
	ex: .asciz "Entre com valor de X:"
	ey: .asciz "Entre com valor de Y:"
	xy: .asciz "A soma de X e Y e igual a:"

.text
	
	#escreve texto
	addi a7, zero, 4
	la a0, ex
	ecall
	
	#ler texto, nesse caso é ler um inteiro
	addi a7, zero, 5
	ecall
	add s0, zero, a0 # x esta no s0
	
	#escreve texto
	addi a7, zero, 4
	la a0, ey
	ecall
	
	#ler texto, nesse caso é ler um inteiro
	addi a7, zero, 5
	ecall
	add s1, zero, a0 # y esta no s1
	
	#fazer a soma de x e y
	add s2, s0, s1
	
	#escreve texto da soma
	addi a7, zero, 4
	la a0, xy
	ecall
	
	#escreve o resultado da soma
	addi a7, zero, 1
	add a0, zero, s2
	ecall