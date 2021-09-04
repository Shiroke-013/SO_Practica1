#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int r,c;
int matrixA, matrixB;

int main(void){
  
  char matrixs[] = {'A','B'};
  for (int m = 0; m < 2; m++){
    cout << "Please enter Matrix " << matrixs[m] << " dimensions \n";
    cout << "Matrix " << matrixs[m]<< " rows \n";
    cin >> r;
    cout << "Matrix " << matrixs[m]<< " columns \n";
    cin >> c;

    if(m == 0){
      **matrixA = malloc(r * sizeof(int *));
      for(int i = 0; i < r; i++){
	matrixA[i] = malloc(c * sizeof(int));
      }
      cout << "Enter the matrix A elements going by rows:";
      for(int i = 0; i<r; i++){
	for(int j = 0; j<c; j++){
	  cin >> matrixA[i][j];
	}
      }
	
    }else{
      **matrixB = malloc(r * sizeof(int *));
      for(int i = 0; i < r; i++){
	matrixB[i] = malloc(c * sizeof(int));
      }      
      cout << "Enter the matrix B elements going by rows:";
      for(int i = 0; i<r; i++){
	for(int j = 0; j<c; j++){
	  cin >> matrixB[i][j];
	}
      }
    }
  }
  for(int i=0;i<r;i++){
    for(int j=0; j<c; j++){
      cout << matrixA[i][j];
    }
    cout<<"\n";
  }
  return 0;
}
