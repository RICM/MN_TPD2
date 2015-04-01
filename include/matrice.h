#define BORNEINF 	0
#define BORNESUP 	10

typedef double MatriceD[N][N];
typedef float MatriceF[N][N];

typedef double VectD[N];
typedef float VectF[N];

/* Operations */

void transD (MatriceD a, MatriceD res);
void addD (MatriceD a, MatriceD b, MatriceD res);
void mulD (MatriceD a, MatriceD b, MatriceD res);
void scalD (MatriceD a, double s, MatriceD res);
void gaxpyD (MatriceD a, VectD x, VectD y);

void transF (MatriceF a, MatriceF res);
void addF (MatriceF a, MatriceF b, MatriceF res);
void mulF (MatriceF a, MatriceF b, MatriceF res);
void scalF (MatriceF a, float s, MatriceF res);
void gaxpyF (MatriceF a, VectF x, VectF y);


/* Printer and initialiser */

void printMatD (MatriceD a);
void initMatD (MatriceD a);
void getMatD (MatriceD a);

void printMatF (MatriceF a);
void initMatF (MatriceF a);
void getMatF (MatriceF a);
