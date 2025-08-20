# Compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iincludes

# Carpeta de fuentes
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/biblioteca.cpp \
      $(SRC_DIR)/fecha.cpp \
      $(SRC_DIR)/funcione.cpp \
      $(SRC_DIR)/libro.cpp \
      $(SRC_DIR)/usuario.cpp

# Archivos objeto
OBJ = $(SRC:.cpp=.o)

# Ejecutable
TARGET = biblioteca

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Cómo compilar cada archivo .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar objetos y ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
