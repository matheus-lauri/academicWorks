.text
jal zero, main

fat_rec:
		addi sp,sp,-8	    # atualiza sp (push 2 itens)
		sw   ra,0(sp)	    # - push ra
		sw   a0,4(sp)	    # - push a0
		addi t0,zero,1	    # testa se n<1
		bgt  a0,t0,ret_n1   # se n>1, desvia para ret_n1
		addi a1,zero,1      # retorna o valor 1
		jalr ra, 0          # retorna para depois de jal

ret_n1:	
		addi a0,a0,-1	    # n>=1, a0 = n-1
		jal  fat_rec	    # chama fat_rec(n-1)
		lw   ra,0(sp)	    # - pop ra
		lw   a0,4(sp)	    # - pop a2  (ou seja, n)
		mul  a1,a1,a0       # retorna n*fact(n-1)
		addi sp,sp,8        # atualiza sp (pop 2 itens)
		jalr   ra, 0        # retorna para o chamador

main:
	addi a0, zero, 5
	jal ra, fat_rec
