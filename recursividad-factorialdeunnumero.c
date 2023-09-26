#include <stdio.h>
/*
EJEMPLO ENCONTRAR EL FACTORIAL
 -Se deben multiplicar  los numeros anteriores entre si.-


EJEMPLO CON 4-

La funcion recursiva factorial resta sucesivamente 1 
para recorrer los valores anteriores del 4.la funcion se llama 
a si misma y se utiliza multiples veces hasta que llega al 
valor base (primer numero a multiplicar)

Despues de la primera llamada ,automaticamente se llama a si misma hasta que se
 cumpla una condicion que la detenga.

n * factorial(n - 1) 

4 * factorial(4 - 1)  -->(3)  					 PRIMER LLAMADO A LA FUNCION
-->	3 * factorial(3 - 1)  -->(2) 				 SUCESION AUTOMATICA
	-->	2 * factorial(2 - 1)  -->(1) 			 SUCESION AUTOMATICA
		--> 1 * factorial(1- 1) = factorial(0)   SUCESION AUTOMATICA


Cuando n==0,se consiguieron todos los num a multiplicar y se multiplican.
si n==0 En la funcion factorial(int n) entonces devuelve el valor 1.


		--> Entonces 1 * (factorial(0))= 1  Valor porel cual termina la sucesion
	--> Entonces 2 * (2 - 1) = 2
--> Entonces 3 * (3 - 1) = 6
 Entonces 6 * (  4  ) = 24



*/


int factorial(int n);/*devuelve solo el resultado final*/
void mostrarfactorial(int n); /*muestra por pantalla el procedimiento*/
void mostrarmultiplicacion(int n);

/*----------------------------------------------------------------------------*/
/*-------------------------------MAIN-----------------------------------------*/
int main() {
	int n ;  /* número para calcular el factorial*/
	int resultado;
	
	printf("ingrese numero para calcular su factorial:\n");
	scanf("%d",&n);
	
	resultado = factorial(n); /*llamada a funcion que da solo el resultado*/
	
	
	printf("Procedimiento detallado de la funcion factorial:\n\n");
	mostrarfactorial(n);      /*llamada a funcion que muestra el procedimiento*/
	mostrarmultiplicacion(n);
	printf("\nEl factorial de %d es %d ---> resultado final\n\n", n, resultado);
	
	return 0;
}
//*---------------------------------------------------------------------------*/
/*-----------------------FUNCIONES Y METODOS----------------------------------*/

int factorial(int n) {	
	if (n == 0) {  /* caso base*/
		
		return 1; /*La función devuelve 1 * (1), que es igual a 1.*/
		
	} else {
		
		return n * factorial(n - 1); /*llamada recursiva*/
		
	}
}


void mostrarfactorial(int n){
	int i;
	for(i=n;n>=1;i--){
		
		if(n==1){
			printf("	%d * factorial((%d) - 1) ----->  finaliza sucesion de la funcion\n\n",n,n);
		}else{
			printf("	%d * factorial((%d) - 1)\n",n,n);
		}
		n=n-1;	
	}	
}

void mostrarmultiplicacion(int n){
	int i,resultado;
	resultado=1;
	for(i=1;i<=n;i++){

		if(i==1){
			printf("\t %d x (%d) =",resultado,i);
			resultado=(resultado * i);
			printf(" %d   -----> Comienza a multiplicar desde el ultimo valor que dio la funcion\n",resultado);
		}else{
			printf("\t %d x (%d) =",resultado,i);
			resultado=(resultado * i);
			printf(" %d\n",resultado);
		}
	}
}
