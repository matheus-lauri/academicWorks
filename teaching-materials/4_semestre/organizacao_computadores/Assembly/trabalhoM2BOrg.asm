.data
	matriz_A: .word 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990
	matriz_B: .word 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	matriz_C: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
	
	solicitaTamanhoMatriz: .asciz "Entre com o tamanho do índice das matrizes (máx. = 10): "
	solicitaModoLeituraMatriz: .asciz "Entre com a forma com que as matrizes serão percorridas (‘0’ para linha-coluna e ‘1’ para coluna-linha): "
	linha: .asciz "\n"
	tab: .asciz "\t"
	invalido: .asciz "Valor inválido\n"
	
.text

jal zero, main

somaMatrizIJ:
	addi a4, zero, 10
	add t6, zero, a4 #pega a ordem da matriz e guarda em t6
	for_i:
		beq t0, t6, fim_i
		add t1, zero, zero #j=0
		for_j:
			beq t1, t6, fim_j
			#calculo da posição das matrizes
			mul t2, t0, t6 #t2 = linha*ordem 
			slli t2, t2, 2 # 4*t2
			slli t3, t1, 2 # 4*j
			add t4, t2, t3  
			add t5, t4, a1 #matriz_A[t2][t3]
			lw a0, 0(t5)   #a0 = matriz_A[t2][t3]
			#salvando o valor [i][j] da matriz_A
			add a5, zero, a0
			
			add t5, t4, a2 #matriz_B[t2][t3]
			lw a0, 0(t5)   #a0 = matriz_B[t2][t3]
			#salvando o valor [i][j] da matriz_B
			add a6, zero, a0
			
			#somando matriz_A e matriz_B
			add a6, a6, a5			
			
			add t5, t4, a3 #matriz_C[t2][t3]
			sw a6, 0(t5)   #matriz_C[t2][t3] = a6
			
			addi t1, t1, 1 #j++
			jal zero, for_j
		fim_j:
		
			addi	 t0, t0, 1 #i++
			jal zero, for_i
	fim_i:
		#jalr ra, zero, 0
		jal zero, fim
	
somaMatrizJI:
	addi a4, zero, 10
	add t6, zero, a4 #pega a ordem da matriz e guarda em t6
	for_j2:
		beq t0, t6, fim_j2 #j == t6 va para fim_j
		add t1, zero, zero #i=0
		for_i2:
			beq t1, t6, fim_i2 # i == t6 => va para fim_i
			#calculo da posição da matriz_A
			mul t2, t1, t6 #t2 = linha*ordem 
			slli t2, t2, 2 # 4*t2
			slli t3, t0, 2 # 4*j
			add t4, t2, t3 # t2+t3
			add t5, t4, a1 #m[t3][t2]
			lw a0, 0(t5)   #a0 = m[t3][t2]
			#salvando o valor [j][i] da matriz_A
			add a5, zero, a0
			
			add t5, t4, a2 #matriz_B[t3][t2]
			lw a0, 0(t5)   #a0 = matriz_B[t3][t2]
			#salvando o valor [j][i] da matriz_B
			add a6, zero, a0
			
			#somando matriz_A e matriz_B
			add a6, a6, a5
			
			add t5, t4, a3 #matriz_C[t3][t2]
			sw a6, 0(t5)   #matriz_C[t3][t2] = a6
		
			addi t1, t1, 1 #i++
			jal zero, for_i2
	fim_j2:
		jal zero, fim #termina de percorrer a matriz e vai para fim
		
	fim_i2:		
		addi t0, t0, 1 #j++
		jal zero, for_j2

imprimeErroEntradaTamanhoMatriz:
	#Imprime "Valor inválido"
	addi    a7, zero, 4
	la    a0, invalido
	ecall
	jal zero, entradaTamanhoMatriz
	
imprimeErroEntradaModoLeituraMatriz:
	#Imprime "Valor inválido"
	addi    a7, zero, 4
	la    a0, invalido
	ecall
	jal zero, entradaModoLeituraMatriz

main:
	
	addi s0, zero, 2 #utilizando s0 como variavel para o valor 2
	addi s1, zero, 10 #utilizando s1 como variavel para o valor 10
	addi s2, zero, 1 #utilizando s2 como variavel para o valor 1
	
	entradaTamanhoMatriz:
		#Imprime "Entre com o tamanho do índice das matrizes (máx. = 10): "
	    	addi    a7, zero, 4
	    	la    a0, solicitaTamanhoMatriz
	    	ecall
	    	#Le inteiro de resposta
	    	addi    a7, zero, 5
	    	ecall
	    	#Verifica se o tamanho da matriz e > 1 e <=10 
	    	blt a0, s0, imprimeErroEntradaTamanhoMatriz
	    	bgt a0, s1, imprimeErroEntradaTamanhoMatriz
	    	#Salvando a ordem da matriz no a4
	    	add a4, zero, a0
	    	#carrega as matrizes
	    	la a1, matriz_A 
	    	la a2, matriz_B
	    	la a3, matriz_C
	
	entradaModoLeituraMatriz:
		#Imprime "Entre com a forma com que as matrizes serão percorridas (‘0’ para linha-coluna e ‘1’ para coluna-linha): "
	    	addi a7, zero, 4
	    	la a0, solicitaModoLeituraMatriz
	    	ecall
	    	#Le inteiro de resposta
	    	addi a7, zero, 5
	    	ecall
	    	#Verifica se a resposta foi escrita corretamente (‘0’ para linha-coluna e ‘1’ para coluna-linha)	
		beq a0, zero, somaMatrizIJ
		beq a0, s2, somaMatrizJI
		blt a0, zero, imprimeErroEntradaModoLeituraMatriz
		bgt a0, s2, imprimeErroEntradaModoLeituraMatriz
	
fim:	
    	#Finaliza programa
    addi    a7, zero, 10
    ecall
