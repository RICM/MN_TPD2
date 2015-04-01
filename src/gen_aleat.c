#include <stdio.h>
#include <stdlib.h>

void init_db(int nb, FILE *file)
{
	int i;
	for(i=0; i<nb; i++)
		fprintf(file, "%lf\n", (((double)(rand()%2) == 0)? 1 : -1)*(double)rand()/(double)(RAND_MAX/10.0));
}

int main(int argc, char* argv[])
{
	FILE *file = NULL;
	int nb;

	if(argc == 3){
		sscanf(argv[1], "%d", &nb);
		file = fopen(argv[2], "w+");
		if (file != NULL){
			init_db(nb, file);
		}
		fclose(file);
	}
	else{
		printf("gen_aleat : [nb elem] [filename]\n");
	}
}