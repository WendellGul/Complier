.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text

read:
li $v0, 4
la $a0, _prompt
syscall
li $v0, 5
syscall
jr $ra

write:
li $v0, 1
syscall
li $v0, 4
la $a0, _ret
syscall
move $v0, $0
jr $ra

fact:
addi $sp, $sp, -16
sw $a0, 0($sp)
lw $t0, 0($sp)
li $t1, 1
beq $t0, $t1, label0
j label1
label0:
li $t0, 1
move $v0, $t0
addi $sp, $sp, 16
jr $ra
j label2
label1:
lw $t0, 0($sp)
li $t1, 1
sub $t0, $t0, $t1
sw $t0, 4($sp)
lw $t0, 4($sp)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal fact
lw $ra, 0($sp)
addi $sp, $sp, 4
sw $v0, 8($sp)
lw $t0, 0($sp)
lw $t1, 8($sp)
mul $t0, $t0, $t1
sw $t0, 12($sp)
lw $t0, 12($sp)
move $v0, $t0
addi $sp, $sp, 16
jr $ra
label2:

main:
addi $sp, $sp, -8
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
sw $v0, 0($sp)
lw $t0, 0($sp)
li $t1, 1
bgt $t0, $t1, label3
j label4
label3:
lw $t0, 0($sp)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal fact
lw $ra, 0($sp)
addi $sp, $sp, 4
sw $v0, 4($sp)
j label5
label4:
li $t0, 1
sw $t0, 4($sp)
label5:
lw $t0, 4($sp)
move $a0, $t0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
li $t0, 0
move $v0, $t0
addi $sp, $sp, 8
jr $ra
