# int fib (int n) {
#	if (n <=2) {
#		return 1; }
#	return fib(n-1) + fib(n-2);
#}
	jal zero, main

fib:
	#empilha
	addi sp, sp, -8
	sw a0, 4(sp)
	sw ra, 0(sp)
	addi t0, zero, 2
	bgt a0, t0, else #if(n<=2)
	addi a2, a2, 1 #soma dos valores
	
	#desempilha
	lw a0, 4(sp)
	lw ra, 0(sp)
	addi sp, sp, 8
	#chamada de return	
	jalr ra, 0
else:
	addi a0, a0, -1
	
	jal ra, fib #fib fib(n-1) 
	
	addi a0, a0, -1 #fib(n-2)
	
	
	jal ra, fib
	
	#desempilha
	lw a0, 4(sp)
	lw ra, 0(sp)
	addi sp, sp, 8
	
	#chamada de return	
	jalr ra, 0
	




main:
	#fib 1  2  3  4  5  6  7   8   9   10
	#fib 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
	addi a0, zero, 8
	jal ra, fib

