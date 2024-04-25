CC = g++
CFLAGS = -std=c++17
SRC = menu_despelgable.cpp fuerza_bruta.cpp auxiliares.cpp backtracking.cpp dp.cpp 
OBJ = $(SRC:.cpp=.o)
EXEC = pwl_fit

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC) 

