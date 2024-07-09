################################################################
#
# MP_Proyecto_Fase4.mak
#
# (C) José Álvaro García Márquez
# Ingeniería Técnica Informática 1ºB grupo 1
#
# Fichero: makefile
#
# makefile para el proyecto fase 4.
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
	$(BIN)/MP_Proyecto_Fase4 \
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
#EJECUTABLES
#..............................................................................
$(BIN)/MP_Proyecto_Fase4: $(OBJ)/main_MP_Proyecto_Fase4.o \
								$(LIB)/libTiempo.a $(LIB)/libFecha.a \
								$(LIB)/libCarrera.a $(LIB)/libCorredor.a \
								$(LIB)/libCategoria.a $(LIB)/libResultado.a \
								$(LIB)/libCarreras.a $(LIB)/libCorredores.a \
								$(LIB)/libCategorias.a $(LIB)/libResultados.a \
								$(LIB)/libTodosResultados.a $(LIB)/libUtils.a
	@echo
	@echo Creando ejecutable: main_MP_Proyecto_Fase4
	@echo
	g++ -o $(BIN)/MP_Proyecto_Fase4 $(OBJ)/main_MP_Proyecto_Fase4.o \
			-lTiempo -lFecha -lCarreras -lCorredores -lCategorias -lResultados\
			-lCarrera -lCorredor -lCategoria -lResultado -lTodosResultados\
			-lUtils -L$(LIB) -std=c++11
#..............................................................................
#..............................................................................

#..............................................................................
#OBJETOS DEL MAIN
#..............................................................................
$(OBJ)/main_MP_Proyecto_Fase4.o: $(SRC)/main_MP_Proyecto_Fase4.cpp \
							$(INCLUDE)/Carrera.h $(INCLUDE)/Corredor.h \
							$(INCLUDE)/Categoria.h $(INCLUDE)/Resultado.h \
							$(INCLUDE)/Carreras.h $(INCLUDE)/Corredores.h \
							$(INCLUDE)/Categorias.h $(INCLUDE)/Resultados.h \
							$(INCLUDE)/TodosResultados.h \
							$(INCLUDE)/Fecha.h $(INCLUDE)/Tiempo.h \
							$(INCLUDE)/Utils.h
	@echo
	@echo Creando objeto: main_MP_Proyecto_Fase4.o
	@echo
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase4.o \
				$(SRC)/main_MP_Proyecto_Fase4.cpp -I$(INCLUDE) -std=c++11
#..............................................................................
#..............................................................................


#..............................................................................
#OBJETOS DE CLASES
#..............................................................................

