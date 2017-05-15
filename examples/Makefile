edit : main.o kbd.o command.o display.o
    g++ -o edit main.o kbd.o command.o display.o

main.o : main.c defs.h
    g++ -c main.c
kbd.o : kbd.c defs.h command.h
    g++ -c kbd.c
command.o : command.c defs.h command.h
    g++ -c command.c
display.o : display.c defs.h
    g++ -c display.c

clean :
    rm edit main.o kbd.o command.o display.o