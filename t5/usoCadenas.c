#include<stdio.h>
#include<ctype.h>
#include<string.h>

void leerCadena(char *);
void intercambia(char *);
void vocales(char *);
void mayusculas(char *);
void longitud(char *);
void palindromo(char *);
//void salir(char *);

void main(){
	char sal[2]={'n', '\0'};
	char cad[50];
	//do{
		//getchar();
		leerCadena(cad);
		intercambia(cad);
		vocales(cad);
		mayusculas(cad);
		longitud(cad);
		palindromo(cad);
		//salir(sal);
	//}while((sal[0]!='s')||(sal[0]!='S'));
}

void leerCadena(char * cad){
	printf("Indroduzca una cadena de 50 caracteres o menos: \n");
	scanf("%[^\n]", cad);
}

void intercambia(char * cad){
	int tam=strlen(cad);
	char cadcopia[tam];
	int i;
	printf("\nLa cadena al revés es: \n");
	for(i=0;i<=tam;i++){
		cadcopia[i]=cad[tam-i];
		printf("%c", cadcopia[i]);
	}
}

void vocales(char * cad){
	int i, n=0, tam=strlen(cad);
	for(i=0;i<tam;i++){
		switch(cad[i]){
			case 'a':
				n++;
				break;
			case 'A':
				n++;
				break;
			case 'e':
				n++;
				break;
			case 'E':
				n++;
				break;
			case 'i':
				n++;
				break;
			case 'I':
				n++;
				break;
			case 'o':
				n++;
				break;
			case 'O':
				n++;
				break;
			case 'u':
				n++;
				break;
			case 'U':
				n++;
				break;
			default:
				break;
		}
	}
	printf("\n\nLa cadena tiene %d vocales.\n", n);
}

void mayusculas(char * cad){
	int i, n=0, tam=strlen(cad);

	for(i=0;i<=tam;i++){
		if(isupper(cad[i])==256) n++;
	}
	printf("\nLa cadena tiene %d mayúsculas\n", n);
}

void palindromo(char * cad){
	int i, n=0, tam=strlen(cad);
	char copia[tam], junto2[tam], junto[tam];
	for(i=0;i<=tam;i++){
		copia[i]=cad[i];
	}
	printf("\n");
	for(i=0;i<=tam;i++){
		copia[i]=tolower(copia[i]);
	}
	for(i=0;i<=tam;i++){
		if(copia[i]!=' ') {junto[n]=copia[i]; n++;}
	}
	for(i=0;i<=n;i++){
		junto2[i]=junto[n-i];
	}
	n=strlen(junto2);
	for(i=0;i<n;i++){
		printf("%ld", strlen(junto));
		printf("%ld", strlen(junto));
		if(junto[i]!=junto2[i]) i=n;
		if(i==(n-1)) printf("\n\nLa cadena es un palindromo\n\n");
	}
}

void longitud(char * cad){
	int tam=strlen(cad);
	printf("\nLa longitud de la cadena es de %d caracteres\n", tam);
}
/*
void salir(char * sal){
	getchar();
	printf("¿Desea salir? (s/n): ");
	scanf("%[^\n]", sal);
}*/