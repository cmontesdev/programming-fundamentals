#include <stdio.h>
#include <stdlib.h>

void darDim(int *);
int * crearAU(int);
void darDatos(int*, int);
void mostrar(int*, int);
void liberar(int*);

void main(){
	int * A, elem;
	darDim(&elem);
	A=crearAU(elem);
	darDatos(A, elem);
	mostrar(A, elem);
	liberar(A);
}

void darDim(int * elem){
	printf("\nIndique la dimension del arreglo: ");
	scanf("%d", elem);
}

int * crearAU(int elem){
	int * A;
	A=(int*) malloc(elem*sizeof(int));
	if(A==NULL){
		printf("\nNo hay memoria disponible.\n");
		exit(0);
	}	
	return A;
}

void darDatos(int * A, int elem){
	int i;
	printf("\nIngrese los datos del arreglo\n");
	for(i=0;i<elem;i++){
		printf("A[%d]=", i+1);
		scanf("%d", &A[i]);
	}
}

void mostrar(int * A, int elem){
	int i;
	printf("Los datos del arreglos son:");
	for(i=0;i<elem;i++)
		printf("\nA[%d]= %d", i+1, A[i]);
}

void liberar(int *A){
	free(A);
	printf("\n\nMemoria liberada.\n\n");
}