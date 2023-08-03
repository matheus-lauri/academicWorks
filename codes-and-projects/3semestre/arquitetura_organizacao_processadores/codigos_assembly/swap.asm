.data
texto1: .asciz "Informe dois valores: "

.text
	#imprime a string colocada em a0
	addi a7, zero, 4
	la a0, texto1
	ecall
	
	#solicita um inteiro
	addi a7, zero, 5
	ecall
	add s0, zero, a0 #salva em t0 o valor digitado
	
	#solicita um inteiro
	#O serviço 5 continua em a7
	ecall
	add s1, zero, a0 #salva em t0 o valor digitado
	
	#falta fazer o swap
	add t0, zero, s0
	add s0, zero, s1
	add s1, zero, t0
	
