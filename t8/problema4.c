#include <stdio.h>

#define FIL 10
#define COL 10

void pedirDim(int *, int *, int [FIL][COL]);
void leeMatriz(int *, int *, int [FIL][COL]);
void analizarFoto(int *, int *, int [FIL][COL], int [FIL][COL]);
void mostrarMatriz(int *, int *, int [FIL][COL], int [FIL][COL]);

void main(){
	int M, N, mtz[FIL][COL];
	int tabla[FIL][COL];
	pedirDim(&M, &N, mtz);
	leeMatriz(&M, &N, mtz);
	analizarFoto(&M, &N, mtz, tabla);
	mostrarMatriz(&M, &N, mtz, tabla);
}

void pedirDim(int * M, int * N, int mtz[FIL][COL]){
	printf("\nBienvenido, ingrese las dimensiones de la fotografía: ");
	do{
		printf("\n¿Cuántas filas de información tiene la fotografía? \n(Valor mínimo: 3, valor máximo: 10) ");
		scanf("%d", M);
		if((*M<3)||(*M>10)) printf("\nFotografía no soportada, intente con otra de alto (entero) N | 2<N<11");
	} while((*M<3)||(*M>10));
	do{
		printf("\n¿Cuántas columnas de información tiene la fotografía? \n(Valor mínimo: 3, valor máximo: 10) ");
		scanf("%d", N);
		if((*N>10)||(*N<3)) printf("\nValor inválido, Se requiere que el valor sea entero N | 2<N<11");
	} while((*N>10)||(*N<3));
}

void leeMatriz(int * M, int * N, int mtz[FIL][COL]){
	printf("\nIngrese la información de la fotografía. \nConsidere que los valores permitidos van de 0 a 20.\n");
	int i, j;
	for(i=0;i<*M;i++){
		for(j=0;j<*N;j++){
			do{
				printf("Casilla[%d][%d]: ", i+1, j+1);
				scanf("%d", &mtz[i][j]);
				if(mtz[i][j]>20||mtz[i][j]<0) printf("\nLos valores aceptados van de 0 a 20. Intente de nuevo:\n");
			} while(mtz[i][j]>20||mtz[i][j]<0);			
		}
	}
}

void analizarFoto(int * M, int * N, int mtz[FIL][COL], int tabla[FIL][COL]){
	int i, j;
	
	for(i=1;(i+1)<*M;i++){
		for(j=1;(j+1)<*N;j++){
			if((mtz[i][j]+mtz[i-1][j]+mtz[i+1][j]+mtz[i][j-1]+mtz[i][j+1])>30) tabla[i][j]=1;
			else tabla[i][j]=0;
		}
	}
	printf("\n\n");
}

void mostrarMatriz(int * M, int * N, int mtz[FIL][COL], int tabla[FIL][COL]){
	int i, j;
	printf("\nInformación de la fotografía:\n");
	for(i=0;i<*M;i++){
		printf("\n");
		for(j=0;j<*N;j++){
			if(mtz[i][j]>9)printf("  %d  ", mtz[i][j]);
			else if(mtz[i][j]<10) printf("   %d  ", mtz[i][j]);
		}
	}
	printf("\n\nResultado del análisis:\n");
	for(i=0;i<*M;i++){
		printf("\n");
		for(j=0;j<*N;j++){
			if(tabla[i][j]==1) printf("   @  ");
			else printf("      ");
		}
	}
	printf("\nFin del programa.\n\n");
}
