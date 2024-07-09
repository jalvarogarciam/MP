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
	$(BIN)/II_Demo-VectorDinamico \
	$(BIN)/II_Demo-VectorDinamico_Eliminacion \
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
$(BIN)/II_Demo-VectorDinamico : $(OBJ)/II_Demo-VectorDinamico.o \
								$(LIB)/libVectorDinamico.a \

	@echo
	@echo Creando ejecutable: II_Demo-VectorDinamico
	@echo
	g++ -o $(BIN)/II_Demo-VectorDinamico $(OBJ)/II_Demo-VectorDinamico.o \
	-lVectorDinamico -L$(LIB)


$(BIN)/II_Demo-VectorDinamico_Eliminacion : \
								$(OBJ)/II_Demo-VectorDinamico_Eliminacion.o \
								$(LIB)/libVectorDinamico.a 
	@echo
	@echo Creando ejecutable: II_Demo-VectorDinamico_Eliminacion
	@echo
	g++ -o $(BIN)/II_Demo-VectorDinamico_Eliminacion \
			$(OBJ)/II_Demo-VectorDinamico_Eliminacion.o \
			-lVectorDinamico -L$(LIB)



#Objetos main
#..............................................................................
$(OBJ)/II_Demo-VectorDinamico.o : $(SRC)/II_Demo-VectorDinamico.cpp \
								  $(INCLUDE)/FuncsVectorDinamico.h \

	@echo
	@echo Creando objeto: II_Demo-VectorDinamico.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-VectorDinamico.o $(SRC)/II_Demo-VectorDinamico.cpp\
			 -I$(INCLUDE) -std=c++11

$(OBJ)/II_Demo-VectorDinamico_Eliminacion.o : \
								$(SRC)/II_Demo-VectorDinamico_Eliminacion.cpp \
								$(INCLUDE)/FuncsVectorDinamico.h \

	@echo
	@echo Creando objeto: II_Demo-VectorDinamico_Eliminacion.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-VectorDinamico_Eliminacion.o \
				$(SRC)/II_Demo-VectorDinamico_Eliminacion.cpp\
				-I$(INCLUDE) -std=c++11



#Objetos utils
#..............................................................................
$(OBJ)/FuncsVectorDinamico.o : $(SRC)/FuncsVectorDinamico.cpp \
							   $(INCLUDE)/FuncsVectorDinamico.h
	@echo
	@echo Creando objeto: FuncsVectorDinamico.o
	@echo
	g++ -c -o $(OBJ)/FuncsVectorDinamico.o $(SRC)/FuncsVectorDinamico.cpp \
				-I$(INCLUDE) -std=c++11


$(OBJ)/ProcesamientoArray.o : $(SRC)/ProcesamientoArray.cpp \
							  $(INCLUDE)/GeneradorAleatorioEnteros.h \
							  $(INCLUDE)/ProcesamientoArray.h
	@echo
	@echo Creando objeto: ProcesamientoArray.o
	@echo
	g++ -c -o $(OBJ)/ProcesamientoArray.o $(SRC)/ProcesamientoArray.cpp \
				-I$(INCLUDE) -std=c++11

$(OBJ)/GeneradorAleatorioEnteros.o : $(SRC)/GeneradorAleatorioEnteros.cpp \
									 $(INCLUDE)/GeneradorAleatorioEnteros.h
	@echo
	@echo Creando objeto: GeneradorAleatorioEnteros.o
	@echo
	g++ -c -o $(OBJ)/GeneradorAleatorioEnteros.o \
				$(SRC)/GeneradorAleatorioEnteros.cpp -I$(INCLUDE) -std=c++11


#Bibliotecas
#..............................................................................
$(LIB)/libVectorDinamico.a: $(OBJ)/FuncsVectorDinamico.o \
							$(OBJ)/ProcesamientoArray.o \
							$(OBJ)/GeneradorAleatorioEnteros.o
	@echo
	@echo Creando biblioteca: libVectorDinamico.a
	@echo
	ar rvs $(LIB)/libVectorDinamico.a $(OBJ)/FuncsVectorDinamico.o \
			$(OBJ)/ProcesamientoArray.o $(OBJ)/GeneradorAleatorioEnteros.o



#Limpieza
#..............................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/II_Demo-VectorDinamico.o
	-rm $(OBJ)/II_Demo-VectorDinamico_Eliminacion.o
	-rm $(OBJ)/FuncsVectorDinamico.o
	-rm $(OBJ)/ProcesamientoArray.o
	-rm $(OBJ)/GeneradorAleatorioEnteros.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/II_Demo-VectorDinamico
	-rm $(BIN)/II_Demo-VectorDinamico_Eliminacion
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libVectorDinamico.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
