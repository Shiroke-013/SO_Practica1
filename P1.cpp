#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int x,y;

//cout << 'Please enter Matrix A dimensions \n';
//cout << 'Matrix A rows: \n';
//cinn >> x;
//cout << 'Matrix A columns: \n';
//cinn >> y;
//float matrixA[x][y];
//float matrixB[x][y];

char matrixs[] = {'A','B'};

int main(){
  for (int i = 0; i < 2; i++){
    cout << "Please enter Matrix " << matrixs[i] << " dimensions \n";
    cout << "Matrix " << matrixs[i]<< " rows \n";
    cin >> x;
    cout << "Matrix " << matrixs[i]<< " columns \n";
    cin >> y;

    if(i == 0){
      float matrixA[x][y];
    }else{
      float matrixB[x][y];
    }
  }
  return 0;
}
