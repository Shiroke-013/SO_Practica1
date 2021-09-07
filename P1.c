#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int r,c, cA, rA, rB, cB;
int **matrixA = NULL;
int **matrixB = NULL;
int **matrixC = NULL;

struct threadStruct {
  int row;
  int column;
};


void getMatrixDims(char matrixName, int *rows, int *cols)
{
    printf("Please enter Matrix %c dimensions \n", matrixName);
    printf("Matrix %c rows \n", matrixName);
    scanf("%d", rows);
    printf("Matrix %c columns \n", matrixName);
    scanf("%d", cols);
    if(matrixName == 'B'){rB = *rows; cB = *cols;}
    if(matrixName == 'A'){cA = *cols; rA = *rows;}
}

void *multiplication(void* thr){
  struct threadStruct *myT = (struct threadStruct*)thr;
  int actualr = (*myT).row;
  int actualc = (*myT).column;
  int count = 0;
  
  for(int i = 0; i < cA; i++){
    count += (matrixA[actualr][i] * matrixB[i][actualc]);
  }
  
  matrixC[actualr][actualc] = count;

  free(thr);
  return NULL;
}

int** createMatrix(char matrixName, int r, int c)
{
  int **matrix = (int **) malloc(r * sizeof(int *));

  for(int i = 0; i < r; i++){
    matrix[i] = (int *) malloc(c * sizeof(int));
  }

  if(matrixName == 'B' || matrixName == 'A'){
    printf("Enter the matrix %c elements going by rows: \n", matrixName);
    for(int i = 0; i<r; i++){
      for(int j = 0; j<c; j++){
	scanf("%d", &matrix[i][j]);
      }
      printf("\n");
    }
    return matrix;
  }

  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
      matrix[i][j] = 0;
    }    
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

  //MULTiPLY
  if(cA == rB){
    matrixC = createMatrix('C', rA, cB);
    //NUMBER OF THREADS TO BE CREATED
    int nThreads = rA * cB;
    int t = 0;
    struct threadStruct *thr;
    
    //CREATiNG THREADS
    pthread_t tid[nThreads];
    for(int i = 0; i < rA; i++){
      for(int j = 0; j < cB; j++){
	thr = (struct threadStruct *) malloc(sizeof(struct threadStruct));
	(*thr).row = i;
	(*thr).column = j;
	pthread_create(&tid[t], NULL, multiplication, (void *)thr);
	t++;
      }
    }
    //Waiting threads
    for(int i = 0; i < nThreads; i++){
      pthread_join(tid[i], NULL);
    }
  }else{
    printf("Lo lamento pero el numero de columnas de la matriz A debe ser el mismo que el numero de filas de la matriz B");
  }


  //Show results
  for(int i = 0; i < rA; i++){
    for(int j = 0; j < cB; j++){
      printf("%d\t", matrixC[i][j]);
    }
    printf("\n");
  }

  //Free the resources
  free(matrixA);
  free(matrixB);
  free(matrixC);

  return 0;
}
