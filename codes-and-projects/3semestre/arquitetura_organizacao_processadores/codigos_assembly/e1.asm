
.data
	ex: .asciz "Entre com o valor de X: "
	ey: .asciz "Entre com o valor de Y: "
	xy: .asciz "A soma de X e Y é igual a: "
	
.text
	#escreve texto
	addi a7, zero, 4
	la a0, ex
	ecall
	
	#ler texto
	addi a7, zero, 5
	ecall
	add s0, zero, a0 # x está no s0
	
	#escreve texto
	addi a7, zero, 4
	la a0, ey
	ecall
	
	#ler texto
	addi a7, zero, 5
	ecall
	add s1, zero, a0 # y está no s1
	
	#fazer a soma de x+y
	add s2, s0, s1 
	
	#escreve texto
	addi a7, zero, 4
	la a0, xy
	ecall
	
	#escreve texto
	addi a7, zero, 1
	add a0, zero, s2
	ecall
	
