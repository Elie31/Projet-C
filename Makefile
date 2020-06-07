#commande compilation : make compile
compile: fonction.c
	gcc fonction.c -o fonction

#commande execution : make execute
execute:
	./fonction


