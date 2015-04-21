#include <stdio.h>
#include <stdlib.h>
#include <nmmintrin.h>

#include "vecteur.h"

#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

#define BLOCAGE 2048

/*****************************************************/
/*					Vecteur double  	             */
/*****************************************************/

void add (VectSM v1, VectSM v2, VectSM v3)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v3[j] = v1[j]+v2[j];
		}
	#elif _VECTOR
		__m128d a, b;
		for(int i=0; i<SMALL; i+=2){
			a = _mm_load_pd(v1+i);
			b = _mm_load_pd(v2+i);
			_mm_store_pd(v3+i,_mm_add_pd(a, b));
		}
	#else
		for(int i=0; i<SMALL; i++)
			v3[i] = v1[i]+v2[i];
	#endif
}

void mult (VectSM v1, double s, VectSM v2)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v2[j] = v1[j]*s;
		}
	#else
		for(int i=0; i<SMALL; i++)
			v2[i] = v1[i]*s;
	#endif
}

void scal (VectSM v1, VectSM v2, double *s)
{
	#ifdef _OPENMP
		double res = 0.0;
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for reduction (*:res) private (i)
				for(j=i; j<i+BLOCAGE; j++)
					res += v1[i]*v2[i];
		}
		*s = res;
	#elif _VECTOR
		__m128d a, b, res;
		*s = 0;
		for(int i=0; i<SMALL; i+=2){
			a = _mm_load_pd(v1+i);
			b = _mm_load_pd(v2+i);

			res = _mm_dp_pd(a, b, 0xFF);

			*s += res[0];
		}	
	#else
		*s = 0;
			for(int i=0; i<SMALL; i++)
				*s += v1[i]*v2[i];
	#endif
}

/***/

void addBG (VectBG v1, VectBG v2, VectBG v3)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v3[j] = v1[j]+v2[j];
		}
	#elif _VECTOR
		__m128d a, b;
		for(int i=0; i<BIG; i+=2){
			a = _mm_load_pd(v1+i);
			b = _mm_load_pd(v2+i);
			_mm_store_pd(v3+i,_mm_add_pd(a, b));
		}
	#else
		for(int i=0; i<BIG; i++)
			v3[i] = v1[i]+v2[i];
	#endif
}

void multBG (VectBG v1, double s, VectBG v2)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v2[j] = v1[j]*s;
		}
	#else
		for(int i=0; i<BIG; i++)
			v2[i] = v1[i]*s;
	#endif
}

void scalBG (VectBG v1, VectBG v2, double *s)
{
	#ifdef _OPENMP
		double res = 0.0;
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for reduction (*:res) private (i)
				for(j=i; j<i+BLOCAGE; j++)
					res += v1[i]*v2[i];
		}
		*s = res;
	#elif _VECTOR
		__m128d a, b, res;
		*s = 0;
		for(int i=0; i<BIG; i+=2){
			a = _mm_load_pd(v1+i);
			b = _mm_load_pd(v2+i);

			res = _mm_dp_pd(a, b, 0xFF);

			*s += res[0];
		}
	#else
		*s = 0;
			for(int i=0; i<BIG; i++)
				*s += v1[i]*v2[i];
	#endif
}

/*****************************************************/
/*					Vecteur float   	             */
/*****************************************************/

void addF (VectFSM v1, VectFSM v2, VectFSM v3)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v3[j] = v1[j]+v2[j];
		}
	#elif _VECTOR
		__m128 a, b;
		for(int i=0; i<SMALL; i+=4){
			a = _mm_load_ps(v1+i);
			b = _mm_load_ps(v2+i);
			_mm_store_ps(v3+i,_mm_add_ps(a, b));
		}
	#else
		for(int i=0; i<SMALL; i++)
			v3[i] = v1[i]+v2[i];
	#endif
}

void multF (VectFSM v1, double s, VectFSM v2)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v2[j] = v1[j]*s;
		}
	#else
		for(int i=0; i<SMALL; i++)
			v2[i] = v1[i]*s;
	#endif
}

