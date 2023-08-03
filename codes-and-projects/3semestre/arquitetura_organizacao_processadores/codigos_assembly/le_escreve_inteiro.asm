.data
texto1: .asciz "Informe um valor: "
texto2: .asciz "Valor digitado: "

.text
	#imprime a string colocada em a0
	addi a7, zero, 4#li a7, 4
	la a0, texto1
	ecall
	
	#solicita um inteiro
	addi a7, zero, 5
	ecall
	add t0, zero, a0 #salva em t0 o valor digitado
	
	#imprime a string colocada em a0
	addi a7, zero, 4
	la a0, texto2
	ecall
	
	#imprime inteiro
	addi a7, zero, 1
	add a0, zero, t0
	ecall