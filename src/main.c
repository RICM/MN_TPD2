#include <stdio.h>
#include <stdlib.h>
 
#include "matrice.h"

MatriceD aD, bD, cD;
MatriceF aF, bF, cF;
 
void usage (void) {
  fprintf(stderr, "Usage : ./test_matrix_XXX [a/m/s/t/g] [int] [d/f]\n");
  exit(EXIT_FAILURE);
}
 
int main (int argc, char **argv){

    char operation;
    int iteration;
    char type;

    if (argc != 4 || sscanf (argv[1],"%c",&operation) != 1 
    		|| sscanf (argv[2],"%d",&iteration) != 1 
    		|| sscanf (argv[3],"%c",&type) != 1)
    	usage();
	if (operation != 'a' && operation != 'm' && operation != 's' 
			&& operation != 'l' && operation !='t' && operation != 'g')
    	usage();
    if (type != 'd' && type != 'f')
        usage();

    

    double d = (double)rand()/(double)(RAND_MAX/100.0);
	float f = (float)rand()/(float)(RAND_MAX/100.0);

	if(type == 'd'){
		getMatD(aD);
		getMatD(bD);
	}
	else{
		getMatF(aF);
		getMatF(bF);
	}

	if(DEBUG){
	    printf("Création de la matrice a de taille %d réussie. a = \n", N);
	    if(type == 'd')
	    	printMatD(aD);
	   	else
	   		printMatF(aF);

	    printf("Création de la matrice b de taille %d réussie. b = \n", N);
	    if(type == 'd')
	    	printMatD(bD);
	   	else
	   		printMatF(bF);
   	}

	switch (operation){
        case 'a':
            if (type == 'd')
            	for (int i = 0; i<iteration; i++)
                    addD(aD, bD, cD);
            else
                for (int i = 0; i<iteration; i++)
                    addF(aF, bF, cF);
            break;
        case 'm':
            if (type == 'd')
                for (int i = 0; i<iteration; i++)
                    mulD(aD, bD, cD);
            else
                for (int i = 0; i<iteration; i++)
                    mulF(aF, bF, cF);
            break;
        case 's':
            if (type == 'd')
                for (int i = 0; i<iteration; i++)
                    scalD(aD, d, cD);
            else
                for (int i = 0; i<iteration; i++)
                    scalF(aF, f, cF);
            break;
        case 't':
            if (type == 'd')
                for (int i = 0; i<iteration; i++)
                    transD(aD, cD);
            else
       		    for (int i = 0; i<iteration; i++)
                    transF(aF, cF);
            break;
        case 'g':
                //todo
                break;
        default:
                break;
    }

    if(DEBUG){
    	printf("Matrice resultat de taille %d =\n", N);
	    if(type == 'd')
	    	printMatD(cD);
	   	else
	   		printMatF(cF);
	   	printf("Nombre d'iterations = %d.\n", iteration);
   	}

    //TODO
    //OPENMP
    return EXIT_SUCCESS;
}


