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
	$(BIN)/III_Demo-Corredores \
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
								$(LIB)/libSecuencia.a
	@echo
	@echo Creando ejecutable: II_Demo-Matriz2D
	@echo
	g++ -o $(BIN)/II_Demo-Matriz2D $(OBJ)/II_Demo-Matriz2D.o \
			-lMatriz2D -lSecuencia -L$(LIB)


$(BIN)/III_Demo-Corredores : $(OBJ)/III_Demo-Corredores.o \
							 $(LIB)/libCorredor.a $(LIB)/libCorredores.a

	@echo
	@echo Creando ejecutable: III_Demo-Corredores
	@echo
	g++ -o $(BIN)/III_Demo-Corredores $(OBJ)/III_Demo-Corredores.o \
				 -lCorredores -lCorredor -L$(LIB) -std=c++11



#Objetos main
#..............................................................................
$(OBJ)/II_Demo-Matriz2D.o : $(SRC)/II_Demo-Matriz2D.cpp \
							$(INCLUDE)/Matriz2D.h \
							$(INCLUDE)/TipoBase_Matriz2D.h \
							$(INCLUDE)/TipoBase_Secuencia.h
	@echo
	@echo Creando objeto: II_Demo-Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/II_Demo-Matriz2D.o $(SRC)/II_Demo-Matriz2D.cpp\
			 -I$(INCLUDE) -std=c++11


$(OBJ)/III_Demo-Corredores.o : $(SRC)/III_Demo-Corredores.cpp \
							$(INCLUDE)/Corredor.h \
							$(INCLUDE)/Corredores.h 

	@echo
	@echo Creando ejecutable: III_Demo-Corredores.o
	@echo
	g++ -c -o $(OBJ)/III_Demo-Corredores.o $(SRC)/III_Demo-Corredores.cpp \
				 -I$(INCLUDE) -std=c++11

#..............................................................................
#OBJETOS DE Clases
#..............................................................................
$(OBJ)/Matriz2D.o : $(SRC)/Matriz2D.cpp $(INCLUDE)/Matriz2D.h \
					$(INCLUDE)/TipoBase_Matriz2D.h $(INCLUDE)/Secuencia.h 
	@echo
	@echo Creando objeto: Matriz2D.o
	@echo
	g++ -c -o $(OBJ)/Matriz2D.o $(SRC)/Matriz2D.cpp \
				-I$(INCLUDE) -std=c++11


$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11


$(OBJ)/Corredor.o : $(SRC)/Corredor.cpp $(INCLUDE)/Corredor.h \
					$(INCLUDE)/Fecha.h $(INCLUDE)/utils.h \
					$(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Corredor.o
	@echo
	g++ -c -o $(OBJ)/Corredor.o $(SRC)/Corredor.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/Corredores.o : $(SRC)/Corredores.cpp $(INCLUDE)/Corredores.h \
					  $(INCLUDE)/Corredor.h $(INCLUDE)/utils.h \
					  $(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Corredores.o
	@echo
	g++ -c -o $(OBJ)/Corredores.o $(SRC)/Corredores.cpp -I$(INCLUDE) -std=c++11


#..............................................................................
#OBJETOS DE UTILIDADES
#..............................................................................
$(OBJ)/utils.o : $(SRC)/utils.cpp $(INCLUDE)/utils.h 
	@echo
	@echo Creando objeto: utils.o
	@echo
	g++ -c -o $(OBJ)/utils.o $(SRC)/utils.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/Fecha.o : $(SRC)/Fecha.cpp $(INCLUDE)/Fecha.h $(INCLUDE)/utils.h
	@echo
	@echo Creando objeto: Fecha.o
	@echo
	g++ -c -o $(OBJ)/Fecha.o $(SRC)/Fecha.cpp -I$(INCLUDE) -std=c++11


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


$(LIB)/libFecha.a: $(OBJ)/Fecha.o $(OBJ)/utils.o
	@echo
	@echo Creando biblioteca: libFecha.a
	@echo
	ar rvs $(LIB)/libFecha.a \
			$(OBJ)/Fecha.o $(OBJ)/utils.o

$(LIB)/libCorredores.a : $(OBJ)/Corredores.o $(OBJ)/Corredor.o
	@echo
	@echo Creando biblioteca: libCorredores.a
	@echo
	ar rvs $(LIB)/libCorredores.a $(OBJ)/Corredores.o $(OBJ)/Corredor.o 


$(LIB)/libCorredor.a: $(OBJ)/Corredor.o $(OBJ)/utils.o $(OBJ)/Fecha.o
	@echo
	@echo Creando biblioteca: libCorredor.a
	@echo
	ar rvs $(LIB)/libCorredor.a $(OBJ)/Corredor.o \
			$(OBJ)/Fecha.o $(OBJ)/utils.o

$(LIB)/libCorredores.a : $(OBJ)/Corredores.o $(OBJ)/Corredor.o $(OBJ)/utils.o
	@echo
	@echo Creando biblioteca: libCorredores.a
	@echo
	ar rvs $(LIB)/libCorredores.a $(OBJ)/Corredores.o $(OBJ)/Corredor.o \
									$(OBJ)/utils.o





#Limpieza
#..............................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/II_Demo-Matriz2D.o
	-rm $(OBJ)/III_Demo-Corredores.o
	-rm $(OBJ)/Matriz2D.o
	-rm $(OBJ)/Fecha.o
	-rm $(OBJ)/Corredores.o
	-rm $(OBJ)/Corredor.o
	-rm $(OBJ)/Secuencia.o
	-rm $(OBJ)/utils.o
	@echo ...Borrados
	@echo

clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/II_Demo-Matriz2D
	-rm $(BIN)/III_Demo-Corredores
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libMatriz2D.a
	-rm $(LIB)/libSecuencia.a
	-rm $(LIB)/libCorredor.a
	-rm $(LIB)/libCorredores.a
	-rm $(LIB)/libfecha.a
	@echo ...Borrados
	@echo
mr.proper: clean-objs clean-bins clean-lib
