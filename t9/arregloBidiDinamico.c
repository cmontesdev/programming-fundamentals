#include <stdio.h>
#include<stdlib.h>

void darDimMtz(int*,int*);
int ** crearMtz(int, int);
void darDatosMtz(int**, int,int);
void mostrarMtz(int**, int, int);
void liberarMtz(int**, int);

void main(){
	int fil, col, **mtz;
	darDimMtz(&fil, &col);
	mtz= crearMtz(fil, col);
	darDatosMtz(mtz, fil, col);
	mostrarMtz(mtz, fil, col);
	liberarMtz(mtz, fil);
}

void darDimMtz(int * fil, int * col){
	printf("\nIndique el numero de filas: ");
	scanf("%d", fil);
	printf("Indique el numero de columnas: ");
	scanf("%d", col);
}

int ** crearMtz(int fil, int col){
	int ** mtz, i;
	mtz=(int**) malloc(fil*sizeof(int*));
	if(mtz==NULL){
		printf("\nNo hay memoria disponible.");
		exit(0);
	}
	for(i=0;i<fil;i++){
		mtz[i]=(int*) malloc(sizeof(int)*col);
	}
	return mtz;
}

void darDatosMtz(int** mtz, int fil, int col){
	int i,j;
	printf("\nIngrese los datos de la matriz\n");
	for(i=0;i<fil;i++)
		for(j=0;j<col;j++){
		printf("Dato[%d][%d]= ", i+1, j+1);
		scanf("%d", &mtz[i][j]);
		}	
}

void mostrarMtz(int **mtz, int fil, int col){
	int i, j;
	printf("\nLos datos de la matriz son: \n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%d ", mtz[i][j]);
		printf("\n");
	}
}

void liberarMtz(int**mtz, int fil){
	int i;
	for(i=0;i<fil;i++)
		free(mtz[i]);
	free(mtz);
	printf("\nMemoria liberada.\n\n");
}