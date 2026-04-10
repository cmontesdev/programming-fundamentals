#include <stdio.h>

#define N 10
#define M 10

void inicio(int [N][M], int *, int *, int *);
void menu(int *);
void dim(int *, int *, int *, int[N][M]);
void datos(int [N][M], int *, int *);
void sumaD(int [N][M], int *, int *);
void sumaDS(int [N][M], int *, int *);
void restar(int [N][M], int *, int *);
void mostrar(int [N][M], int *, int *);

void main(){
	int opcion=0, fil, col, mtz[N][M];
	do{
		if(opcion==0){
			inicio(mtz, &fil, &col, &opcion);
			opcion=8;
		}
		if(opcion==8){
			menu(&opcion);
			if(opcion==1) dim(&fil, &col, &opcion, mtz);
			if(opcion==2) datos(mtz, &fil, &col);
			if(opcion==3) sumaD(mtz, &fil, &col);
			if(opcion==4) sumaDS(mtz, &fil, &col);
			if(opcion==5) restar(mtz, &fil, &col);
			if(opcion==6) mostrar(mtz, &fil, &col);
		}
		if((opcion!=7)||(opcion==0)) opcion=8;
	} while(opcion!=7);
}

void inicio(int mtz[N][M], int * fil, int * col, int * opcion){
	printf("\nBienvenido, para continuar, se le solicita que: \n");
	dim(fil, col, opcion, mtz);
	datos(mtz, fil, col);
	printf("\nListo, ahora puede acceder al menú completo.\n");
}

void menu(int * opcion){
	printf("\n\nIngrese el número asociado a la opción que desea ejecutar: ");
	printf("\n1) Ingresar las dimensiones de la matriz");
	printf("\n2) Ingresar los datos de la matriz");
	printf("\n3) Sumar la diagonal principal de la matriz");
	printf("\n4) Sumar la matriz diagonal superior");
	printf("\n5) Restar la matriz diagonal inferior");
	printf("\n6) Mostrar la matriz");
	printf("\n7) Salir\n");
	scanf("%d", opcion);
}

void dim(int * fil, int * col, int * opcion, int mtz[N][M]){
	int f, c;
	if(*opcion!=0){
		f=(*fil); 
		c=(*col);
	}
	printf("\nIngrese el tamaño de la matriz: ");
	do{
		printf("\n¿Cuántas filas? (ingrese un entero positivo menor o igual que 10): ");
		scanf("%d", fil);
	} while((*fil>10)||(*fil<1));
	do{
		printf("¿Cuántas columnas? (ingrese un entero positivo menor o igual que 10): ");
		scanf("%d", col);
	} while((*col>10)||(*col<1));

	if(*opcion!=0){
		//esto lo hago para evitar que se intente trabajar con casillas vacías, por ejemplo: aumentar la dimensión de la matriz y después hacer una suma (se contemplarían casillas vacías y devolvería valores raros) 
		if((f<(*fil))||(c<(*col))){ 
			printf("\n+++ ¡La nueva matriz tiene casillas vacias! Actualice los datos. +++");
			datos(mtz, fil, col);
		}
	}
}

void datos(int mtz[N][M], int * fil, int * col){
	printf("\n_________________________________________________________________");
	printf("\nIngrese los datos de la matriz (números enteros): \n");
	for(int i=0;i<*fil;i++){
		for(int j=0; j<*col; j++){
			printf("Dato[%d][%d]:", i+1, j+1);
			scanf("%d", &mtz[i][j]);
		}
	}
	printf("\nDatos guardados.");
	printf("\n_________________________________________________________________");
}

void sumaD(int mtz[N][M], int * fil, int * col){
	int suma=0, i, j;
	for(i=0;i<(*fil);i++){
		for(j=0;j<(*col);j++){
			if(i==j) suma=suma+mtz[i][j];
		}
	}
	printf("\n_________________________________________________________________");
	printf("\nLa suma de los valores de la diagonal principal de la matriz es: %d", suma);
	printf("\n_________________________________________________________________");
}

void sumaDS(int mtz[N][M], int * fil, int * col){
	int suma=0;
	for(int i=0;i<*fil;i++){
		for(int j=0;j<*col;j++){
			if(i<j) suma=suma+mtz[i][j];
		}
	}
	printf("\n_________________________________________________________________");
	printf("\nLa suma de los valores de la diagonal superior de la matriz es: %d", suma);
	printf("\n_________________________________________________________________");
}

void restar(int mtz[N][M], int * fil, int * col){
	int resta=0;
	for(int i=0;i<*fil;i++){
		for(int j=0;j<*col;j++){
			if(i>j) resta=resta-mtz[i][j];
		}
	}
	printf("\n_________________________________________________________________");
	printf("\nLa resta de la diagonal inferior de la matriz es: %d", resta);
	printf("\n_________________________________________________________________");
}

void mostrar(int mtz[N][M], int * fil, int * col){
	printf("\n_________________________________________________________________");
	printf("\nLos datos de la matriz son: ");
	for(int i=0;i<*fil;i++){
		for(int j=0;j<*col;j++){
			printf("\nDato[%d][%d]: %d", i+1, j+1, mtz[i][j]);
		}
	}
	printf("\n_________________________________________________________________");
}
