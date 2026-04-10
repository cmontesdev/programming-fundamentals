#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define tam 80

void leer(char *, char *, int *, int *);
void vocales(char *, char *, char *, char *, int *, int *);
void cambioVocales(char *, char *, char *, char *, int *);

void main(){
	int long1; 
	int long2;
	char clave1[2]={'N','\0'}, clave2[2]={'N','\0'};
	char cad[tam], cad2[tam];
	leer(cad, cad2 ,&long1, &long2);
	vocales(cad, cad2, clave1, clave2, &long1, &long2);
	if(clave1[0]!='N'&&clave2[0]!='N') cambioVocales(cad, cad2, clave1, clave2, &long2);
	else printf("\n\nAmbas cadenas deben tener una vocal que más se repite para cambir las vocales.\n\n");
}

void leer(char*c, char*c2, int*long1, int*long2){
	do{
		printf("\n\nIngrese una cadena de texto no más de 80 caracteres: \n");
		scanf("%[^\n]", c);
		getchar();
		*long1=strlen(c);
		if (*long1==0) printf("No se ingresó ninguna cadena, intente nuevamente. \n\n");
	}while(*long1==0);
	//no pude hacer el do-while también con la segunda entrada porque parece que el getchar le afecta también y conserva un caracter vacío, al menos esa fue mi conclusión después de varias pruebas
		printf("\nIngrese otra cadena de texto de no más de 80 caracteres: \n");
		scanf("%[^\n]", c2);
		getchar();
		*long2=strlen(c2);
}

void vocales(char * c1, char * c2, char * cv1, char * cv2, int*long1, int*long2){
	int voc[5]={0,0,0,0,0};
	int i;

	printf("\n... ... ... ...");
	for(i = 0; i < *long1; i++)
	{
		switch(c1[i]){
			case 'a': voc[0]++;
			break;
			case 'A': voc[0]++;
			break;
			case 'e': voc[1]++;
			break;
			case 'E': voc[1]++;
			break;
			case 'i': voc[2]++;
			break;
			case 'I': voc[2]++;
			break;
			case 'o': voc[3]++;
			break;
			case 'O': voc[3]++;
			break;
			case 'u': voc[4]++;
			break;
			case 'U': voc[4]++;
			break;
			default: break;
		}
	}
	printf("\nCadena 1: %s\n", c1);
	if(voc[0]>voc[1]&&voc[0]>voc[2]&&voc[0]>voc[3]&&voc[0]>voc[4]) {printf("La vocal más repetida es la 'a'."); cv1[0]='A';}
	else if(voc[1]>voc[0]&&voc[1]>voc[2]&&voc[1]>voc[3]&&voc[1]>voc[4]) {printf("La vocal más repetida es la 'e'."); cv1[0]='E';}
	else if(voc[2]>voc[0]&&voc[2]>voc[1]&&voc[2]>voc[3]&&voc[2]>voc[4]) {printf("La vocal más repetida es la 'i'."); cv1[0]='I';}
	else if(voc[3]>voc[0]&&voc[3]>voc[1]&&voc[3]>voc[2]&&voc[3]>voc[4]) {printf("La vocal más repetida es la 'o'."); cv1[0]='O';}
	else if(voc[4]>voc[1]&&voc[4]>voc[2]&&voc[4]>voc[3]&&voc[4]>voc[0]) {printf("La vocal más repetida es la 'u'."); cv1[0]='U';}
	else if(voc[0]==0&&voc[1]==0&&voc[2]==0&&voc[3]==0&&voc[4]==0) printf("No hay vocales.\n\n"); 
	else printf("No hay un una vocal más repetida.\n");

	for(i=0;i<5;i++)
		voc[i]=0;
	
	for(i = 0; i < *long2; i++)
	{
		switch(c2[i]){
			case 'a': voc[0]++;
			break;
			case 'A': voc[0]++;
			break;
			case 'e': voc[1]++;
			break;
			case 'E': voc[1]++;
			break;
			case 'i': voc[2]++;
			break;
			case 'I': voc[2]++;
			break;
			case 'o': voc[3]++;
			break;
			case 'O': voc[3]++;
			break;
			case 'u': voc[4]++;
			break;
			case 'U': voc[4]++;
			break;
			default: break;
		}
	}

	printf("\n\nCadena 2: %s\n", c2);
	if(voc[0]>voc[1]&&voc[0]>voc[2]&&voc[0]>voc[3]&&voc[0]>voc[4]) {printf("La vocal más repetida es la 'a'."); cv2[0]='A';}
	else if(voc[1]>voc[0]&&voc[1]>voc[2]&&voc[1]>voc[3]&&voc[1]>voc[4]) {printf("La vocal más repetida es la 'e'."); cv2[0]='E';}
	else if(voc[2]>voc[0]&&voc[2]>voc[1]&&voc[2]>voc[3]&&voc[2]>voc[4]) {printf("La vocal más repetida es la 'i'."); cv2[0]='I';}
	else if(voc[3]>voc[0]&&voc[3]>voc[1]&&voc[3]>voc[2]&&voc[3]>voc[4]) {printf("La vocal más repetida es la 'o'."); cv2[0]='O';}
	else if(voc[4]>voc[1]&&voc[4]>voc[2]&&voc[4]>voc[3]&&voc[4]>voc[0]) {printf("La vocal más repetida es la 'u'."); cv2[0]='U';}
	else if(voc[0]==0&&voc[1]==0&&voc[2]==0&&voc[3]==0&&voc[4]==0) printf("No hay vocales"); 
	else printf("No hay un una vocal más repetida.\n");
}

void cambioVocales(char * c1, char * c2, char * cv1, char * cv2, int * long2){
	printf("\n\nCadena resultante: \n");
		for(int i=0;i<(*long2); i++){
			if(cv2[0]==cv1[0]) {i=(*long2); printf("%s", c2);}
			else if(toupper(c2[i])==cv2[0]) c2[i]=cv1[0];
			printf("%c", tolower(c2[i])); 
		}//No pude conservar la frase con sus mayúsculas porque las funciones islower/isupper no daban valores asociados a mayusculas/minusculas
		printf("\n\n");
}