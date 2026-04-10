#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dimensiones(int*);
int ** crearMtz(int*);
void datos(int**, int**, int*);
float * arregloU(int*);
void operaciones(int**,int**,float*,int*);
void mostrar(float*, int*);
void liberar(int**, int**, float*, int*);

void main(){
	int **A, **B, dim;
	float *C;
	dimensiones(&dim);
	A=crearMtz(&dim);
	B=crearMtz(&dim);
	datos(A, B, &dim);
	C=arregloU(&dim);
	operaciones(A,B,C,&dim);
	mostrar(C,&dim);
	liberar(A,B,C,&dim);
}

void dimensiones(int * dim){
	printf("\n\nIngrese las dimensiones de la matrices (un numero N que creará dos matrices NxN): ");
	scanf("%d", dim);
}

int ** crearMtz(int * dim){
	int ** mtz, i;
	mtz=(int**) malloc((*dim)*sizeof(int*));
	if(mtz==NULL){
		printf("\nNo hay memoria disponible.");
		exit(0);
	}
	for(i=0;i<(*dim);i++){
		mtz[i]=(int*) malloc((*dim)*sizeof(int));
	}
	return mtz;
}

void datos(int** A, int** B, int * dim){
	int i,j,k;
	for(k=0;k<2;k++){
		if(k==0) printf("\nIngrese los datos de la matriz 1:\n");
		else if(k==1) printf("\nIngrese los datos de la matriz 2:\n");
		for(i=0;i<(*dim);i++) 
			for(j=0;j<(*dim);j++){
			printf("Dato[%d][%d]= ", i+1, j+1);
			if(k==0) scanf("%d", &A[i][j]);
			else if(k==1) scanf("%d", &B[i][j]);
			}	
	}
}

float * arregloU(int * dim){
	float * C;
	C=(float*) malloc((*dim)*sizeof(float));
	if(C==NULL){
		printf("\nNo hay memoria disponible para crear una tercera matriz.\n");
		exit(0);
	}	
	return C;
}

void operaciones(int ** A, int ** B, float * C, int * dim){
	int i,j,k, menor=0, pos=0;
	float prom;
	for(i=0;i<(*dim);i++){
		prom=0;
		for(j=0;j<(*dim);j++){
			prom=prom+A[i][j];
		}
		prom=prom/(*dim);
		for(k=0;k<(*dim);k++){
			if(k==0) menor=B[k][i];
			if(B[k][i]<menor) {
				menor=B[k][i];
				pos=k;
			}
		}
		C[i]=prom*(pow(menor,(i+pos)));
		printf("+%f+%d+%d+%d+",prom,menor,i,pos);
	}
}

void mostrar(float * C, int * dim){
	int i;
	printf("\nLos datos del arreglo resultante son:");
	for(i=0;i<(*dim);i++)
		printf("\nC[%d]= %f", i+1, C[i]);
}

void liberar(int**A, int**B, float*C, int * dim){
	free(C);
	int i;
	for(i=0;i<(*dim);i++){
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
	printf("\n\nMemoria liberada.\n\n");
}

