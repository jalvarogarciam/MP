################################################################
#
# MP
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: sesion10.
#
################################################################

HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include



EJ5 = 5.CuentaLineas
EJ7 = 7.CopiaLineasSinAlmohadilla
EJ13 = 13.CuentaCaracteresConcretos
EJ14 = 14.CuentaPalabrasLongitudConcreta
EJ15 = 15.Cabecera
EJ16 = 16.Final
EJ17 = 17.Cuenta_palabras_por_linea

all: \
	preambulo \
	ejecutables \
	$(BIN)/Cabecera \
	$(BIN)/Final \
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

#..............................................................................
#ejecutables
#..............................................................................
$(BIN)/Cabecera : $(OBJ)/Cabecera.o $(LIB)/libUtils_ES.a 
	@echo
	@echo Creando ejecutable: Cabecera
	@echo
	g++ -o $(BIN)/Cabecera $(OBJ)/Cabecera.o -L$(LIB)

$(BIN)/Final : $(OBJ)/Final.o $(LIB)/libUtils_ES.a 
	@echo
	@echo Creando ejecutable: Final
	@echo
	g++ -o $(BIN)/Final $(OBJ)/Final.o -L$(LIB)


#..............................................................................
#Objetos main
#..............................................................................
$(OBJ)/Cabecera.o : $(SRC)/Cabecera.cpp $(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: Cabecera
	@echo
	g++ -c -g -o $(OBJ)/Cabecera.o $(SRC)/Cabecera.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Final.o : $(SRC)/Final.cpp $(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: Final
	@echo
	g++ -c -g -o $(OBJ)/Final.o $(SRC)/Final.cpp -I$(INCLUDE) -std=c++11

#..............................................................................
#Objetos de utilidades
#..............................................................................
$(OBJ)/Utils_ES.o : $(SRC)/Utils_ES.cpp $(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: Utils_ES.o
	@echo
	g++ -c -g -o $(OBJ)/Utils_ES.o $(SRC)/Utils_ES.cpp -I$(INCLUDE) -std=c++11


#..............................................................................
#Bibliotecas
#..............................................................................
$(LIB)/libUtils_ES.a : $(OBJ)/Utils_ES.o
	@echo 
	@echo Creando biblioteca: Utils_ES.a
	@echo  
	ar rvs $(LIB)/libUtils_ES.a  $(OBJ)/Utils_ES.o


#Limpieza
#..............................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/Final.o
	-rm $(OBJ)/Cabecera.o
	@echo ...Borrados
	@echo

clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/Final
	-rm $(BIN)/Cabecera
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libUtils_ES.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
