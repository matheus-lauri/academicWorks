.data
	texto1: .asciz "Informe a posi��o: "

.text
	#registrador com tudo 1
	xori t0, zero, -1
	
	#pergunta a posi��o para o user
	addi a7, zero, 4
	la a0, texto1
	ecall
	
	#l� a posi��o informada
	addi a7, zero, 5
	ecall
	
	#registrador com o valor 1
	addi t1, zero, 1
	
	#desloca o t1 para esquerda o
	#o n�mero de posi��es informada
	sll s0, t1, a0
	
	#inverte o s0
	xori s0, s0, -1
	
	and s1, t0, s0