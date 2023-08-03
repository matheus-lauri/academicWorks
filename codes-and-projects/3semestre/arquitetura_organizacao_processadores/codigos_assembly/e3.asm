.data
	lv: .asciz "LEITURA DOS ELEMENTOS DO VETOR: \n"
	ia: .asciz "Entre com A["
	fa: .asciz "] = "
	va: .word 0,0,0,0,0,0,0,0
	av: .asciz "APRESENTAÇÃO DO VETOR LIDO: \n"
	ia2: .asciz "\nA["
.text
	add t0, zero, zero #i=0
	addi s8, zero, 8
	
	la s1, va #endereço base do vetor a

	#imprime texto
	addi a7, zero, 4
	la a0, lv
	ecall
for1: 
	bge t0, s8, endfor1
		#imprime Entre com A[
		addi a7, zero, 4
		la a0, ia
		ecall
		
		#imprime o indice 
		addi a7, zero, 1
		add a0, zero, t0
		ecall 
		
		#imprime ] = 
		addi a7, zero, 4
		la a0, fa
		ecall
		
		#ler inteiro
		addi a7, zero, 5
		ecall
		add s0, zero, a0 # x está no s0
		
		#guarda no vetor
		slli t1, t0, 2  #t1 = 4*i
		add s2, s1, t1 #s2 = base+deslocamento
		sw s0, 0(s2)
		
		addi t0, t0, 1 #i++
	
	#j for1 #teste
	jal zero, for1
endfor1:

	#imprime texto
	addi a7, zero, 4
	la a0, av
	ecall

	add t0, zero, zero
for2: 
	bge t0, s8, endfor2
		#imprime A[
		addi a7, zero, 4
		la a0, ia2
		ecall
		
		#imprime o indice 
		addi a7, zero, 1
		add a0, zero, t0
		ecall 
		
		#imprime ] = 
		addi a7, zero, 4
		la a0, fa
		ecall
		
		#ler do vetor
		slli t1, t0, 2  #t1 = 4*i
		add s2, s1, t1 #s2 = base+deslocamento
		lw a0, 0(s2)
		
		#imprime valor do vetor 
		addi a7, zero, 1
		ecall 
		
		addi t0, t0, 1 #i++
	
	jal zero, for2 #teste
endfor2:
