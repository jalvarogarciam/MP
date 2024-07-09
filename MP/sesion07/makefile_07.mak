################################################################
#
# MP
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: sesion07.
#
################################################################

HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

all: \
	preambulo \
	ejecutables \
	$(BIN)/II_Demo-Matriz2D \
	fin-ejecutables

preambulo:
	@echo
	@echo -----------------------------------------------------------
	@echo MP
	@echo José Álvaro García Márquez
	@echo Ingeniería Técnica Informática 1ºB grupo 1
	@echo Universidad de Granada
	@echo -----------------------------------------------------------
	@echo
ejecutables:
	@echo
	@echo Creando ejecutables...
fin-ejecutables:
	@echo
	@echo ...Ejecutables creados
	@echo

#ejecutables
#..............................................................................
$(BIN)/II_Demo-Matriz2D : $(OBJ)/II_Demo-Matriz2D.o \
								$(LIB)/libMatriz2D.a \

	@echo
	@echo Creando ejecutable: II_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/II_Demo-Matriz2D $(OBJ)/II_Demo-Matriz2D.o \
	-lMatriz2D -L$(LIB)


#Objetos main
#..............................................................................
$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
								  $(INCLUDE)/Matriz2D.h $(INCLUDE)/TipoBase.h
	@echo
	@echo Creando objeto: II_Demo-Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o $(SRC)/II_Demo-Matriz2D.cpp\
			 -I$(INCLUDE) -std=c++11




#Objetos utils
#..............................................................................
$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase.h $(INCLUDE)/utils.h
	@echo
	@echo Creando objeto: Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp \
				-I$(INCLUDE) -std=c++11

$(OBJ)/utils.o : $(SRC)/utils.cpp $(INCLUDE)/utils.h $(INCLUDE)/TipoBase.h
	@echo
	@echo Creando objeto: utils.o
	@echo
	g++ -c -o $(OBJ)/utils.o $(SRC)/utils.cpp -I$(INCLUDE) -std=c++11

#Bibliotecas
#..............................................................................
$(LIB)/libMatriz2D.a: $(OBJ)/Matriz2D.o $(OBJ)/utils.o
	@echo
	@echo Creando biblioteca: libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a $(OBJ)/Matriz2D.o $(OBJ)/utils.o



#Limpieza
#..............................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/II_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/utils.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/II_Demo-Matriz2D
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libMatriz2D.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
