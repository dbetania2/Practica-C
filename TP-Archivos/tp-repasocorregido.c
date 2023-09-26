#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define max 3
/*
1-Estructura Datos del artista: DNI- Nombre del artista- Apellido del Artista
2-Estructura Éxito: DNI-Título- Género Musical (1= folklore, 2: rock, 3: popular), Cant-Vendida.
3-Estructura Final: DNI- Nombre del artista- Apellido del Artista Título- Género Musical (1= folklore, 2: rock, 3: popular), Cant-Vendida.
*/

struct datos_artista{
	int DNI;
	char nombre[20];
	char apellido[20];
};

struct Exito{
	int DNI;
	char titulo[10];
	int genero;
	int CantVendida;
	
};

struct Final{
	
	int DNI;
	char nombre[20];
	char apellido[20];
	char titulo[10];
	int genero;
	int CantVendida;
	
};
/*-----------------------------PROCEDIMIENTOS---------------------------------*/

void unirestructuras(struct datos_artista artista[],struct Exito exito[],struct Final exfinal[],int *longitud);

int cantidadvendidaporGenero(struct Final exfinal[],int longitud,int num);

int buscardni(struct Final exfinal[],int longitud,int numdni);

void copiatitulos(struct Final exfinal[],int longitud,char ctitulos[30]);

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


int main(int argc, char *argv[]) {
	
	/*----------------------------*/
	/*ESTRUCTURAS-----------------*/
	struct datos_artista artista[max];
	struct Exito exito[max];
	struct Final exfinal[max];
	/*----------------------------*/
	
	
	/*----------------------------*/
	/*AUXILAIRES PARA ORDENAMIENTO*/
	struct datos_artista temp;
	struct Exito tempe;
	int i,j;
	int longi=0;
	/*----------------------------*/
	int TOTALvendido=0;
	int contmasvendido;
	char vargenero[10];
	int numgenero;
	int idmasvendido;
	
	int generoa,generob,generoc;
	/*----------------------------*/
	int busquedadni,busquedadniM;
	int contIngresodedatos=0;
	/*----------------------------*/
	char ct[30];
	
	while(contIngresodedatos<max){
		
		printf( "Escribe el nombre del Artista %d ",contIngresodedatos );
		scanf( "%s", &artista[contIngresodedatos].nombre );
		
		printf( "Escribe el apellido del Artista %d ",contIngresodedatos );
		scanf( "%s", &artista[contIngresodedatos].apellido );
		
		printf( "Escribe el DNI del Artista %d ",contIngresodedatos );
		scanf( "%d", &artista[contIngresodedatos].DNI );
		
		
		
		contIngresodedatos++;
		
	}
	
	contIngresodedatos=0;
	
	while(contIngresodedatos<max){
		
		printf( "Escribe el titulo del exito %d ",contIngresodedatos );
		scanf( "%s", &exito[contIngresodedatos].titulo );
		
		printf( "Escribe el genero del exito %d ",contIngresodedatos );
		scanf( "%d", &exito[contIngresodedatos].genero );
		
		printf( "Escribe el DNI del Artista %d ",contIngresodedatos );
		scanf( "%d", &exito[contIngresodedatos].DNI );
		
		printf( "Escribe cantidad vendida del Artista %d ",contIngresodedatos );
		scanf( "%d", &exito[contIngresodedatos].CantVendida);
		
		contIngresodedatos++;
		
	}
	
	/*Ordenar por dni esctructura datos_artista*/
	for (i = 0; i < max -1 ; i++) {
		for (j = 0; j < max -1 ; j++) {
			if (artista[j].DNI > artista[j + 1].DNI) {
				temp = artista[j];
				artista[j] = artista[j + 1];
				artista[j + 1] = temp;
			}
		}
	}
	
	/*Ordenar por dni esctructura Exito*/
	for (i = 0; i < max - 1 ; i++) {
		for (j = 0; j < max -1 ; j++) {
			if (exito[j].DNI > exito[j + 1].DNI) {
				tempe = exito[j];
				exito[j] = exito[j + 1];
				exito[j + 1] = tempe;
			}
		}
	}
	
	
	unirestructuras(artista,exito,exfinal,&longi);
	printf("\n%d\n",longi);
	
	for (i = 0; i < longi; i++) {
		printf("\nDatos del Artista %d:\n", i + 1);
		printf("Nombre: %s\n", exfinal[i].nombre);
		printf("Apellido: %s\n", exfinal[i].apellido);
		printf("DNI: %d\n", exfinal[i].DNI);
		printf("Título del Éxito: %s\n", exfinal[i].titulo);
		printf("Género: %d\n", exfinal[i].genero);
		printf("Cantidad Vendida: %d\n", exfinal[i].CantVendida);
	}
	
	/*
	variable = contmasvendido 
	variable para genero(cadena) = CHAR vargenero[10] 
	variable para genero (numero entero 1,2,3) = numgenero 
	
	*/
	
	contmasvendido = exfinal[0].CantVendida;
	
	for(i=0;i<longi;i++){
		
		if(exfinal[i].CantVendida>contmasvendido){
			contmasvendido = exfinal[i].CantVendida;
			idmasvendido=i;
			numgenero=exfinal[i].genero;
			
		}
		
	}
	
	/*Asigna cadena de caracteres segun el genero 1,2, o 3*/
	
	switch (numgenero) {
	case 1:
		strcpy(vargenero, "folklore");
		break;
	case 2:
		strcpy(vargenero, "rock");
		break;
	default:
		strcpy(vargenero, "popular");
		break;
	}
	
	printf("\nArtista que mas cantidades vendió:\n");
	printf("\n%s ,%s\n",exfinal[idmasvendido].nombre ,exfinal[idmasvendido].apellido);
	printf("\n%s ,%s\n",exfinal[idmasvendido].titulo,vargenero);
	printf("\nCantidad vendida :%d\n",contmasvendido);
	
	/*-----------------------CANTIDAD VENDIDA POR GENERO------------------------
	
	variables =	generoa,	generob	,	generoc			
	funcion= cantidadvendidaporGenero									
	*/
	
	generoa=  cantidadvendidaporGenero(exfinal,longi,1);
	printf("\nCantidad vendida Genero floklore :%d",generoa);
	generob=  cantidadvendidaporGenero(exfinal,longi,2);
	printf("\nCantidad vendida Genero rock :%d",generob);
	generoc=  cantidadvendidaporGenero(exfinal,longi,3);
	printf("\nCantidad vendida Genero popular :%d",generoc);
	
	
	
	printf("\nGenero mas vendido: %s %d ventas\n",vargenero,contmasvendido);
	
	
	/*---------------------------BUSQUEDA POR DNI----------------------------*/
	
	printf("Ingrese numero de DNI para busqueda:");
	scanf("%d",&busquedadni);
	busquedadniM=buscardni(exfinal,longi,busquedadni);
	if(busquedadniM==0){
		
		printf("DNI no encontrado");
		
	}else{
		for (i = 0; i < longi; i++) {
			if (exfinal[i].DNI == busquedadni) {
				printf("%d | %s | %s | %s | %d | %d\n",
					   exfinal[i].DNI, exfinal[i].nombre, exfinal[i].apellido,
					   exfinal[i].titulo, exfinal[i].genero, exfinal[i].CantVendida);
				break;
			}
		}
	}
	
	copiatitulos(exfinal,longi,ct);
	   
	   
	   i = 0;
	while (ct[i] != '\0') {
		if (ct[i] == '*') {
			printf("\n"); 
		} else {
			printf("%c", ct[i]); 
		}
		i++;
	}
	/*
	char* token = strtok(ctitulos, "*");
	while (token != NULL) {
	printf("%s\n", token);
	token = strtok(NULL, "*");
	}
	*/
	return 0;
}






