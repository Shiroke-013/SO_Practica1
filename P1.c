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

    /*
    int **matrixA = NULL;
    matrixA = (int **)malloc(2 * sizeof(int *));
    matrixA[0] = (int *)malloc(sizeof( *matrixA[0] * 2));
    matrixA[1] = (int *)malloc(sizeof( *matrixA[0] * 3));
    matrixA[2] = (int *)malloc(sizeof( *matrixA[0] * 3));
    matrixA[0][4] = 40;
    //matrixA[2][0] = 50;

    //printf("Matrix %s value; %p \n", 'A', rows);

    free(matrixA);
    */
}


void setMatrixVals(int **matrix, int r, int c)
{
  //
  printf("\nHoli\n");
  matrix = (int **) malloc(r * sizeof(int *));
  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(c * sizeof(int));
  }
  
  printf("Enter the matrix A elements going by rows: ");

  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
      //scanf("%p", matrix[i][j]);
      matrix[i][j] = 4;
    }
  }

  printf("\nValue: %d\n", matrix[0][0]);
}

int main(void){
  
  char matrixs[] = "AB";
  for (int m = 0; m < 2; m++){
    
    if (m == 0)
    {
      getMatrixDims(matrixs[m], &r, &c);
      setMatrixVals(matrixA, r, c);
    } else {
      getMatrixDims(matrixs[m], &r, &c);
      setMatrixVals(matrixB, r, c);
    }
    
  }
  printf("Aca");
  printf("%p", matrixA[0][0]);

  //Multiply

  //Show results
  return 0;
}
