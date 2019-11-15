SOURCES = $(wildcard src/*.c)
COMPILER = gcc
FLAGS = -O0 -Wall

o: $(patsubst src/%.c, obj/%.o, $(SOURCES) )

obj/%.o: src/%.c $(SOURCES)
	$(COMPILER) $(FLAGS) -c -o $@ $<

main:
	$(COMPILER) $(FLAGS) $(SOURCES) -o roi
	
clear:
	rm -f obj/*.o
