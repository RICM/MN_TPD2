#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

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
		for(i = 0; i<N; i++)
			for(j = 0; j<N; j++)
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
					sum += a[j][k] * b[k][i];
				res[i][j] = sum;
			}
		}
	#else
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k++)
					sum += a[j][k] * b[k][i];
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
		for(int j = 0; j<N; j++)
			res[i][j] = a[i][j]*s;
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
					sum += a[j][k] * b[k][i];
				res[i][j] = sum;
			}
		}
	#else
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				sum = 0.0;
				// calcule de sum
				for(int k = 0; k<N; k++)
					sum += a[j][k] * b[k][i];
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
