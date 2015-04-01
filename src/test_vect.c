#include <stdio.h>
#include <stdlib.h>

#include "vecteur.h"

int main(int argc, char* argv[])
{
	VectSM sv1, sv2, sv3;
	VectBG bv1, bv2, bv3;

	VectFSM fsv1, fsv2, fsv3;
	VectFBG fbv1, fbv2, fbv3;

	double sc = 3.2456;

	if(argc == 4){
		switch(argv[1][0]){
			case 'd' :
				switch(argv[2][0]){
					case 's' :
						read_vect(sv1);
						read_vect(sv2);
						switch(argv[3][0]){
							case 'a' :
								printf("Affichage de l'addition : \n");
								add(sv1, sv2, sv3);
								print_vect(sv3);
								break;
							case 'm' :
								printf("Affichage de la multiplication par un scalaire : \n");
								mult (sv1, sc, sv3);
								print_vect(sv3);
								break;
							case 's' :
								printf("Affichage du produit scalaire : \n");
								scal (sv1, sv2, &sc);
								printf("%lf\n", sc);
								break;
							default :
								break;
						}
						break;

					case 'b' :
						read_vectBG(bv1);
						read_vectBG(bv2);
						switch(argv[3][0]){
							case 'a' :
								printf("Affichage de l'addition : \n");
								addBG(bv1, bv2, bv3);
								print_vectBG(bv3);
								break;
							case 'm' :
								printf("Affichage de la multiplication par un scalaire : \n");
								multBG(bv1, sc, bv3);
								print_vectBG(bv3);
								break;
							case 's' :
								printf("Affichage du produit scalaire : \n");
								scalBG(bv1, bv2, &sc);
								printf("%lf\n", sc);
								break;
							default :
								break;
						}
						break;
				}
				break;

			case 'f' :
				switch(argv[2][0]){
					case 's' :
						read_vectF(fsv1);
						read_vectF(fsv2);
						switch(argv[3][0]){
							case 'a' :
								printf("Affichage de l'addition : \n");
								addF(fsv1, fsv2, fsv3);
								print_vectF(fsv3);
								break;
							case 'm' :
								printf("Affichage de la multiplication par un scalaire : \n");
								multF(fsv1, sc, fsv3);
								print_vectF(fsv3);
								break;
							case 's' :
								printf("Affichage du produit scalaire : \n");
								scalF(fsv1, fsv2, &sc);
								printf("%lf\n", sc);
								break;
							default :
								break;
						}
						break;

					case 'b' :
						read_vectFBG(fbv1);
						read_vectFBG(fbv2);
						switch(argv[3][0]){
							case 'a' :
								printf("Affichage de l'addition : \n");
								addFBG(fbv1, fbv2, fbv3);
								print_vectFBG(fbv3);
								break;
							case 'm' :
								printf("Affichage de la multiplication par un scalaire : \n");
								multFBG(fbv1, sc, fbv3);
								print_vectFBG(fbv3);
								break;
							case 's' :
								printf("Affichage du produit scalaire : \n");
								scalFBG(fbv1, fbv2, &sc);
								printf("%lf\n", sc);
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
	}
	else
		printf("Erreur : [d ou f] [s ou b] [a ou m ou s]\n");

	return 0;
}