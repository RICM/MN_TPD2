#include <stdio.h>
#include <stdlib.h>
#include <nmmintrin.h>
#include "matrice.h"

/****************************************************************/
/*						Used for _OPENMP 						*/
/****************************************************************/
#ifdef _OPENMP
#include <omp.h>
#endif
/****************************************************************/
/*							Operations							*/
/****************************************************************/


/********************************************************/
/*						  Double						*/
/********************************************************/

/** Transposition of a matrix **/
void transD (MatriceD a, MatriceD res){
	#ifdef _OPENMP
	int i;
	int j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[j][i];
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[j][i];
	#endif
}

/** Addition of 2 matrix **/
void addD (MatriceD a, MatriceD b, MatriceD res){
	#ifdef _OPENMP
		int i;
		int j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[i][j] + b[i][j];
	#elif _VECTOR
		__m128d aTmp, bTmp, resTmp;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j+=2) {
				aTmp = _mm_load_pd(a[i]+j);
				bTmp = _mm_load_pd(b[i]+j);
				resTmp = _mm_add_pd(aTmp,bTmp);
				_mm_store_pd(res[i]+j,resTmp);
			}
		}
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[i][j] + b[i][j];
	#endif
}

/** Multiplication of 2 matrix **/
void mulD (MatriceD a, MatriceD b, MatriceD res){
	double sum;
	#ifdef _OPENMP
		int i;
		int j;
		int k;
	#pragma omp parallel for private(i,j,k)
		for(i = 0; i<N; i++){
			for(j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(k = 0; k<N; k++)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
	#elif _VECTOR
		__m128d aTmp, bTmp, resTmp, tmp;
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k+=2){

					aTmp = _mm_load_pd(a[i]+k);

					bTmp[0] = b[k][j];
					bTmp[1] = b[k+1][j];

					resTmp = _mm_mul_pd(aTmp, bTmp);
					tmp = _mm_hadd_pd(resTmp, resTmp);
					sum += tmp[0];
				}
				res[i][j] = sum;
			}
		}
	#else
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k++)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
	#endif
}

/** Multiplication of a matrix by a real **/
void scalD (MatriceD a, double s, MatriceD res){
	#ifdef _OPENMP
		int i;
		int j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[i][j]*s;
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[i][j]*s;
	#endif
}

/** Gaxpy of a matrix by an array**/
void gaxpyD (MatriceD a, VectD x, VectD y){
	#ifdef _OPENMP
		int i,j;
	#pragma omp parallel for private(i,j)
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				y[i] += a[i][j]*x[j];
	#else
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				y[i] += a[i][j]*x[j];
	#endif
}

void factLUD (MatriceD a, MatriceD L, MatriceD U){
	float sum;
	#ifdef _OPENMP
		int i,j,k;
	#pragma omp parallel for private(i,j,k)
		for(i=0; i<N; i++)
			for(j=0; j<N; j++){
				if(i == j)
					L[i][j] = 1.;
				else
					L[i][j] = 0.;
				U[i][j] = 0.;
			}

		for(i=0; i<N-1; i++){
			for(j=i; j<N; j++){
				sum = 0.;
				for(k=0; k<i; k++)
					sum += L[i][k]*U[k][j];
				U[i][j] = a[i][j] - sum;
			}
			for(j=i+1; j<N; j++){
				sum = 0.;
				for(k=0; k<i; k++)
					sum += L[j][k]*U[k][i];
				L[j][i] = (1./U[i][i]) * (a[j][i] - sum);
			}
		}

		sum = 0.;
		for(k=0; k<N-1; k++)
			sum += L[N-1][k]*U[k][N-1];
		U[N-1][N-1] = a[N-1][N-1] - sum;
	#else
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++){
				if(i == j)
					L[i][j] = 1.;
				else
					L[i][j] = 0.;
				U[i][j] = 0.;
			}

		for(int i=0; i<N-1; i++){
			for(int j=i; j<N; j++){
				sum = 0.;
				for(int k=0; k<i; k++)
					sum += L[i][k]*U[k][j];
				U[i][j] = a[i][j] - sum;
			}
			for(int j=i+1; j<N; j++){
				sum = 0.;
				for(int k=0; k<i; k++)
					sum += L[j][k]*U[k][i];
				L[j][i] = (1./U[i][i]) * (a[j][i] - sum);
			}
		}

		sum = 0.;
		for(int k=0; k<N-1; k++)
			sum += L[N-1][k]*U[k][N-1];
		U[N-1][N-1] = a[N-1][N-1] - sum;
	#endif
}

/********************************************************/
/*						   Float						*/
/********************************************************/

/** Transposition of a matrix **/
void transF (MatriceF a, MatriceF res){
	#ifdef _OPENMP
		 int i;
		 int j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[j][i];
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[j][i];
	#endif
}

