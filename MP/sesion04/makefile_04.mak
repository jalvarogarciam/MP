################################################################
#
# MP
#
# José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: Entrega práctica 4.
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
	$(BIN)/I_DemoMiCadenaClasica \
	$(BIN)/I_EncuentraInicioPalabras \
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
#.....................................................................................................................
$(BIN)/I_DemoMiCadenaClasica : $(OBJ)/I_DemoMiCadenaClasica.o $(LIB)/libMiCadenaClasica.a
	@echo
	@echo Creando ejecutable: I_DemoMiCadenaClasica
	@echo
	g++ -o $(BIN)/I_DemoMiCadenaClasica $(OBJ)/I_DemoMiCadenaClasica.o -lMiCadenaClasica -L$(LIB)

$(BIN)/I_EncuentraInicioPalabras : $(OBJ)/I_EncuentraInicioPalabras.o $(LIB)/libMiCadenaClasica.a
	@echo
	@echo Creando ejecutable: I_EncuentraInicioPalabras
	@echo
	g++ -o $(BIN)/I_EncuentraInicioPalabras $(OBJ)/I_EncuentraInicioPalabras.o -lMiCadenaClasica -L$(LIB)


#Objetos main
#.....................................................................................................................
$(OBJ)/I_DemoMiCadenaClasica.o : $(SRC)/I_DemoMiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo
	@echo Creando objeto: I_DemoMiCadenaClasica.o
	@echo
	g++ -c -o $(OBJ)/I_DemoMiCadenaClasica.o $(SRC)/I_DemoMiCadenaClasica.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/I_EncuentraInicioPalabras.o : $(SRC)/I_EncuentraInicioPalabras.cpp $(INCLUDE)/MiCadenaClasica.h 
	@echo
	@echo Creando objeto: I_EncuentraInicioPalabras.o
	@echo
	g++ -c -o $(OBJ)/I_EncuentraInicioPalabras.o $(SRC)/I_EncuentraInicioPalabras.cpp -I$(INCLUDE) -std=c++11


#Objetos utils
#.....................................................................................................................
$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo
	@echo Creando objeto: MiCadenaClasica.o
	@echo
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE) -std=c++11


#Bibliotecas
#.....................................................................................................................
$(LIB)/libMiCadenaClasica.a: $(OBJ)/MiCadenaClasica.o
	ar rvs -o $(LIB)/libMiCadenaClasica.a $(OBJ)/MiCadenaClasica.o



#Limpieza
#.....................................................................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/I_DemoMiCadenaClasica.o
	-rm $(OBJ)/I_EncuentraInicioPalabras.o
	-rm $(OBJ)/MiCadenaClasica.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/I_DemoMiCadenaClasica
	-rm $(BIN)/I_EncuentraInicioPalabras
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libMiCadenaClasica.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib