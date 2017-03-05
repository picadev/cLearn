
VPATH = ../include

main : test_main.o List.o 
	gcc  -w  -o   $@   $^  -g
test_main.o : test_main.c  List.h
	gcc  -w -c   $<  -g
List.o : List.c List.h
	gcc   -w  -c    $<  -g
.PHONY : clean
clean :	
	-rm  *.o

