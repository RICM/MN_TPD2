#include <stdio.h>
#include <stdlib.h>

#include "vecteur.h"

void usage (void) {
  fprintf(stderr, "Usage : ./test_vect [d ou f] [s ou b] [a ou m ou s] [int]\n");
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

int main(int argc, char* argv[])
{
	VectSM sv1, sv2, sv3;
	VectBG bv1, bv2, bv3;

	VectFSM fsv1, fsv2, fsv3;
	VectFBG fbv1, fbv2, fbv3;

	double sc = 3.2456;

	char operation;
    int iteration;
    char type;
    char taille;

    if (argc != 5 || sscanf (argv[1],"%c",&type) != 1
    		|| sscanf (argv[2],"%c",&taille) != 1	
    		|| sscanf (argv[3],"%c",&operation) != 1	
    		|| sscanf (argv[4],"%d",&iteration) != 1)
    	usage();
	if (operation != 'a' && operation != 'm' && operation != 's'
			&& operation != 'l' && operation !='t' && operation != 'g' && operation != 'f')
    	usage();
    if (taille != 's' && taille != 'b')
        usage();
    if (type != 'd' && type != 'f')
        usage();

	switch(type){
		case 'd' :
			switch(taille){
				case 's' :
					read_vect(sv1);
					read_vect(sv2);
					switch(operation){
						case 'a' :
							for (int i = 0; i<iteration; i++){
								add(sv1, sv2, sv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de l'addition : \n");
								print_vect(sv3);
							}
							break;
						case 'm' :
							for (int i = 0; i<iteration; i++){
								mult (sv1, sc, sv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de la multiplication par un scalaire : \n");
								print_vect(sv3);
							}
							break;
						case 's' :
							for (int i = 0; i<iteration; i++){
								scal (sv1, sv2, &sc);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage du produit scalaire : \n");
								printf("%lf\n", sc);
							}
							break;
						default :
							break;
					}
					break;

				case 'b' :
					read_vectBG(bv1);
					read_vectBG(bv2);
					switch(operation){
						case 'a' :
							for (int i = 0; i<iteration; i++){
								addBG(bv1, bv2, bv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de l'addition : \n");
								print_vectBG(bv3);
							}
							break;
						case 'm' :
							for (int i = 0; i<iteration; i++){
								multBG(bv1, sc, bv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de la multiplication par un scalaire : \n");
								print_vectBG(bv3);
							}
							break;
						case 's' :
							for (int i = 0; i<iteration; i++){
								scalBG(bv1, bv2, &sc);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage du produit scalaire : \n");
								printf("%lf\n", sc);
							}
							break;
						default :
							break;
					}
					break;
			}
			break;

		case 'f' :
			switch(taille){
				case 's' :
					read_vectF(fsv1);
					read_vectF(fsv2);
					switch(operation){
						case 'a' :
							for (int i = 0; i<iteration; i++){
								addF(fsv1, fsv2, fsv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de l'addition : \n");
								print_vectF(fsv3);
							}
							break;
						case 'm' :
							for (int i = 0; i<iteration; i++){
								multF(fsv1, sc, fsv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de la multiplication par un scalaire : \n");
								print_vectF(fsv3);
							}
							break;
						case 's' :
							for (int i = 0; i<iteration; i++){
								scalF(fsv1, fsv2, &sc);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage du produit scalaire : \n");
								printf("%lf\n", sc);
							}
							break;
						default :
							break;
					}
					break;

				case 'b' :
					read_vectFBG(fbv1);
					read_vectFBG(fbv2);
					switch(operation){
						case 'a' :
							for (int i = 0; i<iteration; i++){
								addFBG(fbv1, fbv2, fbv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de l'addition : \n");
								print_vectFBG(fbv3);
							}
							break;
						case 'm' :
							for (int i = 0; i<iteration; i++){
								multFBG(fbv1, sc, fbv3);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage de la multiplication par un scalaire : \n");
								print_vectFBG(fbv3);
							}
							break;
						case 's' :
							for (int i = 0; i<iteration; i++){
								scalFBG(fbv1, fbv2, &sc);
                				avancement(i, iteration, 100, 50);
            				}
							if(DEBUG){
								printf("Affichage du produit scalaire : \n");
								printf("%lf\n", sc);
							}
							break;
						default :
							break;
					}
					break;
			}
			break;

		default :
			break;
	}

	return 0;
}