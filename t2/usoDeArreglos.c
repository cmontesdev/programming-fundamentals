#include <stdio.h>

#define tam 50

void darNumElem(int *);
void insertarDatos(int *, int);
void pideNumBuscar();
void copiar(int *, int *, int);
void mostrar(int *, int);
void pedirElemento(int *);
void ordenaBurbuja(int *, int);
void busqueda(int *, int, int);
void busquedaBinaria(int *, int, int);

void main(){
	int n, elem;
	darNumElem(&n);
	int num1[tam], num2[tam]; 
	insertarDatos(num1, n);
	mostrar(num1, n);
	copiar(num1, num2, n);
	pedirElemento(&elem);
	busqueda(num1, n, elem);
	ordenaBurbuja(num1, n);
	busquedaBinaria(num1, n, elem);
}

void darNumElem(int * n){
	printf("\n\nFunción que pide al usuario el numero de elementos a ingresar..........\n");
	do{
		printf("Numero de elementos: ");
		scanf("%d", n);
		if(*n>tam) printf("¡Solo se admite un maximo de 50 elementos!\n");
		if(*n<1) printf("¡Se debe ingresar al menos 1 elemento!\n");
	}while(((*n)>tam)||((*n)<1));
}

void insertarDatos(int * num, int n){
	printf("\n\nFunción donde el usuario ingresa los elementos.........................\n");
	int i;
	for(i=0;i<n;i++){
		printf("Elemento [%d]: ",i+1);
		scanf("%d", &num[i]);
	}
}

void mostrar(int * num, int n){
	printf("\n\nSe ingresaron los siguientes elementos.................................\n");
	int i;
	printf("Los elementos son:\n");
	for(i=0; i<n; i++){
		printf("Dato[%d]=%d\n",i+1, num[i]);
	}
}

void copiar(int * num1, int * num2, int n){
	printf("\n\nCopiando los elementos a otro arreglo..................................\n");
	int i;
	for(i=0;i<n;i++){
		printf("\nDato[%d] = %d", i+1, num1[i]);
		num2[i]=num1[i];
		printf(", entonces copia[%d] = %d", i+1, num2[i]);
	} 
}

void pedirElemento(int * elem){
	printf("\n\n\nBuscar al elemento entre los ingresados previamente....................\n");
	printf("Ingrese el elemento que quiere encontrar: ");
	scanf("%d", elem);
}

void busqueda(int * num, int n, int elem){
	printf("\n\nBúsqueda secuencial del elemento (elementos con el orden original).....\n");
	int i;
	for(i=0;i<n;i++){
		if(elem==num[i]){
			printf("La posición del elemento es %d", i+1);
			break;
		}	
	}
	if(i==n) printf("El elemento no se encuentra en el arreglo");
}

void busquedaBinaria(int * num, int n, int elem){
	printf("\n\nHaciendo búsqueda binaria del elemento.................................\n");
	int izq=0, der=n-1, medio=((izq+der)/2);
	while(izq<=der){
		if(num[medio]<elem) izq=medio+1;
		else if(num[medio]==elem){
			printf("Se encontro la posicion %d", medio+1); //aunque originalmente no tenía "+1", sería confuso para el usuario dejarlo así
			printf("\n\n\n");
			break;
		}
		else der=medio-1;
		medio=(izq+der)/2;
		
	}
	if(izq>der) printf("El numero %d no se encontro\n\n\n", elem);
}

void ordenaBurbuja(int * num, int n){
	printf("\n\nOrdenando los elementos ingresados.....................................\n");
	int i, j, temp;
	for(j=0;j<n;j++){
		for(i=0;i<n-1;i++){
			if(num[i]>num[i+1]){
				temp=num[i];
				num[i]=num[i+1];
				num[i+1]=temp;
			}
		}
	}
	printf("Los elementos quedaron ordenados de la siguiente manera:\n");
	for(i=0;i<n;i++) printf("%d ", num[i]);
}