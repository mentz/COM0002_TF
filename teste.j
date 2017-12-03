.class public teste
.super java/lang/Object

.field static private s Ljava/lang/String;

.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 10
	.limit locals 6
	ldc "teste atribuição de string\n\t\tolamundo com 2 tabs"
	putstatic teste/s Ljava/lang/String;
	bipush 7
	istore 3
	iconst_0
	istore 2
	iconst_0
	istore 1
	ldc 1.500000
	fstore 4
  l1:
	iload 1
	iload 3
	if_icmplt l2
	goto l3
  l2:
	iload 2
	iconst_1
	iadd
	istore 2
	iload 1
	iconst_1
	iadd
	istore 1
	fload 4
	fload 4
	fmul
	fstore 4
	goto l1
  l3:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 2
	invokevirtual java/io/PrintStream/println(I)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	fload 4
	invokevirtual java/io/PrintStream/println(F)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic teste/s Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
