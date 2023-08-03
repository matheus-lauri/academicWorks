#for (i = 0; i < 10; i++)
#cout << i;

.data

.text

	add t0, zero, zero #i = 0
	addi s10, zero, 10

for1:
	bge t0, s10, endfor1 #desvia na condicao oposta do laco for do c++
		addi a7, zero, 1
		add a0, zero, t0
		ecall #cout << i
		
		addi t0, t0, 1 #i++
	
	j for1 
	
endfor1: 	