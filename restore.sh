#supression des makefiles existants
rm -rf *Make*;
#recreation des makefiles
touch Makefile;
touch MakefileOpenmpO3;
touch MakefileNOpenmpO3;
touch MakefileOpenmpO3SSE;
#remplissage des fichiers
	#remplissage de Makefile
echo -e '#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -std=c99 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = test_matrix_small test_matrix_big test_vect test_vect_lib gen_aleat libvect.a
DEBUG = 0
_OPENMP = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = libs/
DIR_EXE = target/debug/
DIR_OBJ = target/obj/

# MAT_SMALL = limit size of the cache = sqrt(99 225) = 315
# MAT_BIG = sqrt(302 500) = 550
MAT_SMALL = 315
MAT_BIG = 550

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

test_matrix_small: $(DIR_OBJ)matrice_small.o $(DIR_OBJ)main_small.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_matrix_big: $(DIR_OBJ)matrice_big.o $(DIR_OBJ)main_big.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_vect: $(DIR_OBJ)test_vect.o $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_vect_lib: $(DIR_OBJ)test_vect.o libvect.a
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $< $(DIR_LIB)libvect.a
	@echo -e

gen_aleat: $(DIR_OBJ)gen_aleat.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

libvect.a: $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	ar rvs $(DIR_LIB)$@ $^
	@echo -e

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#--------------
#		SMALL
#--------------
$(DIR_OBJ)main_small.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -fopenmp -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_small.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -fopenmp -c $< $(CFLAGS)
	@echo -e


#--------------
#		BIG
#--------------
$(DIR_OBJ)main_big.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -fopenmp -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_big.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -fopenmp -c $< $(CFLAGS)
	@echo -e


#--------------
#		Global
#--------------
$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)test_vect.o : $(DIR_SRC)test_vect.c $(DIR_INCLUDE)vecteur.h

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------

clean:
	rm -f $(DIR_OBJ)* $(DIR_EXE)* $(DIR_LIB)libvect.a' >> Makefile;

	#remplissage de MakefileOpenmpO3
	echo -e '#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -O3 -std=c99 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = test_matrix_small test_matrix_big test_vect test_vect_lib gen_aleat libvect.a
DEBUG = 0
_OPENMP = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = libs/
DIR_EXE = target/debug/
DIR_OBJ = target/obj/

# MAT_SMALL = limit size of the cache = sqrt(99 225) = 315
# MAT_BIG = sqrt(302 500) = 550
MAT_SMALL = 315
MAT_BIG = 550

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

test_matrix_small: $(DIR_OBJ)matrice_small.o $(DIR_OBJ)main_small.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_matrix_big: $(DIR_OBJ)matrice_big.o $(DIR_OBJ)main_big.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_vect: $(DIR_OBJ)test_vect.o $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

test_vect_lib: $(DIR_OBJ)test_vect.o libvect.a
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $< $(DIR_LIB)libvect.a
	@echo -e

gen_aleat: $(DIR_OBJ)gen_aleat.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

libvect.a: $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	ar rvs $(DIR_LIB)$@ $^
	@echo -e

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#--------------
#		SMALL
#--------------
$(DIR_OBJ)main_small.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -fopenmp -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_small.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -fopenmp -c $< $(CFLAGS)
	@echo -e


#--------------
#		BIG
#--------------
$(DIR_OBJ)main_big.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -fopenmp -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_big.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -fopenmp -c $< $(CFLAGS)
	@echo -e


#--------------
#		Global
#--------------
$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)test_vect.o : $(DIR_SRC)test_vect.c $(DIR_INCLUDE)vecteur.h

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------

clean:
	rm -f $(DIR_OBJ)* $(DIR_EXE)* $(DIR_LIB)libvect.a
' >> MakefileOpenmpO3;

	#remplissage de MakefileNOpenmpO3
	echo -e '#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -O3 -std=c99 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = test_matrix_small test_matrix_big test_vect test_vect_lib gen_aleat libvect.a
DEBUG = 0
_OPENMP = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = libs/
DIR_EXE = target/debug/
DIR_OBJ = target/obj/

# MAT_SMALL = limit size of the cache = sqrt(99 225) = 315
# MAT_BIG = sqrt(302 500) = 550
MAT_SMALL = 315
MAT_BIG = 550

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

test_matrix_small: $(DIR_OBJ)matrice_small.o $(DIR_OBJ)main_small.o
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_EXE)$@ $^
	@echo -e

test_matrix_big: $(DIR_OBJ)matrice_big.o $(DIR_OBJ)main_big.o
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_EXE)$@ $^
	@echo -e

