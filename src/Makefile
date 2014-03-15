CC=g++
CFLAGS=-Wall -ansi -pedantic -Wextra
LDFLAGS=
DFLAGS=-O3
EXEC=main
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)

makefile.dep: *.cpp
	$(CC) -MM $(SRC) > $@
  
.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

include makefile.dep

