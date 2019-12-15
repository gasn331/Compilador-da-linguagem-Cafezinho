SOURCE= ./fonte
 
#Makefile

all: Temp cafezinho

cafezinho: cafezinho.tab.c lex.yy.c
	@ gcc -o cafezinho cafezinho.tab.c lex.yy.c -w
	@ mv cafezinho.tab.c lex.yy.c cafezinho.tab.h temp

cafezinho.tab.c: $(SOURCE)/cafezinho.y
	@ bison -d -v $(SOURCE)/cafezinho.y

lex.yy.c: $(SOURCE)/cafezinho.l
	@ flex $(SOURCE)/cafezinho.l

Temp:
	@ mkdir -p temp
