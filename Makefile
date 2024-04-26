all: obj/Programa.o obj/Sequencia.o obj/Forca_Bruta.o obj/Prog_Dinamica.o obj/Tempo.o
	gcc obj/Programa.o obj/Sequencia.o obj/Forca_Bruta.o obj/Prog_Dinamica.o obj/Tempo.o -o Programa
	mv Programa bin/
	
obj/Programa.o: src/Programa.c
	gcc src/Programa.c -c
	mv Programa.o obj/

obj/Sequencia.o: src/Sequencia.c include/Sequencia.h
	gcc src/Sequencia.c -c
	mv Sequencia.o obj/

obj/Forca_Bruta.o: src/Forca_Bruta.c include/Forca_Bruta.h
	gcc src/Forca_Bruta.c -c 
	mv Forca_Bruta.o obj/

obj/Prog_Dinamica.o: src/Prog_Dinamica.c include/Prog_Dinamica.h
	gcc src/Prog_Dinamica.c -c 
	mv Prog_Dinamica.o obj

obj/Tempo.o: src/Tempo.c include/Tempo.h
	gcc src/Tempo.c -c 
	mv Tempo.o obj/
	
deletar:
	rm obj/*
	rm bin/*
