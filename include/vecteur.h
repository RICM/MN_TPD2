#define SMALL 	1000
#define BIG		100000

// double 2048*1000/(3*8) ~ 85 000

typedef double VectSM[SMALL];
typedef double VectBG[BIG];

typedef float VectFSM[SMALL];
typedef float VectFBG[BIG];

void add (VectSM v1, VectSM v2, VectSM v3);
void mult (VectSM v1, double s, VectSM v2);
void scal (VectSM v1, VectSM v2, double *s);

void addBG (VectBG v1, VectBG v2, VectBG v3);
void multBG (VectBG v1, double s, VectBG v2);
void scalBG (VectBG v1, VectBG v2, double *s);

void addF (VectFSM v1, VectFSM v2, VectFSM v3);
void multF (VectFSM v1, double s, VectFSM v2);
void scalF (VectFSM v1, VectFSM v2, double *s);

void addFBG (VectFBG v1, VectFBG v2, VectFBG v3);
void multFBG (VectFBG v1, double s, VectFBG v2);
void scalFBG (VectFBG v1, VectFBG v2, double *s);

void read_vect(VectSM v);
void print_vect(VectSM v);

void read_vectBG(VectBG v);
void print_vectBG(VectBG v);

void read_vectF(VectFSM v);
void print_vectF(VectFSM v);

void read_vectFBG(VectFBG v);
void print_vectFBG(VectFBG v);