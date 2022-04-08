.EXPORT_ALL_VARIABLES:

LD_LIBRARY_PATH:=$$PWD;

compileAndExecute:
	gcc -std=c99 -Wall -Werror -fPIC -c vectorLL.c
	gcc -std=c99 -Wall -Werror -fPIC -c heap.c
	gcc -std=c99 -Wall -Werror -fPIC -c moreMath.c
	gcc -std=c99 -Wall -Werror -fPIC -c vectorPJ.c
	gcc -std=c99 -shared -fPIC -o libcompute.so moreMath.o vectorLL.o heap.o vectorPJ.o
	gcc -std=c99 main.c -lcompute -L. -o main
	./main
	
compile:
	gcc -std=c99 -Wall -Werror -fPIC -c vectorLL.c
	gcc -std=c99 -Wall -Werror -fPIC -c heap.c
	gcc -std=c99 -Wall -Werror -fPIC -c moreMath.c
	gcc -std=c99 -Wall -Werror -fPIC -c vectorPJ.c
	gcc -std=c99 -shared -fPIC -o libcompute.so vectorLL.o heap.o moreMath.o vectorPJ.o
	gcc -std=c99 main.c -lcompute -L. -o main

execute:
	./main

clear:
	rm -f ./main
	
clearAll:
	rm -f ./main
	rm -f ./a
	rm -f ./moreMath.o
	rm -f ./vectorLL.o
	rm -f ./vectorPJ.o
	rm -f ./heap.so
	rm -f ./libcompute.so