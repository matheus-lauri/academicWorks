####################################################################
# Exerc�cio 06 - 
# Mostra a compila��o de um la�o For
####################################################################
# Trecho em C:
#
# for (i==0; i<10; i++)
#     j++;
#
      .text   # segmento de c�digo (programa)
main:    
       addi s0, zero, 0     # i=0
Loop:  slti t0, s0, 10      # se i<10 ent�o $t0=1 sen�o $t0=0
       beq  t0, zero, Exit  # se $t0=0 ent�o goto Exit
       addi s1, s1, 1       # j++
       addi s0, s0, 1       # i++ (do la�o for)
       jal  zero, Loop      # goto Loop
Exit:  nop
