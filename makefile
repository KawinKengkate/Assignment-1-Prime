compile: main.c 
	 gcc main.c -o gun

run: gun
	 ./gun

clean: gun
	 rm gun