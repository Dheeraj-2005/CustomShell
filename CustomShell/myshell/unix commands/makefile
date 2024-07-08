assignment: ls.o system.o mv.o cp.o mygrep.o
	gcc ls.o system.o mv.o cp.o mygrep.o -o assignment -lreadline
ls.o: ls.c 
	gcc -c ls.c -o ls.o -lreadline
system.o: system.c 
	gcc -c system.c -o system.o -lreadline
mv.o: mv.c 
	gcc -c mv.c -o mv.o -lreadline
cp.o: cp.c 
	gcc -c cp.c -o cp.o -lreadline
mygrep.o: mygrep.c 
	gcc -c mygrep.c -o mygrep.o -lreadline
