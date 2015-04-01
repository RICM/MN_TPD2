#include <stdio.h>
#include <stdlib.h>
 
#include "matrice.h"

MatriceD aD, bD, cD;
MatriceF aF, bF, cF;

VectD xD, yD;
VectF xF, yF;
 
void usage (void) {
  fprintf(stderr, "Usage : ./test_matrix_XXX [a/m/s/t/g] [int] [d/f]\n");
  exit(EXIT_FAILURE);
}


/********************************************************************************************************************/
/** Fonction non necessaire pour l'exécution du programme mais utile pour afficher la progression des calculs
    Copyright : https://wwww.ross.click/2011/02/creating-a-progress-bar-in-c-or-any-other-console-app/  **/
void avancement(int x, int n, int r, int w){
    if(x%(n/r +1) != 0) return ;

    float ratio = x/(float)n;
    int c = ratio*w;
    printf("%3d%% [", (int)(ratio*100));

    for(int x=0; x<c; x++)
        printf("=");
    for(int x=c; x<w; x++)
        printf(" ");

    printf("]\n\033[F\033[J");
}
/********************************************************************************************************************/
 
 
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
            	for (int i = 0; i<iteration; i++){
                    addD(aD, bD, cD);
                    avancement(i, iteration, 100, 50);
                }
            else
                for (int i = 0; i<iteration; i++){
                    addF(aF, bF, cF);
                    avancement(i, iteration, 100, 50);
                }
            break;
        case 'm':
            if (type == 'd')
                for (int i = 0; i<iteration; i++){
                    mulD(aD, bD, cD);
                    avancement(i, iteration, 100, 50);
                }
            else
                for (int i = 0; i<iteration; i++){
                    mulF(aF, bF, cF);
                    avancement(i, iteration, 100, 50);
                }
            break;
        case 's':
            if (type == 'd')
                for (int i = 0; i<iteration; i++){
                    scalD(aD, d, cD);
                    avancement(i, iteration, 100, 50);
                }
            else
                for (int i = 0; i<iteration; i++){
                    scalF(aF, f, cF);
                    avancement(i, iteration, 100, 50);
                }
            break;
        case 't':
            if (type == 'd')
                for (int i = 0; i<iteration; i++){
                    transD(aD, cD);
                    avancement(i, iteration, 100, 50);
                }
            else
       		    for (int i = 0; i<iteration; i++){
                    transF(aF, cF);
                    avancement(i, iteration, 100, 50);
                }
            break;
        case 'g':
            if (type == 'd'){
                getVectD(xD);
                getVectD(yD);
                for (int i = 0; i<iteration; i++){
                    gaxpyD(aD, xD, yD);
                    avancement(i, iteration, 100, 50);
                }
            }
            else{
                getVectF(xF);
                getVectF(yF);
                for (int i = 0; i<iteration; i++){
                    gaxpyF(aF, xF, yF);
                    avancement(i, iteration, 100, 50);
                }
            }
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