/*----------------------------------Procedimeintos----------------------------*/


void unirestructuras(struct datos_artista artista[],struct Exito exito[],struct Final exfinal[],int *longitud){
	int i,j;
	int cont3=0;
	
	for(i=0;i<max - 1;i++){
		for(j=0;j<max -1 ;j++){
			
			if(artista[i].DNI==exito[j].DNI){
				
				exfinal[cont3].genero = exito[j].genero ;
				exfinal[cont3].CantVendida = exito[j].CantVendida;
				strcpy(exfinal[cont3].titulo, exito[j].titulo);
				
				exfinal[cont3].DNI=artista[i].DNI;
				strcpy(exfinal[cont3].nombre , artista[i].nombre);
				strcpy(exfinal[cont3].apellido, artista[i].apellido);
				
				cont3++;
				
			}			
		}
		*longitud=cont3;
	}
}
	
	
	int cantidadvendidaporGenero(struct Final exfinal[],int longitud,int num){
		
		int cantidad=0;
		int i;
		int numd=num;
		
		switch (numd) {
		case 1:
			for(i=0;i<longitud;i++){
				
				if(exfinal[i].genero==1){
					cantidad++;
				}
			}
			break;
			
		case 2:
			for(i=0;i<longitud;i++){
				
				if(exfinal[i].genero==2){
					cantidad++;
					
				}
			}
			break;
			
		default:
			for(i=0;i<longitud;i++){
				
				if(exfinal[i].genero==3){
					cantidad++;
					
				}
			}
			break;
		}
		
		
		return cantidad;
		
	}
		
		
		int buscardni(struct Final exfinal[], int longitud, int numdni) {
			int izquierda = 0;
			int derecha = longitud - 1;
			
			while (izquierda <= derecha) {
				int medio = izquierda + (derecha - izquierda) / 2;
				
				if (exfinal[medio].DNI == numdni) {
					return numdni;  
				} else if (exfinal[medio].DNI < numdni) {
					izquierda = medio + 1;
				} else {
					derecha = medio - 1;
				}
			}
			
			return 0;  
		}
		
		
		void copiatitulos(struct Final exfinal[],int longitud,char ctitulos[30]){
			int i;
			char ast[]="*";
			
			for(i=0;i<longitud;i++){
				strcat(ctitulos,exfinal[i].titulo);
				strcat(ctitulos,ast);
				
			}
		}
			