/** Addition of 2 matrix **/
void addF (MatriceF a, MatriceF b, MatriceF res){
	#ifdef _OPENMP
		int i;
		int j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[i][j] + b[i][j];
	#elif _VECTOR
		__m128 aTmp, bTmp, resTmp;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j+=4) {
				aTmp = _mm_load_ps(a[i]+j);
				bTmp = _mm_load_ps(b[i]+j);
				resTmp = _mm_add_ps(aTmp,bTmp);
				_mm_store_ps(res[i]+j,resTmp);
			}
		}
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[i][j] + b[i][j];
	#endif
}

/** Multiplication of 2 matrix **/
void mulF (MatriceF a, MatriceF b, MatriceF res){
	float sum;
	#ifdef _OPENMP
		 int i,j,k;
	#pragma omp parallel for private(i,j,k,sum)
		for(i = 0; i<N; i++){
			for(j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(k = 0; k<N; k++)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
	#elif _VECTOR
		__m128 aTmp, bTmp, resTmp, tmp;
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k+=4){

					aTmp = _mm_load_ps(a[i]+k);

					bTmp[0] = b[k][j];
					bTmp[1] = b[k+1][j];
					bTmp[2] = b[k+2][j];
					bTmp[3] = b[k+3][j];

					resTmp = _mm_mul_ps(aTmp, bTmp);
					tmp = _mm_hadd_ps(resTmp, resTmp);
					sum += tmp[0]+tmp[1];
				}
				res[i][j] = sum;
			}
		}
	#else
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k++)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
	#endif
}

/** Multiplication of a matrix by a real **/
void scalF (MatriceF a, float s, MatriceF res){
	#ifdef _OPENMP
		int i,j;
	#pragma omp parallel for private(i,j)
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
				res[i][j] = a[i][j]*s;
	#else
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				res[i][j] = a[i][j]*s;
	#endif
}

/** Gaxpy of a matrix by an array**/
void gaxpyF (MatriceF a, VectF x, VectF y){
	#ifdef _OPENMP
		int i,j;
	#pragma omp parallel for private(i,j)
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				y[i] += a[i][j]*x[j];
	#else
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				y[i] += a[i][j]*x[j];
	#endif
}

void factLUF (MatriceF a, MatriceF L, MatriceF U){
	float sum;
	#ifdef _OPENMP
		int i,j,k;
	#pragma omp parallel for private(i,j,k)
		for(i=0; i<N; i++)
			for(j=0; j<N; j++){
				if(i == j)
					L[i][j] = 1.;
				else
					L[i][j] = 0.;
				U[i][j] = 0.;
			}
		
		for(i=0; i<N-1; i++){
			for(j=i; j<N; j++){
				sum = 0.;
				for(k=0; k<i; k++)
					sum += L[i][k]*U[k][j];
				U[i][j] = a[i][j] - sum;
			}
			for(j=i+1; j<N; j++){
				sum = 0.;
				for(k=0; k<i; k++)
					sum += L[j][k]*U[k][i];
				L[j][i] = (1./U[i][i]) * (a[j][i] - sum);
			}
		}

		sum = 0.;
		for(k=0; k<N-1; k++)
			sum += L[N-1][k]*U[k][N-1];
		U[N-1][N-1] = a[N-1][N-1] - sum;
	#else
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++){
				if(i == j)
					L[i][j] = 1.;
				else
					L[i][j] = 0.;
				U[i][j] = 0.;
			}

		for(int i=0; i<N-1; i++){
			for(int j=i; j<N; j++){
				sum = 0.;
				for(int k=0; k<i; k++)
					sum += L[i][k]*U[k][j];
				U[i][j] = a[i][j] - sum;
			}
			for(int j=i+1; j<N; j++){
				sum = 0.;
				for(int k=0; k<i; k++)
					sum += L[j][k]*U[k][i];
				L[j][i] = (1./U[i][i]) * (a[j][i] - sum);
			}
		}

		sum = 0.;
		for(int k=0; k<N-1; k++)
			sum += L[N-1][k]*U[k][N-1];
		U[N-1][N-1] = a[N-1][N-1] - sum;
	#endif
}


/****************************************************************/
/*  					Printer / Initialiser					*/
/****************************************************************/


/********************************************************/
/*						  Double						*/
/********************************************************/

#ifdef _OPENMP
	#define NUM_THREADS 4
#endif

void printMatD (MatriceD a){
	for(int i = 0; i<N; i++){
		printf("(\t");
		for(int j = 0; j<N; j++)
			printf("%lf\t", a[i][j]);
		printf(")\n");
	}
	printf("\n");
}

void getMatD (MatriceD a){
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			scanf("%lf", &a[i][j]);
}


/********************************************************/
/*						   Float						*/
/********************************************************/

void printMatF (MatriceF a){
	for(int i = 0; i<N; i++){
		printf("(\t");
		for(int j = 0; j<N; j++)
			printf("%f\t", a[i][j]);
		printf(")\n");
	}
	printf("\n");
}

void getMatF (MatriceF a){
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			scanf("%f", &a[i][j]);
}

void getVectD (VectD a){
	for(int i=0; i<N; i++)
		scanf("%lf", &a[i]);
}

void getVectF (VectF a){
	for(int i=0; i<N; i++)
		scanf("%f", &a[i]);
}
