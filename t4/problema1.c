#include <stdio.h>

#define n 15

void inicio();
void entrada(int *);
void proceso(int *, int *);
void salida(int *);

void main(){
	inicio();
	int A[n], suma[8];
	entrada(A);
	proceso(A, suma);
	salida(suma);
}

void inicio(){
	printf("\n\nDada una serie de 15 elementos (cifras enteras) ingresados por el usuario, \neste programa suma los extremos de dicha serie hasta llegar al elemento  del \nmedio, y almacena los resultados en una matriz...\n\n");}

void entrada(int * A){
	int i;
	for(i=0;i<n;i++){
		printf("Elemento %d: ", i+1);
		scanf("%d", &A[i]);
	}
}

void proceso(int * A, int * suma){ 
	int i;
	for(i=0;i<7;i++){
		suma[i]=A[i]+A[n-(i+1)];
	}
	suma[i]=A[i];
}

void salida(int * suma){
	int i;
	printf("\n\nResultados:");
	for(i=0;i<8;i++){
		printf("\n");
		printf("Suma[%d] = %d", i+1, suma[i]);
	}
	printf("\n\n");
}
