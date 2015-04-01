#include <stdio.h>
#include <stdlib.h>

#include "vecteur.h"

/*****************************************************/
/*					Vecteur double  	             */
/*****************************************************/

void add (VectSM v1, VectSM v2, VectSM v3)
{
	int i;
	for(i=0; i<SMALL; i++)
		v3[i] = v1[i]+v2[i];
}

void mult (VectSM v1, double s, VectSM v2)
{
	int i;
	for(i=0; i<SMALL; i++)
		v2[i] = v1[i]*s;
}

void scal (VectSM v1, VectSM v2, double *s)
{
	int i;
	*s = 0;
	for(i=0; i<SMALL; i++)
		*s += v1[i]*v2[i];
}

/***/

void addBG (VectBG v1, VectBG v2, VectBG v3)
{
	int i;
	for(i=0; i<BIG; i++)
		v3[i] = v1[i]+v2[i];
}

void multBG (VectBG v1, double s, VectBG v2)
{
	int i;
	for(i=0; i<BIG; i++)
		v2[i] = v1[i]*s;
}

void scalBG (VectBG v1, VectBG v2, double *s)
{
	int i;
	*s = 0;
	for(i=0; i<BIG; i++)
		*s += v1[i]*v2[i];
}

/*****************************************************/
/*					Vecteur float   	             */
/*****************************************************/

void addF (VectFSM v1, VectFSM v2, VectFSM v3)
{
	int i;
	for(i=0; i<SMALL; i++)
		v3[i] = v1[i]+v2[i];
}

void multF (VectFSM v1, double s, VectFSM v2)
{
	int i;
	for(i=0; i<SMALL; i++)
		v2[i] = v1[i]*s;
}

void scalF (VectFSM v1, VectFSM v2, double *s)
{
	int i;
	*s = 0;
	for(i=0; i<SMALL; i++)
		*s += v1[i]*v2[i];
}

/***/

void addFBG (VectFBG v1, VectFBG v2, VectFBG v3)
{
	int i;
	for(i=0; i<BIG; i++)
		v3[i] = v1[i]+v2[i];
}

void multFBG (VectFBG v1, double s, VectFBG v2)
{
	int i;
	for(i=0; i<BIG; i++)
		v2[i] = v1[i]*s;
}

void scalFBG (VectFBG v1, VectFBG v2, double *s)
{
	int i;
	*s = 0;
	for(i=0; i<BIG; i++)
		*s += v1[i]*v2[i];
}

/*****************************************************/
/*					Vecteur double  	             */
/*****************************************************/

void read_vect(VectSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
	{
		printf("Composante %d : ", i);	
		scanf("%lf", &v[i]);
	}
}

void print_vect(VectSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
		printf("Composante %d : %lf\n", i, v[i]);
}

/***/

void read_vectBG(VectBG v)
{
	int i;
	for(i=0; i<BIG; i++)
	{
		printf("Composante %d : ", i);	
		scanf("%lf", &v[i]);
	}
}

void print_vectBG(VectBG v)
{
	int i;
	for(i=0; i<BIG; i++)
		printf("Composante %d : %lf\n", i, v[i]);
}

/*****************************************************/
/*					Vecteur float   	             */
/*****************************************************/

void read_vectF(VectFSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
	{
		printf("Composante %d : ", i);	
		scanf("%f", &v[i]);
	}
}

void print_vectF(VectFSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
		printf("Composante %d : %f\n", i, v[i]);
}

/***/

void read_vectFBG(VectFBG v)
{
	int i;
	for(i=0; i<BIG; i++)
	{
		printf("Composante %d : ", i);	
		scanf("%f", &v[i]);
	}
}

void print_vectFBG(VectFBG v)
{
	int i;
	for(i=0; i<BIG; i++)
		printf("Composante %d : %f\n", i, v[i]);
}
