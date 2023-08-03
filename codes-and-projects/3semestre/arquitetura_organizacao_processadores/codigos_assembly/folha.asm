.text
	jal zero, main

folha:
	#nao precisaria utilizar a pilha nesse exemplo, pois é uma funcao folha, porém foi feito como exemplo
	addi sp, sp, -12 #desci uma posicao da pilha(utiliza o stack pointer "sp")
	sw t0, 8(sp) #coloquei o t0 na pilha(deslocado 8 posicoes, ficando o valor mais acima da pilha)
	sw t1, 4(sp) #coloquei o t1 na pilha(deslocado 4 posicoes, ficando o valor do meio da pilha)
	sw t2, 0(sp) #coloquei o t2 na pilha(deslocado 8 posicoes, ficando o valor mais embaixo da pilha)
	
	add t0, a0, a1
	add t1, a2, a3
	sub t2, t0, t1
	add a0, zero, t2
	
	lw t0, 8(sp) #desempilha
	lw t1, 4(sp) #desempilha
	lw t2, 0(sp) #desempilha
	addi sp, sp, 12 #ajusta a pilha
	
	jalr ra, 0 #comando literal para retornar

main:
	
	#inicio da chamada de funcao
	addi a0, zero, 0 #g
	addi a1, zero, 1 #h
	addi a2, zero, 2 #i
	addi a3, zero, 3 #j
	jal ra, folha #o registrador ra guarda o retorno
	#fim da chamada da funcao

