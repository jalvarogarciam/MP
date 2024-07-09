################################################################
#
# MP
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: Ordenacion por suma de los dıgitos.
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
	$(BIN)/I_PosMayor_Basico \
	$(BIN)/I_OrdenaVector \
	$(BIN)/I_OrdenayMezclaVectores \
	fin-ejecutables

preambulo:
	@echo
	@echo -----------------------------------------------------------
	@echo MP
	@echo "("c")" José Álvaro García Márquez
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
$(BIN)/I_PosMayor_Basico : $(OBJ)/I_PosMayor_Basico.o $(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a
	@echo
	@echo Creando ejecutable: I_PosMayor_Basico
	@echo
	g++ -o $(BIN)/I_PosMayor_Basico $(OBJ)/I_PosMayor_Basico.o\
			$(OBJ)/ProcesamientoArrayInt.o -lGeneradorAleatorioEnteros -L$(LIB)

$(BIN)/I_OrdenaVector : $(OBJ)/I_OrdenaVector.o $(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a
	@echo
	@echo Creando ejecutable: I_OrdenaVector
	@echo
	g++ -o $(BIN)/I_OrdenaVector $(OBJ)/I_OrdenaVector.o\
			$(OBJ)/ProcesamientoArrayInt.o -lGeneradorAleatorioEnteros -L$(LIB)

$(BIN)/I_OrdenayMezclaVectores : $(OBJ)/I_OrdenayMezclaVectores.o $(OBJ)/ProcesamientoArrayInt.o $(LIB)/libGeneradorAleatorioEnteros.a
	@echo
	@echo Creando ejecutable: I_OrdenayMezclaVectores
	@echo
	g++ -o $(BIN)/I_OrdenayMezclaVectores $(OBJ)/I_OrdenayMezclaVectores.o\
			$(OBJ)/ProcesamientoArrayInt.o -lGeneradorAleatorioEnteros -L$(LIB)


#Objetos main
#.....................................................................................................................
$(OBJ)/I_PosMayor_Basico.o : $(SRC)/I_PosMayor_Basico.cpp $(INCLUDE)/ProcesamientoArrayInt.h $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo
	@echo Creando objeto: I_PosMayor_Basico.o
	@echo
	g++ -c -o $(OBJ)/I_PosMayor_Basico.o $(SRC)/I_PosMayor_Basico.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/I_OrdenaVector.o : $(SRC)/I_OrdenaVector.cpp $(INCLUDE)/ProcesamientoArrayInt.h $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo
	@echo Creando objeto: I_OrdenaVector.o
	@echo
	g++ -c -o $(OBJ)/I_OrdenaVector.o $(SRC)/I_OrdenaVector.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/I_OrdenayMezclaVectores.o : $(SRC)/I_OrdenayMezclaVectores.cpp $(INCLUDE)/ProcesamientoArrayInt.h $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo
	@echo Creando objeto: I_OrdenayMezclaVectores.o
	@echo
	g++ -c -o $(OBJ)/I_OrdenayMezclaVectores.o $(SRC)/I_OrdenayMezclaVectores.cpp -I$(INCLUDE) -std=c++11


#Objetos utils
#.....................................................................................................................
$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp $(INCLUDE)/GeneradorAleatorioEnteros.h $(INCLUDE)/ProcesamientoArrayInt.h
	@echo
	@echo Creando objeto: GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o $(SRC)/ProcesamientoArrayInt.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo
	@echo Creando objeto: GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++11


#Bibliotecas
#.....................................................................................................................
$(LIB)/libGeneradorAleatorioEnteros.a: $(OBJ)/GeneradorAleatorioEnteros.o
	ar rvs -o $(LIB)/libGeneradorAleatorioEnteros.a $(OBJ)/GeneradorAleatorioEnteros.o



#Limpieza
#.....................................................................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/I_OrdenaVector.o
	-rm $(OBJ)/I_PosMayor_Basico.o
	-rm $(OBJ)/I_OrdenayMezclaVectores.o
	-rm $(OBJ)/ProcesamientoArrayInt.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/I_OrdenaVector
	-rm $(BIN)/I_PosMayor_Basico
	-rm $(BIN)/I_OrdenayMezclaVectores
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libGeneradorAleatorioEnteros.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
