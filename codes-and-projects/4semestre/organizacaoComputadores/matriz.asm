.data
	matriz: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
	solicita: .asciz "Informe a ordem da matriz: "	
	linha: .asciz "\n"
	tab: .asciz "\t"
	
.text
jal zero, main

imprime_matriz:
	add t6, zero, a0
	for_i:
		beq t0, t6, fim_i
		add t1, zero, zero #j=0
		for_j:
			beq t1, t6, fim_j
			#calculo da posição da matriz
			mul t2, t0, t6 #t2 = linha*ordem 
			slli t2, t2, 2 # 4*t2
			slli t3, t1, 2 # 4*j
			add t4, t2, t3  
			add t5, t4, a1 #m[t2][t3]
			lw a0, 0(t5)   #a0 = m[t2][t3]
			
			#imprime
			addi a7, zero, 1
			ecall
			#imprime tabulação
			addi a7, zero, 4
			la a0, tab
			ecall
		
			addi t1, t1, 1 #j++
			jal zero, for_j
		fim_j:
		#imprime pula linha
		addi a7, zero, 4
		la a0, linha
		ecall
		
		addi t0, t0, 1 #i++
		jal zero, for_i
	fim_i:
	jalr ra, zero, 0
	
main:
	#Imprime string
	addi a7, zero, 4
	la a0, solicita
	ecall
	
	#Le inteiro
	addi a7, zero, 5
	ecall
	
	#a0, contém a ordem da matriz
	la a1, matriz
	jal ra, imprime_matriz
	
	
	#Finaliza programa
	addi a7, zero, 10
	ecall