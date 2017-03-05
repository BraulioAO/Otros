#include <stdio.h>
#include <windows.h>
#include <time.h>

main(){
	int n;
	double sum = 0;
	
	printf("Introduce el tamaño de la matriz: ");
	scanf("%d",&n);
	
	double A[n][n]; //Matriz de coeficientes del sistema
	double L[n][n]; //Matriz L
	double U[n][n]; //Matriz U
	double B[n]; //Vector de terminos independientes
	double b[n]; //Vector auxiliar
	double x[n]; //Vector de soluciones
	double c[n]; //Vector de las comprobaciones
	int i,j,k;
	
	//Inicialización de las matrices y vectores
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			A[i][j] = L[i][j] = 0;
			B[i] = b[i] = 0;
			if(i==j)
				U[i][j] = 1; //Diagonal de U
			else
				U[i][j] = 0;
		}
	

	//***********************************************************************************
	printf("\nIntroduce la matriz de coeficientes del sistema\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			printf("A[%d][%d] = ",i,j);
			scanf("%lf",&A[i][j]);
		}

	printf("\nIntroduce el vector de terminos independientes\n");
	for(i=0;i<n;i++){
		printf("B[%d] = ",i);
		scanf("%lf",&B[i]);
	}
/*
	//Generador de sistemas aleatorios
	srand(time(NULL));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			A[i][j] = rand()%100-50;
		}
	for(i=0;i<n;i++)
		B[i] = rand()%200-100;
*/
	//***********************************************************************************	
	//printf("\n");
	//system("pause");
	system("cls");
	
	//Determinación de los valores de la matriz L y U
	for(j=0;j<n;j++){//j=0
		
		for(i=j;i<n;i++){//i=0
		
			for(k=0;k<=j-1;k++)//k=...
				sum=L[i][k]*U[k][j]+sum;
			
			L[i][j] = A[i][j] - sum;
			sum=0;	
		}
		
		for(i=j+1;i<n;i++){//i=1
		
			for(k=0;k<=j-1;k++)//k=...
				sum=L[j][k]*U[k][i]+sum;
			
			U[j][i] = (A[j][i] - sum)/L[j][j];
			sum=0;
		}	
	}
	
	//Determinación del vector auxiliar b
	for(i=0;i<n;i++){
		for(k=0;k<i;k++)
				sum=L[i][k]*b[k]+sum;
		
		b[i]=(B[i] - sum)/L[i][i];
		sum=0;
	}	
	
	//***********************************************************************************	
	//Determinación de las soluciones
	for(i=0;i<n;i++){
		
		for(k=n-i;k<n;k++)
			sum=U[n-1-i][k]*x[k]+sum;
		
		
		x[n-1-i]=b[n-1-i] - sum;
		sum=0;
		
	}
	//Comprobación de las soluciones
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			c[i] = A[i][j]*x[j] + c[i];
	//***********************************************************************************			
	
	//Impresión de todas las matrices y vectores 

	printf("Matriz A\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nValores Independientes B\n");
	for(i=0;i<n;i++){
		printf("%lf\n",B[i]);
	}
/*	
	printf("\nMatriz L\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ",L[i][j]);
		}
		printf("\n");
	}
	  
	printf("\nMatriz U\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ",U[i][j]);
		}
		printf("\n");
	}

	printf("\nValores auxiliares b[]\n");
	for(i=0;i<n;i++){
		printf("%f\n",b[i]);
	}
*/	
	printf("\n\n******************************");
	printf("\nLA SOLUCION DEL SISTEMA ES: \n");
	for(i=0;i<n;i++){
		printf("X[%d] = %lf\n",i,x[i]);
	}
	printf("******************************");
	
	printf("\n\nComprobacion\n");
	for(i=0;i<n;i++){
		printf("c[%d] = %lf\n",i,c[i]);
	}
	
	printf("\n\n");
	system("pause");
}
