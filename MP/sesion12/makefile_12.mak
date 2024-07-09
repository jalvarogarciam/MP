################################################################
#
# MP
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto: sesion12.
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
	$(BIN)/VI_Demo-Matriz \
	$(BIN)/NumeraLineas_Ampliacion \
	$(BIN)/InfoPGM \
	$(BIN)/ParteFicheroPorNumLineas \
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
$(BIN)/VI_Demo-Matriz : $(OBJ)/VI_Demo-Matriz.o $(LIB)/libMatriz2D.a \
						$(LIB)/libSecuencia.a
	@echo
	@echo Creando ejecutable: VI_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/VI_Demo-Matriz $(OBJ)/VI_Demo-Matriz.o \
			-lMatriz2D -lSecuencia -L$(LIB)

$(BIN)/NumeraLineas_Ampliacion : $(OBJ)/NumeraLineas_Ampliacion.o \
								$(LIB)/libUtils_ES.a
	@echo
	@echo Creando ejecutable: NumeraLineas_Ampliacion
	@echo
	g++ -o $(BIN)/NumeraLineas_Ampliacion $(OBJ)/NumeraLineas_Ampliacion.o \
			-lUtils_ES -L$(LIB)

$(BIN)/InfoPGM : $(OBJ)/InfoPGM.o $(LIB)/libUtils_ES.a
	@echo
	@echo Creando ejecutable: InfoPGM
	@echo
	g++ -o $(BIN)/InfoPGM $(OBJ)/InfoPGM.o \
			-lUtils_ES -L$(LIB)

$(BIN)/ParteFicheroPorNumLineas : $(OBJ)/ParteFicheroPorNumLineas.o \
								$(LIB)/libUtils_ES.a
	@echo
	@echo Creando ejecutable: ParteFicheroPorNumLineas
	@echo
	g++ -o $(BIN)/ParteFicheroPorNumLineas $(OBJ)/ParteFicheroPorNumLineas.o \
			-lUtils_ES -L$(LIB)


#..............................................................................
#Objetos main
#..............................................................................
$(OBJ)/VI_Demo-Matriz.o : $(SRC)/VI_Demo-Matriz.cpp \
							$(INCLUDE)/Matriz2D.h \
							$(INCLUDE)/TipoBase_Matriz2D.h \
							$(INCLUDE)/TipoBase_Secuencia.h
	@echo
	@echo Creando objeto: VI_Demo-Matriz2D
	@echo
	g++ -c -g -o $(OBJ)/VI_Demo-Matriz.o $(SRC)/VI_Demo-Matriz.cpp\
		 		-I$(INCLUDE) -std=c++11


$(OBJ)/NumeraLineas_Ampliacion.o : $(SRC)/NumeraLineas_Ampliacion.cpp \
									$(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: NumeraLineas_Ampliacion.o
	@echo
	g++ -c -g -o $(OBJ)/NumeraLineas_Ampliacion.o \
					$(SRC)/NumeraLineas_Ampliacion.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/InfoPGM.o : $(SRC)/InfoPGM.cpp $(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: InfoPGM.o
	@echo
	g++ -c -g -o $(OBJ)/InfoPGM.o $(SRC)/InfoPGM.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/ParteFicheroPorNumLineas.o : $(SRC)/ParteFicheroPorNumLineas.cpp \
									$(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: ParteFicheroPorNumLineas.o
	@echo
	g++ -c -g -o $(OBJ)/ParteFicheroPorNumLineas.o \
					$(SRC)/ParteFicheroPorNumLineas.cpp -I$(INCLUDE) -std=c++11

#..............................................................................
#Objetos de utilidades
#..............................................................................
$(OBJ)/Utils_ES.o : $(SRC)/Utils_ES.cpp $(INCLUDE)/Utils_ES.h
	@echo
	@echo Creando objeto: Utils_ES.o
	@echo
	g++ -c -g -o $(OBJ)/Utils_ES.o $(SRC)/Utils_ES.cpp -I$(INCLUDE) -std=c++11

#..............................................................................
#OBJETOS DE Clases
#..............................................................................
$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase_Matriz2D.h $(INCLUDE)/Secuencia.h \

	@echo
	@echo Creando objeto: Matriz2D.o
	@echo
	g++ -c -g -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp \
				-I$(INCLUDE) -std=c++11


$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -g -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11



#..............................................................................
#Bibliotecas
#..............................................................................
$(LIB)/libMatriz2D.a: $(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o
	@echo
	@echo Creando biblioteca: libMatriz2D.a
	@echo
	ar rvs $(LIB)/libMatriz2D.a $(OBJ)/Matriz2D.o $(OBJ)/Secuencia.o 

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o

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
	-rm $(OBJ)/VI_Demo-Matriz2D.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Secuencia.o
	-rm $(OBJ)/NumeraLineas_Ampliacion.o
	-rm $(OBJ)/ParteFicheroPorNumLineas.o
	-rm $(OBJ)/InfoPGM.o
	-rm $(OBJ)/Utils_ES.o
	-rm $(OBJ)/VI_Demo-Matriz.o
	@echo ...Borrados
	@echo

clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/VI_Demo-Matriz
	-rm $(BIN)/NumeraLineas_Ampliacion
	-rm $(BIN)/ParteFicheroPorNumLineas
	-rm $(BIN)/InfoPGM
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libMatriz2D.a
	-rm $(LIB)/libSecuencia.a
	-rm $(LIB)/libUtils_ES.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
