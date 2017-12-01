.class public FelizNatalCristiano
.super java/lang/Object

.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
	.limit stack 10
	.limit locals 3
	iconst_5
	istore 2
	iconst_1
	istore 1
  l1:
	iload 2
	iconst_0
	if_icmpgt l2
	goto l3
  l2:
	iload 1
	iload 2
	imul
	istore 1
	iload 2
	iconst_1
	isub
	istore 2
	goto l1
  l3:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 1
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
