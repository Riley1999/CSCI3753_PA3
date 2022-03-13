	.file	"max_name_length.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Please enter a file name...\12\0"
.LC1:
	.ascii "Attempting to open %s...\12\0"
.LC2:
	.ascii "Failed to open file.\12\0"
.LC3:
	.ascii "%c\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movl	$54144, %eax
	call	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc	54144
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, 54032(%rbp)
	movq	%rdx, 54040(%rbp)
	call	__main
	movl	$0, 54008(%rbp)
	movq	54040(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L4
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$1, %eax
	jmp	.L9
.L4:
	movq	54040(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$0, 54004(%rbp)
	movq	54040(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	open
	movl	%eax, 54004(%rbp)
	cmpl	$-1, 54004(%rbp)
	jne	.L6
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$1, %eax
	jmp	.L9
.L6:
	leaq	-96(%rbp), %rdx
	movl	54004(%rbp), %eax
	movl	$6762, %r8d
	movl	%eax, %ecx
	call	read
	movl	%eax, 54000(%rbp)
	movl	54000(%rbp), %eax
	cltq
	movq	$0, -96(%rbp,%rax,8)
	movl	$0, 54012(%rbp)
	jmp	.L7
.L8:
	movl	54012(%rbp), %eax
	cltq
	movq	-96(%rbp,%rax,8), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	printf
	addl	$1, 54012(%rbp)
.L7:
	movl	54012(%rbp), %eax
	cmpl	54000(%rbp), %eax
	jl	.L8
	movl	$0, %eax
.L9:
	addq	$54144, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev5, Built by MSYS2 project) 10.3.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	open;	.scl	2;	.type	32;	.endef
	.def	read;	.scl	2;	.type	32;	.endef
