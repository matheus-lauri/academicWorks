#int mdc_recursivo(int a, int b) {
#    if(a==b){
#        return a;
#    }
#    if(a>b){
#        return mdc_recursivo(a-b, b);
#    } else{
#        return mdc_recursivo(a, b-a);
#    }
#}

#Desenvolvido por Gustavo Baron Lauritzen e Matheus Baron Lauritzen
.data

	mensagemA: .asciz "Digite um número inteiro positivo para o valor de A:\n"
	mensagemB: .asciz "Digite um número inteiro positivo para o valor de B:"
    resultado: .asciz "O MDC é: "

.text

	jal zero, main
	
mdc:	
	addi sp, sp, -4 #empilha
	lw ra, 0(sp)
	beq a0, a1, fim
	
	blt a0, a1, menor #if (a > b)
	
	sub, a0, a0, a1 #diminui a0
	jal ra, mdc
	
menor:	
	sub a1, a1, a0 #dimnui a1
	jal ra, mdc 
	
	
fim:
	lw ra, 0(sp) #desempilha
	addi sp, sp, 4
	jalr ra, 0 #retorna

main:

	#addi a7, zero, 4
	#la a0, mensagemA
	#ecall
	
	#addi a7, zero, 5
	#ecall
	#add a1, zero, a3 #salva o valor digitado em a1
	
	#addi a7, zero, 4
	#la a0, mensagemB
	#ecall
	
	#addi a7, zero, 5
	#ecall
	#add a2, zero, a3 #salva o valor digitado em a2
	
	#addi a0, zero, 0
	#addi a3, zero, 0
	#addi a7, zero,0
	
	addi a0, zero, 4
	addi a1, zero,2
	jal ra, mdc	#chama a função
	