$(OBJ)/Carrera.o : $(SRC)/Carrera.cpp $(INCLUDE)/Carrera.h \
					$(INCLUDE)/Fecha.h $(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Carrera.o
	@echo
	g++ -c -o $(OBJ)/Carrera.o $(SRC)/Carrera.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Carreras.o : $(SRC)/Carreras.cpp $(INCLUDE)/Carreras.h \
					  $(INCLUDE)/Carrera.h $(INCLUDE)/Constantes.h \
					  $(INCLUDE)/Utils.h
	@echo
	@echo Creando objeto: Carreras.o
	@echo
	g++ -c -o $(OBJ)/Carreras.o $(SRC)/Carreras.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/Corredor.o : $(SRC)/Corredor.cpp $(INCLUDE)/Corredor.h \
					$(INCLUDE)/Fecha.h $(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Corredor.o
	@echo
	g++ -c -o $(OBJ)/Corredor.o $(SRC)/Corredor.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Corredores.o : $(SRC)/Corredores.cpp $(INCLUDE)/Corredores.h \
					  $(INCLUDE)/Corredor.h $(INCLUDE)/Constantes.h \
					  $(INCLUDE)/Utils.h
	@echo
	@echo Creando objeto: Corredores.o
	@echo
	g++ -c -o $(OBJ)/Corredores.o $(SRC)/Corredores.cpp -I$(INCLUDE) -std=c++11



$(OBJ)/Categoria.o : $(SRC)/Categoria.cpp $(INCLUDE)/Categoria.h \
					$(INCLUDE)/Fecha.h $(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Categoria.o
	@echo
	g++ -c -o $(OBJ)/Categoria.o $(SRC)/Categoria.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Categorias.o : $(SRC)/Categorias.cpp $(INCLUDE)/Categorias.h \
					  $(INCLUDE)/Categoria.h $(INCLUDE)/Constantes.h \
					  $(INCLUDE)/Utils.h
	@echo
	@echo Creando objeto: Categorias.o
	@echo
	g++ -c -o $(OBJ)/Categorias.o $(SRC)/Categorias.cpp -I$(INCLUDE) -std=c++11



$(OBJ)/Resultado.o : $(SRC)/Resultado.cpp $(INCLUDE)/Resultado.h \
					$(INCLUDE)/Tiempo.h $(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Resultado.o
	@echo
	g++ -c -o $(OBJ)/Resultado.o $(SRC)/Resultado.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/Resultados.o : $(SRC)/Resultados.cpp $(INCLUDE)/Resultados.h \
					  $(INCLUDE)/Resultado.h  $(INCLUDE)/Constantes.h \
					  $(INCLUDE)/Utils.h
	@echo
	@echo Creando objeto: Resultados.o
	@echo
	g++ -c -o $(OBJ)/Resultados.o $(SRC)/Resultados.cpp -I$(INCLUDE) -std=c++11


$(OBJ)/TodosResultados.o : $(SRC)/TodosResultados.cpp \
							$(INCLUDE)/TodosResultados.h \
					  		$(INCLUDE)/Resultados.h	$(INCLUDE)/Constantes.h
	@echo
	@echo Creando objeto: Resultados.o
	@echo
	g++ -c -o $(OBJ)/TodosResultados.o $(SRC)/TodosResultados.cpp \
			-I$(INCLUDE) -std=c++11
#..............................................................................
#..............................................................................


#..............................................................................
#OBJETOS DE UTILIDADES
#..............................................................................
$(OBJ)/Utils.o : $(SRC)/Utils.cpp $(INCLUDE)/Utils.h \
					$(INCLUDE)/Tiempo.h $(INCLUDE)/Fecha.h 
	@echo
	@echo Creando objeto: Utils.o
	@echo
	g++ -c -o $(OBJ)/Utils.o $(SRC)/Utils.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Tiempo.o : $(SRC)/Tiempo.cpp $(INCLUDE)/Tiempo.h
	@echo
	@echo Creando objeto: Tiempo.o
	@echo
	g++ -c -o $(OBJ)/Tiempo.o $(SRC)/Tiempo.cpp -I$(INCLUDE) -std=c++11

$(OBJ)/Fecha.o : $(SRC)/Fecha.cpp $(INCLUDE)/Fecha.h
	@echo
	@echo Creando objeto: Fecha.o
	@echo
	g++ -c -o $(OBJ)/Fecha.o $(SRC)/Fecha.cpp -I$(INCLUDE) -std=c++11
#..............................................................................
#..............................................................................


#..............................................................................
#BIBLIOTECAS
#..............................................................................
$(LIB)/libTiempo.a : $(OBJ)/Tiempo.o
	@echo
	@echo Creando biblioteca: libTiempo.a
	@echo
	ar rvs $(LIB)/libTiempo.a $(OBJ)/Tiempo.o


$(LIB)/libFecha.a : $(OBJ)/Fecha.o
	@echo
	@echo Creando biblioteca: libFecha.a
	@echo
	ar rvs $(LIB)/libFecha.a $(OBJ)/Fecha.o 

$(LIB)/libUtils.a : $(OBJ)/Utils.o $(OBJ)/Fecha.o  $(OBJ)/Tiempo.o
	@echo
	@echo Creando biblioteca: libUtils.a
	@echo
	ar rvs $(LIB)/libUtils.a $(OBJ)/Utils.o  $(OBJ)/Tiempo.o $(OBJ)/Fecha.o


$(LIB)/libCarrera.a : $(OBJ)/Carrera.o $(OBJ)/Fecha.o
	@echo
	@echo Creando biblioteca: libCarrera.a
	@echo
	ar rvs $(LIB)/libCarrera.a $(OBJ)/Carrera.o $(OBJ)/Fecha.o

$(LIB)/libCarreras.a : $(OBJ)/Carreras.o $(OBJ)/Carrera.o $(OBJ)/Utils.o \
						$(OBJ)/Tiempo.o
	@echo
	@echo Creando biblioteca: libCarreras.a
	@echo
	ar rvs $(LIB)/libCarreras.a $(OBJ)/Carreras.o $(OBJ)/Carrera.o \
			$(OBJ)/Utils.o $(OBJ)/Fecha.o $(OBJ)/Tiempo.o



$(LIB)/libCorredor.a : $(OBJ)/Corredor.o $(OBJ)/Fecha.o
	@echo
	@echo Creando biblioteca: libCorredor.a
	@echo
	ar rvs $(LIB)/libCorredor.a $(OBJ)/Corredor.o $(OBJ)/Fecha.o

$(LIB)/libCorredores.a : $(OBJ)/Corredores.o $(OBJ)/Corredor.o $(OBJ)/Tiempo.o \
							$(OBJ)/Utils.o
	@echo
	@echo Creando biblioteca: libCorredores.a
	@echo
	ar rvs $(LIB)/libCorredores.a $(OBJ)/Corredores.o $(OBJ)/Corredor.o \
			$(OBJ)/Tiempo.o $(OBJ)/Utils.o



$(LIB)/libCategoria.a : $(OBJ)/Categoria.o $(OBJ)/Fecha.o
	@echo
	@echo Creando biblioteca: libCategoria.a
	@echo
	ar rvs $(LIB)/libCategoria.a $(OBJ)/Categoria.o \
			$(OBJ)/Fecha.o

$(LIB)/libCategorias.a : $(OBJ)/Categorias.o $(OBJ)/Categoria.o \
							$(OBJ)/Tiempo.o $(OBJ)/Utils.o
	@echo
	@echo Creando biblioteca: libCategorias.a
	@echo
	ar rvs $(LIB)/libCategorias.a $(OBJ)/Categorias.o $(OBJ)/Categoria.o \
			$(OBJ)/Tiempo.o $(OBJ)/Utils.o



$(LIB)/libResultado.a : $(OBJ)/Resultado.o $(OBJ)/Tiempo.o
	@echo
	@echo Creando biblioteca: libResultado.a
	@echo
	ar rvs $(LIB)/libResultado.a $(OBJ)/Resultado.o \
			$(OBJ)/Tiempo.o

$(LIB)/libResultados.a : $(OBJ)/Resultados.o $(OBJ)/Resultado.o \
							$(OBJ)/Fecha.o $(OBJ)/Utils.o
	@echo
	@echo Creando biblioteca: libResultados.a
	@echo
	ar rvs $(LIB)/libResultados.a $(OBJ)/Resultados.o $(OBJ)/Resultado.o \
			$(OBJ)/Fecha.o $(OBJ)/Utils.o

$(LIB)/libTodosResultados.a : $(OBJ)/TodosResultados.o $(OBJ)/Resultados.o \
							$(OBJ)/Resultado.o $(OBJ)/Tiempo.o
	@echo
	@echo Creando biblioteca: libTodosResultados.a
	@echo
	ar rvs $(LIB)/libTodosResultados.a $(OBJ)/TodosResultados.o \
			$(OBJ)/Resultados.o $(OBJ)/Resultado.o \
			$(OBJ)/Tiempo.o
#..............................................................................
#..............................................................................






#..............................................................................
#Limpieza
#..............................................................................
clean: clean-objs
clean-objs:
	@echo Borrando objetos...
	-rm $(OBJ)/Tiempo.o
	-rm $(OBJ)/Fecha.o
	-rm $(OBJ)/Utils.o
	-rm $(OBJ)/Carrera.o
	-rm $(OBJ)/Corredor.o
	-rm $(OBJ)/Categoria.o
	-rm $(OBJ)/Resultado.o
	-rm $(OBJ)/Carreras.o
	-rm $(OBJ)/Corredores.o
	-rm $(OBJ)/Categorias.o
	-rm $(OBJ)/Resultados.o
	-rm $(OBJ)/TodosResultados.o
	-rm $(OBJ)/main_MP_Proyecto_Fase4.o
	@echo ...Borrados
	@echo
clean-bins :
	@echo Borrando ejecutables...
	-rm $(BIN)/MP_Proyecto_Fase4
	@echo ...Borrados
	@echo
clean-lib:
	@echo Borrando bibliotecas...
	-rm $(LIB)/libTiempo.a
	-rm $(LIB)/libFecha.a
	-rm $(LIB)/libUtils.a
	-rm $(LIB)/libCarrera.a
	-rm $(LIB)/libCorredor.a
	-rm $(LIB)/libCategoria.a
	-rm $(LIB)/libResultado.a
	-rm $(LIB)/libCarreras.a
	-rm $(LIB)/libCorredores.a
	-rm $(LIB)/libCategorias.a
	-rm $(LIB)/libResultados.a
	-rm $(LIB)/libTodosResultados.a
	@echo ...Borrados
	@echo
	
mr.proper: clean-objs clean-bins clean-lib
#..............................................................................
#..............................................................................
