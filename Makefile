CC=	gcc
LIBRARIES= -lpthread -ldl

all:Input_validation_main.o argument_check.o operation_execution.o database.o validation.o
	$(CC) -o inputvalidation Input_validation_main.o argument_check.o operation_execution.o database.o validation.o sqlite3.c $(LIBRARIES)

Input_validation_main.o:Input_validation_main.c
	$(CC) -c Input_validation_main.c
	
argument_check.o:argument_check.c
	$(CC) -c argument_check.c
	
operation_execution.o:operation_execution.c
	$(CC) -c operation_execution.c
	
database.o:database.c
	$(CC) -c database.c
	
validation.o:validation.c
	$(CC) -c validation.c
	
clean:
	rm -f *.o inputval