void scalF (VectFSM v1, VectFSM v2, double *s)
{
	#ifdef _OPENMP
		double res = 0.0;
		int i, j;
		for(i=0; i<SMALL; i+=BLOCAGE){
			#pragma omp parallel for reduction (*:res) private (i)
				for(j=i; j<i+BLOCAGE; j++)
					res += v1[i]*v2[i];
		}
		*s = res;
	#elif _VECTOR
		*s = 0;
		__m128 a, b, res;
		for(int i=0; i<SMALL; i+=4){
			a = _mm_load_ps(v1+i);
			b = _mm_load_ps(v2+i);

			res = _mm_dp_ps(a, b, 0xFF);

			*s += res[0];
		}
	#else
		*s = 0;
			for(int i=0; i<SMALL; i++)
				*s += v1[i]*v2[i];
	#endif
}

/***/

void addFBG (VectFBG v1, VectFBG v2, VectFBG v3)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v3[j] = v1[j]+v2[j];
		}
	#elif _VECTOR
		__m128 a, b;
		for(int i=0; i<BIG; i+=4){
			a = _mm_load_ps(v1+i);
			b = _mm_load_ps(v2+i);
			_mm_store_ps(v3+i,_mm_add_ps(a, b));
		}
	#else
		for(int i=0; i<BIG; i++)
			v3[i] = v1[i]+v2[i];
	#endif
}

void multFBG (VectFBG v1, double s, VectFBG v2)
{
	#ifdef _OPENMP
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for private (i)
				for(j=i; j<i+BLOCAGE; j++)
					v2[j] = v1[j]*s;
		}
	#else
		for(int i=0; i<BIG; i++)
			v2[i] = v1[i]*s;
	#endif
}

void scalFBG (VectFBG v1, VectFBG v2, double *s)
{
	#ifdef _OPENMP
		double res = 0.0;
		int i, j;
		for(i=0; i<BIG; i+=BLOCAGE){
			#pragma omp parallel for reduction (*:res) private (i)
				for(j=i; j<i+BLOCAGE; j++)
					res += v1[i]*v2[i];
		}
		*s = res;
	#elif _VECTOR
		__m128 a, b, res;
		*s = 0;
		for(int i=0; i<BIG; i+=4){
			a = _mm_load_ps(v1+i);
			b = _mm_load_ps(v2+i);

			res = _mm_dp_ps(a, b, 0xFF);

			*s += res[0];
		}
	#else
		*s = 0;
			for(int i=0; i<BIG; i++)
				*s += v1[i]*v2[i];
	#endif
}

/*****************************************************/
/*					Vecteur double  	             */
/*****************************************************/

void read_vect(VectSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
	{
		if(DEBUG)
			printf("Composante %d : ", i);	
		scanf("%lf", &v[i]);
	}
}

void print_vect(VectSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
		if(DEBUG)
			printf("Composante %d : %lf\n", i, v[i]);
}

/***/

void read_vectBG(VectBG v)
{
	int i;
	for(i=0; i<BIG; i++)
	{
		if(DEBUG)
			printf("Composante %d : ", i);	
		scanf("%lf", &v[i]);
	}
}

void print_vectBG(VectBG v)
{
	int i;
	for(i=0; i<BIG; i++)
		if(DEBUG)
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
		if(DEBUG)
			printf("Composante %d : ", i);	
		scanf("%f", &v[i]);
	}
}

void print_vectF(VectFSM v)
{
	int i;
	for(i=0; i<SMALL; i++)
		if(DEBUG)
			printf("Composante %d : %f\n", i, v[i]);
}

/***/

void read_vectFBG(VectFBG v)
{
	int i;
	for(i=0; i<BIG; i++)
	{
		if(DEBUG)
			printf("Composante %d : ", i);	
		scanf("%f", &v[i]);
	}
}

void print_vectFBG(VectFBG v)
{
	int i;
	for(i=0; i<BIG; i++)
		if(DEBUG)
			printf("Composante %d : %f\n", i, v[i]);
}
