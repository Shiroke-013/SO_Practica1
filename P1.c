#include <stdlib.h>
#include <stdio.h>

int r,c;
int matrixA, matrixB;

int main(void){
  
  char matrixs[] = "AB";
  for (int m = 0; m < 2; m++){
    
    printf("Please enter Matrix %c dimensions \n", matrixs[m]);
    printf("Matrix %c rows \n", matrixs[m]);
    scanf("%d", &r);
    printf("Matrix %c columns \n", matrixs[m]);
    scanf("%d", &c);

    if(m == 0){
      **matrixA = malloc(r * sizeof(int *));
      for(int i = 0; i < r; i++){
	matrixA[i] = malloc(c * sizeof(int));
      }
      printf("Enter the matrix A elements going by rows: ");
      for(int i = 0; i<r; i++){
	for(int j = 0; j<c; j++){
	  scanf("%d", matrixA[i][j]);
	}
      }
	
    }else{
      **matrixB = malloc(r * sizeof(int *));
      for(int i = 0; i < r; i++){
	matrixB[i] = malloc(c * sizeof(int));
      }      
      printf("Enter the matrix B elements going by rows: ");
      for(int i = 0; i<r; i++){
	for(int j = 0; j<c; j++){
	  scanf("%d", matrixB[i][j]);
	}
      }
    }
  }
  return 0;
}
