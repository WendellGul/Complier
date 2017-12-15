# My C-- Complier Help Doc

[TOC]

## 1. 用法

使用`make`产生可执行文件*complier.exe*

使用`complier.exe -h` 获取帮助

最终输出语法树，目标代码以及汇编代码

*test.c*和*test_fact.c*为测试代码

## 2. 文法定义

### Tokens

> 运算符和分隔符

1. TK_PLUS ::= `+`
2. TK_MINUS ::= `-`
3. TK_STAR ::= `*`
4. TK_DIVIDE ::= `/`
5. TK_MOD ::= `%`
6. TK_EQ ::= `==`
7. TK_NEQ ::= `!=`
8. TK_LT ::= `<`
9. TK_LEQ ::= `<=`
10. TK_GT ::= `>`
11. TK_GEQ ::= `>=`
12. TK_ASSIGN ::= `=`
13. TK_DOT ::= `.`
14. TK_AND ::= `&&`
15. TK_OR ::= `||`
16. TK_NOT ::= `!`
17. TK_LP ::= `(`
18. TK_RP ::= `)`
19. TK_LB ::= `[`
20. TK_RB ::= `]`
21. TK_BEGIN ::= `{`
22. TK_END ::= `}`
23. TK_SEMI ::= `;`
24. TK_COMMA ::= `,`
25. TK_EOF ::= `END OF FILE`

> 常量

1. TK_CINT ::= `CONST INT`
2. TK_CFLOAT ::= `CONST FLOAT`
3. TK_CCHAR ::= `CONST CHAR`
4. TK_CSTR ::= `CONST STRING`

> 关键字

1. KW_CHAR ::= `char`
2. KW_INT ::= `int`
3. KW_FLOAT ::= `float`
4. KW_STRUCT ::= `struct`
5. KW_RETURN ::= `return`
6. KW_IF ::= `if`
7. KW_ELSE ::= `else`
8. KW_FOR ::= `for`
9. KW_CONTINUE ::= `continue`
10. KW_BREAK ::= `break`

> 标识符

1. TK_ID ::= `IDENTIFIER`



### High-level Definitions

>  	这部分包含全局变量及函数定义的语法，**Program**是初始语法单元，表示整个程序。每个**Program**可以产生一个**ExtDefList**，每个**ExtDefList**表示0个或多个**ExtDef**，每个**ExtDef**表示一个全局变量、结构体、函数的定义或函数的声明

1. Program ::= ExtDefList

2. ExtDefList ::= ExtDef ExtDefList

   ​	| ε

3. ExtDef ::= Specifier ExtDecList TK_SEMI

   ​	| Specifier TK_SEMI

   ​	| Specifier FunDec CompSt

   ​	| Specifier FunDec TK_SEMI

4. ExtDecList ::= VarDec

   ​	| VarDec TK_COMMA ExtDecList

### Specifiers

> ​	这部分主要与变量的类型有关，包括普通类型`int`、`char`、`float`和结构体类型

1. Specifier ::= Type

   ​	| StructSpecifier

2. Type ::= KW_INT| KW_FLOAT| KW_CHAR

3. StructSpecifier ::= KW_STRUCT OptTag TK_BEGIN DefList TK_END

   ​	| KW_STRUCT TK_ID

4. OptTag ::= TK_ID

   ​	| ε

### Declarators

> ​	这一部分主要与变量和函数的定义有关，**VarDec**表示对一个变量的定义，**FunDec**表示对一个函数头的定义

1. VarDec ::= TK_ID

   ​	| VarDec TK_LB TK_CINT TK_RB

2. FunDec ::= TK_ID TK_LP ParamList TK_RP

   ​	| TK_ID TK_LP TK_RP

3. ParamList ::= ParamDec TK_COMMA ParamList

   ​	| ParamDec

4. ParamDec ::= Specifier VarDec

### Statements

> ​	这一部分主要与语句有关，**CompSt**表示一个由一对花括号括起来的语句块，**StmtList**是个或多个**Stmt**的组合，每个**Stmt**都表示一个语句

1. CompSt ::= TK_BEGIN DefList StmtList TK_END

2. StmtList ::= Stmt StmtList

   ​	| ε

3. Stmt ::= Expression TK_SEMI

   ​	| CompSt

   ​	| KW_RETURN Expression TK_SEMI

   ​	| KW_IF TK_LP Expression TK_RP Stmt

   ​	| KW_IF TK_LP Expression TK_RP Stmt KW_ELSE Stmt

   ​	| KW_FOR TK_LP Expression TK_SEMI Expression TK_SEMI Expression TK_RP Stmt


### Local Definitions

> ​	这一部分主要与局部变量的定义有关，**DefList**由0个或多个**Def**组成，每个**Def**就是一条变量定义，它包含一个类型描述符**Specifier**和一个**DecList**

1. DefList ::= Def DefList

   ​	| ε

2. Def ::= Specifier DecList TK_SEMI

3. DecList ::= Dec

   ​	| Dec TK_COMMA DecList

4. Dec ::= VarDec

   ​	| VarDec TK_ASSIGN Expression

### Expressions

> ​	这一部分主要与表达式有关，包含二元运算符的表达式（赋值表达式、逻辑表达式、关系表达式以及四则运算表达式）、一元运算符的表达式（括号表达式，取负以及逻辑非）、不包含运算符的表达式（函数调用表达式、数组访问表达式以及结构体访问表达式）和最基本的表达式（整型常数、浮点型常数、字符型常量、字符串常量以及普通变量），**Args**表示实参列表。

1. Expression ::= Expression TK_ASSIGN Expression

   ​	| Expression TK_AND Expression

   ​	| Expression TK_OR Expression

   ​	| Expression RelOp Expression

   ​	| Expression TK_PLUS Expression

   ​	| Expression TK_MINUS Expression

   ​	| Expression TK_STAR Expression

   ​	| Expression TK_DIVIDE Expression

   ​	| TK_LP Expression TK_RP

   ​	| TK_MINUS Expression

   ​	| TK_NOT Expression

   ​	| TK_ID TK_LP Args TK_RP

   ​	| TK_ID TK_LP TK_RP

   ​	| Expression TK_LB Expression TK_RB

   ​	| Expression TK_DOT TK_ID

   ​	| TK_ID

   ​	| TK_CINT

   ​	| TK_CFLOAT

   ​	| TK_CCHAR

   ​	| TK_CSTR

2. RelOp ::= TK_LT | TK_LEQ | TK_EQ | TK_GT | TK_GEQ | TK_NEQ

3. Args ::= Expression TK_COMMA Args

   ​	| Expression

--------

## 3. 语义错误类型

1. Undefined variable;
2. Undefined function;
3. Redefined variable;
4. Redefined function;
5. Type mismatched for assignment;
6. The left-hand side of an assignment must be a variable;
7. Type mismatched for operands;
8. Type mismatched for return;
9. Unmatched parameters for function;
10. Symbol is not an array;
11. Symbol is not a function;
12. Type of expression between "[]" should be INT;
13. Illegal use of ".";
14. Non-existent field of a structure;
15. Redefined structure field;
16. Redefined structure;
17. Undefined structure;
18. Redefined parameter of function;
19. Only INT can be use as boolean in a condition statement;
20. Can not initialize a field while defining the structure;
21. Only INT can use "!"(not);
22. Only INT or FLOAT can use "-"(minus);
23. Array dimension error;