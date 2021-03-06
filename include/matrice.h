typedef double MatriceD[N][N] __attribute__((aligned (16)));
typedef float MatriceF[N][N] __attribute__((aligned (16)));

typedef double VectD[N] __attribute__((aligned (16)));
typedef float VectF[N] __attribute__((aligned (16)));

/* Operations */

void transD (MatriceD a, MatriceD res);
void addD (MatriceD a, MatriceD b, MatriceD res);
void mulD (MatriceD a, MatriceD b, MatriceD res);
void scalD (MatriceD a, double s, MatriceD res);
void gaxpyD (MatriceD a, VectD x, VectD y);
void factLUD (MatriceD a, MatriceD L, MatriceD U);

void transF (MatriceF a, MatriceF res);
void addF (MatriceF a, MatriceF b, MatriceF res);
void mulF (MatriceF a, MatriceF b, MatriceF res);
void scalF (MatriceF a, float s, MatriceF res);
void gaxpyF (MatriceF a, VectF x, VectF y);
void factLUF (MatriceF a, MatriceF L, MatriceF U);


/* Printer and initialiser */

void printMatD (MatriceD a);
void initMatD (MatriceD a);
void getMatD (MatriceD a);

void printMatF (MatriceF a);
void initMatF (MatriceF a);
void getMatF (MatriceF a);

void getVectD (VectD a);
void getVectF (VectF a);
