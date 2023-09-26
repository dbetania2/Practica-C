#include <stdio.h>
#include <math.h>

/*
Triángulo de Pascal.

*/

int factorial(int n);
int combinacion(int n,int k);

int main(int argc, char *argv[]) {
	int n,i,j,resultadocombinacion;
	
	printf("Ingrese num: ");
	scanf("%d",&n);
	int numGuiones = n;
	
	for(i=0;i<=n;i++){
		
		if(i<n){
			
			for (j = 0; j < numGuiones; j++) {
				printf("  ");
			}
			
			numGuiones--;
			
		}
		
		for(j=0;j<=i;j++){ 
			
			resultadocombinacion=combinacion(i,j);
			
			//condiciones PARA la simetria del triangulo
			if(resultadocombinacion>=100){
				
				if(resultadocombinacion>=10){
					
					printf("%d ",resultadocombinacion); //1 espacio
					
				}else{
					
					printf("%d ",resultadocombinacion); //1 espacio
				}
				
			}else{
				
				if(i>=15){
					
					if(resultadocombinacion<0){
						printf("%d  ",resultadocombinacion); //2 espacios
					}else {
						printf("%d   ",resultadocombinacion); //3 espacios
					}
					
				}else{
					
					if(resultadocombinacion>=10){
						
						printf("%d  ",resultadocombinacion); //2 espacios
						
					}else{
						
						printf("%d   ",resultadocombinacion); //3 espacios
					}
				}
			}
		}
		printf("\n"); // Agregamos un salto de línea después de cada fila.
		
	}
	return 0;
}

int factorial(int n) {	
	if (n == 0) {  // caso base
		
		return 1; //La función devuelve 1 * (1), que es igual a 1.
		
	} else {
		
		return n * factorial(n - 1); // llamada recursiva
		
	}
}

int combinacion(int n,int k){
	int resultado;
	resultado=(factorial(n))/(factorial(k)*factorial(n-k));
	return resultado;
}







