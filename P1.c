#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int r,c, cA, rB;
int **matrixA = NULL;
int **matrixB = NULL;
int **matrixC = NULL;

struct t {
  int row;
  int column;
};


void getMatrixDims(char matrixName, int *rows, int *cols)
{
    printf("Please enter Matrix %c dimensions \n", matrixName);
    printf("Matrix %c rows \n", matrixName);
    scanf("%d", rows);
    if(matrixName == 'B'){rB = r;}
    printf("Matrix %c columns \n", matrixName);
    scanf("%d", cols);
    if(matrixName == 'A'){cA = c;}
}


int** createMatrix(char matrixName, int r, int c)
{
  int **matrix = (int **) malloc(r * sizeof(int *));

  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(c * sizeof(int));
  }
  
  printf("Enter the matrix %c elements going by rows: \n", matrixName);

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
      matrixA = createMatrix(matrixs[m], r, c);
    } else {
      getMatrixDims(matrixs[m], &r, &c);
      matrixB = createMatrix(matrixs[m], r, c);
    }
  }

  //Multiply
  if(cA == rB){
    //Number of threads to be created
    int nThreads = cA * rB;
    //Creating threads
    pthread_t tid[nThreads];
    for(int i = 0; i < nThreads; i++){
      pthread_create(&tid[i], NULL, );
    }
    //Waiting threads
    for(int i = 0; i < nThreads; i++){
      pthread_join(tid[i], NULL);
    }
  }else{
    printf("Lo lamento pero el numero de columnas de la matriz A debe ser el mismo que el numero de filas de la matriz B");
  }
  //Show results

  //Free the resources
  free(matrixA);
  free(matrixB);

  return 0;
}
