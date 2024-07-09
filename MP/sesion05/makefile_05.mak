################################################################
#
# MP
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: sesion05.
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
	$(BIN)/I_MezclaArrays \
	$(BIN)/I_MezclaArrays_ref \
	$(BIN)/I_DemoSecuenciaEnteros \
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
$(BIN)/I_MezclaArrays : $(OBJ)/I_MezclaArrays.o \
						$(LIB)/libProcesamientoArrayInt.a \
						$(LIB)/libGeneradorAleatorioEnteros.a
	@echo
	@echo Creando ejecutable: I_MezclaArrays
	@echo
	g++ -o $(BIN)/I_MezclaArrays $(OBJ)/I_MezclaArrays.o \
	-lProcesamientoArrayInt -lGeneradorAleatorioEnteros -L$(LIB)


$(BIN)/I_MezclaArrays_ref : $(OBJ)/I_MezclaArrays_ref.o \
							$(LIB)/libProcesamientoArrayInt.a \
						    $(LIB)/libGeneradorAleatorioEnteros.a
	@echo
	@echo Creando ejecutable: I_MezclaArrays_ref
	@echo
	g++ -o $(BIN)/I_MezclaArrays_ref $(OBJ)/I_MezclaArrays_ref.o \
	-lProcesamientoArrayInt -lGeneradorAleatorioEnteros -L$(LIB)

$(BIN)/I_DemoSecuenciaEnteros : $(SRC)/I_DemoSecuenciaEnteros.cpp \
								$(LIB)/libSecuenciaEnteros_basico.a
	@echo
	@echo Creando ejecutable: I_DemoSecuenciaEnteros
	@echo
	g++ -o $(BIN)/I_DemoSecuenciaEnteros $(SRC)/I_DemoSecuenciaEnteros.cpp \
	-lSecuenciaEnteros_basico -L$(LIB) -I$(INCLUDE) -std=c++11

#Objetos main
#.....................................................................................................................
$(OBJ)/I_MezclaArrays.o : $(SRC)/I_MezclaArrays.cpp \
						  $(INCLUDE)/ProcesamientoArrayInt.h \
						  $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo
	@echo Creando objeto: I_MezclaArrays.o
	@echo
	g++ -c -o $(OBJ)/I_MezclaArrays.o $(SRC)/I_MezclaArrays.cpp\
			 -I$(INCLUDE) -std=c++11

$(OBJ)/I_MezclaArrays_ref.o : $(SRC)/I_MezclaArrays_ref.cpp \
						  $(INCLUDE)/ProcesamientoArrayInt.h \
						  $(INCLUDE)/GeneradorAleatorioEnteros.h 
	@echo
	@echo Creando objeto: I_MezcI_MezclaArrays_reflaArrays.o
	@echo
	g++ -c -o $(OBJ)/I_MezclaArrays_ref.o $(SRC)/I_MezclaArrays_ref.cpp\
			 -I$(INCLUDE) -std=c++11

$(OBJ)/I_DemoSecuenciaEnteros.o : $(SRC)/I_DemoSecuenciaEnteros.cpp \
								  $(INCLUDE)/SecuenciaEnteros_basico.h
	@echo
	@echo Creando objeto: I_DemoSecuenciaEnteros.o
	@echo
	g++ -c -o $(OBJ)/I_DemoSecuenciaEnteros.o $(SRC)/I_DemoSecuenciaEnteros.cpp \
			-I$(INCLUDE) -std=c++11

#Objetos utils
#.....................................................................................................................
$(OBJ)/ProcesamientoArrayInt.o : $(SRC)/ProcesamientoArrayInt.cpp \
								 $(INCLUDE)/GeneradorAleatorioEnteros.h \
								 $(INCLUDE)/ProcesamientoArrayInt.h
	@echo
	@echo Creando objeto: ProcesamientoArrayInt.o
	@echo
	g++ -c -o $(OBJ)/ProcesamientoArrayInt.o $(SRC)/ProcesamientoArrayInt.cpp \
			-I$(INCLUDE) -std=c++11

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
									 $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo
	@echo Creando objeto: GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
			  $(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/SecuenciaEnteros_basico.o : $(SRC)/SecuenciaEnteros_basico.cpp \
								   $(INCLUDE)/SecuenciaEnteros_basico.h \
								   $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo
	@echo Creando objeto: SecuenciaEnteros_basico.o
	@echo
	g++ -c -o $(OBJ)/SecuenciaEnteros_basico.o \
			  $(SRC)/SecuenciaEnteros_basico.cpp -I$(INCLUDE) -std=c++11


#Bibliotecas
#.....................................................................................................................
$(LIB)/libGeneradorAleatorioEnteros.a: $(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando biblioteca: libGeneradorAleatorioEnteros.a
	@echo
	ar rvs -o $(LIB)/libGeneradorAleatorioEnteros.a \
			  $(OBJ)/GeneradorAleatorioEnteros.o

$(LIB)/libSecuenciaEnteros_basico.a: $(OBJ)/SecuenciaEnteros_basico.o \
									 $(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando biblioteca: libSecuenciaEnteros_basico.a
	@echo
	ar rvs -o $(LIB)/libSecuenciaEnteros_basico.a \
			  $(OBJ)/SecuenciaEnteros_basico.o \
			  $(OBJ)/GeneradorAleatorioEnteros.o

$(LIB)/libProcesamientoArrayInt.a: $(OBJ)/ProcesamientoArrayInt.o
	@echo
	@echo Creando biblioteca: libProcesamientoArrayInt.a
	@echo
	ar rvs -o $(LIB)/libProcesamientoArrayInt.a \
			  $(OBJ)/ProcesamientoArrayInt.o

#Limpieza
#.....................................................................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/I_MezclaArrays.o
	-rm $(OBJ)/I_MezclaArrays_ref.o
	-rm $(OBJ)/I_DemoSecuenciaEnteros.o
	-rm $(OBJ)/SecuenciaEnteros_basico.o
	-rm $(OBJ)/ProcesamientoArrayInt.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/I_MezclaArrays
	-rm $(BIN)/I_MezclaArrays_ref
	-rm $(BIN)/I_DemoSecuenciaEnteros
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libGeneradorAleatorioEnteros.a
	-rm $(LIB)/libSecuenciaEnteros_basico.a
	-rm $(LIB)/libProcesamientoArrayInt.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
