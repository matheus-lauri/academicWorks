# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Programa 02
# Grupo: - Matheus Baron Lauritzen
#        - Gustavo Baron Lauritzen
#        - Gabriel Bosio

.data
	mensagemAula: .asciz "\nEntre com o número da aula (de 0 a 15):"
	mensagemAluno: .asciz "\nEntre com o número do aluno (de 0 a 31):"
	mensagemRegistro: .asciz "\nEntre com o tipo do registro (presença = 1; ausência = 0):"
	mensagemMascara: .asciz "\nMascara do dia ["
	mensagemMascara2: .asciz "]: "

	# Define o vetor com 16 elementos inicializados com todos os bits em 1
	vetor: .word 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
	       0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
	       0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
    	   0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF

	

.text
	la s1, vetor #endereço base do vetor com 16 elementos 0xFFFFFFFF

	xori t6, zero, -1 # registrador com tudo 1
	
	addi s10, zero, 0

loop1:
	
    # Exibe mensagem solicitando o número da aula
    addi a7, zero, 4          
    la a0, mensagemAula    
    ecall                   

    # Lê o número da aula
    addi a7, zero, 5          
    ecall                   
    add s2, zero, a0          
	
    # Exibe mensagem solicitando o número do aluno
    addi a7, zero, 4          
    la a0, mensagemAluno   
    ecall                   

    # Lê o número do aluno
    addi a7, zero, 5          
    ecall                   
    add s3, zero, a0          

    # Exibe mensagem solicitando o tipo de registro
    addi a7, zero, 4         
    la a0, mensagemRegistro    
    ecall                   
    # Lê o tipo de registro
    addi a7, zero, 5          
    ecall                   
    add s4, zero, a0     
	
	#Percorre o array ate chegar na posicao(aula) que o user mandou
	slli t1, s2, 2 
	add s7, s1, t1
	#pega a mascara original e coloca no t2 
	lw t2, 0(s7) 
    
    #Desloca o valor t3=1 em s3=aluno posicoes na mascara
    addi t3, zero, 1         
    sll t4, t3, s3
    #invertendo todos os bits da máscara e aplicando no t5
    xor t5, t4, t6
    
    DesligaBit:
    	bne s4, zero, LigaBit 
    	#desliga bit
    	and t2, t2, t5
    	jal zero, fimOperacaoBit
    LigaBit:
    	xor t5, t5, t6
    	#liga bit
    	or t2, t2, t5
    	jal zero, fimOperacaoBit
    
    fimOperacaoBit:
    
    # Exibe mensagem da mascara
    addi a7, zero, 4          
    la a0, mensagemMascara    
    ecall  
    
    # Exibe numero da aula
	addi a7, zero, 1
	add a0, zero, s2
	ecall 
	
	# Exibe mensagem 2 da mascara
    addi a7, zero, 4          
    la a0, mensagemMascara2    
    ecall
    
    # Exibe a mascara modificada
	addi a7, zero, 1
	add a0, zero, t2
	ecall 
    
    #Armazena a mascara original modificada na posicao do vetor
    sw t2, 0(s7)
    
    # Volta para o início do loop
    jal zero, loop1
