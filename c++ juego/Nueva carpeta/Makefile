# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -Wall -Wextra -std=c++17 -g -I includes

# Detectar automáticamente todos los .cpp en src/
SRC = $(wildcard src/*.cpp)

# Generar los nombres de los objetos correspondientes
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
TARGET = combate

# Regla principal
all: $(TARGET)

# Cómo generar el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Cómo compilar cada .cpp a .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Limpiar todo incluyendo backups
mrproper: clean
	rm -f *~
