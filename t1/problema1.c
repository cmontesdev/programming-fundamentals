/*Profesora, para mostrar todos los resultados hasta el final sin arreglos solo hay dos casos:
- Caso a: que se haya especificado el número de grupos, alumnos y materias.
- Caso b: que se haya especificado el máximo número de grupos, alumnos y materias,
          pero en este caso, de ingresar cantidades menores, quedarían variables sin utilizar --> desperdicio de memoria.
 Por eso, es más óptimo mostrar los resultados conforme terminan los ciclos, que no mostrarlos al final. */

#include <stdio.h>

void titulo();
void promedios(int *, int *, int *);

void main(){
	int g, n, m;
	titulo();
	promedios(&g, &n, &m);
}

void titulo(){
	printf("\n_____________________________________________________________");
	printf("\nPromedios académicos.");
	printf("\n_____________________________________________________________");
}

void promedios(int * g, int * n, int * m){
	printf("\n\nIngresa el número de grupos de los que se obtendrá el promedio: ");
	scanf("%d", g);
	int cont1, cont2, cont3, cont4;
	float prom_tot=0;
	for(cont1=1; cont1<=(*g); cont1++){
		printf("Ingresa la cantidad de alumnos que pertenecen al grupo %d: ", cont1);
		scanf("%d", n);
		float prom_grupal=0;
		for(cont2=1; cont2<=(*n); cont2++){
			if(cont2==1) printf("\n_ _ _ _ _ _ _ _ _ _ _ _ Grupo %d _ _ _ _ _ _ _ _ _ _ _ _", cont1);
			printf("\n\n    Ingresa la cantidad de materias del alumno %d: ", cont2);
			scanf("%d", m);
			float prom_ind=0;
			for(cont3=1; cont3<=(*m); cont3++){
				if (cont3==1) printf("    . . . . . . . . . . Alumno %d . . . . . . . . . .\n", cont2);
				printf("\n    Con respecto a las calificaciones de la materia %d", cont3);
				printf("\n");
				float prom_materia=0;
				for(cont4=1; cont4<=3; cont4++){
					float cal=0;
					printf("    Ingresa la calificación %d (de 3):", cont4);
					scanf("%f", &cal);
					prom_materia+=cal;
				}
				prom_materia/=3;
				prom_ind+=prom_materia;
			}
			prom_ind/=(*m);
			prom_grupal+=prom_ind;
			printf("\n    El promedio del alumno %d es: %f", cont2, prom_ind);
			printf("\n    . . . . . . . . . . . . . . . . . . . . . . . . .\n");
		}
		prom_grupal/=(*n);
		prom_tot+=prom_grupal;
		printf("\n    El promedio del grupo %d es: %f", cont1, prom_grupal);
		printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
		if (cont1!=(*g)) printf("\n\n\n\n");
	}
	prom_tot/=(*g);
	if((*g>=2)) printf("\nEl promedio general (de los %d grupos) es: %f", *g, prom_tot); //solamente tiene sentido si son 2 grupos o más
	printf("\n\n\n");
}