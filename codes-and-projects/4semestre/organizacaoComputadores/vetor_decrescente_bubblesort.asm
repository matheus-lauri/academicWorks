#hazard01: código com conflito de dados ao considerar execução em pipeline
## VETOR DECRESCENTE COM BUBBLE SORT ##
#    int v[8]={1,2,3,4,5,6,7,8};
#    int temp;
#    for (int i=0; i<7; i++) {
#        for (int j=0; j<7; j++) {
#            if ( v[j+1]>v[j] ) {
#                temp=v[j];
#                v[j]=v[j+1];
#                v[j+1]=temp;
#            }
#        }
#    }
.data
	v: .word 1,2,3,4,5,6,7,8
.text
	la 		s0, v
	addi	s7, zero, 7 #tamanho vetor -1 = 7

## ORDENA VETOR DECRESCENTE ##
	addi	t0, zero, 0 # i=0
fori:
	beq		t0, s7, fim_fori
	addi	t1, zero, 0 # j=0
	forj:
		beq		t1, s7, fim_forj
		slli 	t2, t1, 2 #4*j
		add 	t2, t2, s0 #4*j + endereço base
		addi    t3, t2, 4 #4*j + endereço base + 4 (próxima instrução)
		lw 		t4, 0(t2) #t4=vetor[i]
		lw 		t5, 0(t3) #t5=vetor[i+1]
		ble		t5, t4, fim_if #if ( v[j+1]>v[j] )
			sw t5, 0(t2) #inverte
			sw t4, 0(t3) #inverte
		fim_if:
		addi	t1, t1, 1 #j++
		jal 	zero, forj
	fim_forj:
	addi	t0, t0, 1 #i++
	jal 	zero, fori
fim_fori:



fim_programa:
	addi 	a7, zero, 10
	ecall