test_vect: $(DIR_OBJ)test_vect.o $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_EXE)$@ $^
	@echo -e

test_vect_lib: $(DIR_OBJ)test_vect.o libvect.a
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_EXE)$@ $< $(DIR_LIB)libvect.a
	@echo -e

gen_aleat: $(DIR_OBJ)gen_aleat.o
	@echo ------------- Generating $@ -------------
	$(CC) -o $(DIR_EXE)$@ $^
	@echo -e

libvect.a: $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	ar rvs $(DIR_LIB)$@ $^
	@echo -e

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#--------------
#		SMALL
#--------------
$(DIR_OBJ)main_small.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_small.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -c $< $(CFLAGS)
	@echo -e


#--------------
#		BIG
#--------------
$(DIR_OBJ)main_big.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_big.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -c $< $(CFLAGS)
	@echo -e


#--------------
#		Global
#--------------
$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)test_vect.o : $(DIR_SRC)test_vect.c $(DIR_INCLUDE)vecteur.h

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------

clean:
	rm -f $(DIR_OBJ)* $(DIR_EXE)* $(DIR_LIB)libvect.a
' >> MakefileNOpenmpO3;

echo '#-------------------------------------------------
#                    VARIABLES
#-------------------------------------------------
CC = gcc
CFLAGS = -g -Wall -pedantic -std=c99 -msse4.2 -Iinclude/
LFLAGS = -L$(DIR_LIB)
EXEC = test_matrix_small test_matrix_big test_vect test_vect_lib gen_aleat libvect.a
DEBUG = 0
_OPENMP = 0

DIR_INCLUDE = include/
DIR_SRC = src/
DIR_LIB = libs/
DIR_EXE = target/debug/
DIR_OBJ = target/obj/

# MAT_SMALL = limit size of the cache = sqrt(99 225) = 315 -- for vectorisation it has to be divisible by 4 --> 312
# MAT_BIG = sqrt(302 500) = 550 --> 548
MAT_SMALL = 312
MAT_BIG = 548

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXEC)

test_matrix_small: $(DIR_OBJ)matrice_small.o $(DIR_OBJ)main_small.o
	@echo ------------- Generating $@ -------------
	$(CC) -D_VECTOR -o $(DIR_EXE)$@ $^
	@echo -e

test_matrix_big: $(DIR_OBJ)matrice_big.o $(DIR_OBJ)main_big.o
	@echo ------------- Generating $@ -------------
	$(CC) -D_VECTOR -o $(DIR_EXE)$@ $^
	@echo -e

test_vect: $(DIR_OBJ)test_vect.o $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	$(CC) -D_VECTOR -o $(DIR_EXE)$@ $^
	@echo -e

test_vect_lib: $(DIR_OBJ)test_vect.o libvect.a
	@echo ------------- Generating $@ -------------
	$(CC) -D_VECTOR -o $(DIR_EXE)$@ $< $(DIR_LIB)libvect.a
	@echo -e

gen_aleat: $(DIR_OBJ)gen_aleat.o
	@echo ------------- Generating $@ -------------
	$(CC) -fopenmp -o $(DIR_EXE)$@ $^
	@echo -e

libvect.a: $(DIR_OBJ)vecteur.o
	@echo ------------- Generating $@ -------------
	ar rvs $(DIR_LIB)$@ $^
	@echo -e

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

$(DIR_OBJ)test_vect.o: $(DIR_SRC)test_vect.c $(DIR_INCLUDE)vecteur.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -D_VECTOR -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)vecteur.o: $(DIR_SRC)vecteur.c $(DIR_INCLUDE)vecteur.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -D_VECTOR -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

#--------------
#		SMALL
#--------------
$(DIR_OBJ)main_small.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -D_VECTOR -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_small.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_SMALL) -D_VECTOR -c $< $(CFLAGS)
	@echo -e

#--------------
#		BIG
#--------------
$(DIR_OBJ)main_big.o: $(DIR_SRC)main.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -D_VECTOR -DDEBUG=$(DEBUG) -c $< $(CFLAGS)
	@echo -e

$(DIR_OBJ)matrice_big.o: $(DIR_SRC)matrice.c $(DIR_INCLUDE)matrice.h
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -DN=$(MAT_BIG) -D_VECTOR -c $< $(CFLAGS)
	@echo -e


#--------------
#		Global
#--------------
$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@echo ------------- Generating $@ -------------
	$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------

clean:
	rm -f $(DIR_OBJ)* $(DIR_EXE)* $(DIR_LIB)libvect.a
' >> MakefileOpenmpO3SSE;
