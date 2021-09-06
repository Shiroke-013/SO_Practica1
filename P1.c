#include <stdlib.h>
#include <stdio.h>

int r,c;
int **matrixA = NULL;
int **matrixB = NULL;
int **matrixC = NULL;

void getMatrixDims(char matrixName, int *rows, int *cols)
{
    printf("Please enter Matrix %c dimensions \n", matrixName);
    printf("Matrix %c rows \n", matrixName);
    scanf("%d", rows);
    printf("Matrix %c columns \n", matrixName);
    scanf("%d", cols); 
}


int** createMatrix(int r, int c)
{
  int **matrix = (int **) malloc(r * sizeof(int *));

  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(c * sizeof(int));
  }
  
  printf("Enter the matrix A elements going by rows: \n");

  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
      scanf("%d", &matrix[i][j]);
    }
    printf("\n");
  }

  return matrix;
}


int main(void){
  
  char matrixs[] = "AB";

  for (int m = 0; m < 2; m++){
    if (m == 0)
    {
      getMatrixDims(matrixs[m], &r, &c);
      matrixA = createMatrix(r, c);
    } else {
      getMatrixDims(matrixs[m], &r, &c);
      matrixB = createMatrix(r, c);
    }
  }

  //Multiply

  //Show results

  //Free the resources
  free(matrixA);
  free(matrixB);

  return 0;
}
