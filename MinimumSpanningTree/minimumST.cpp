#include <vector>
#include "minimumST.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

double minimumST( vector< vector<double> > matrix) {
int edges=0;
int size = matrix.size();
int col = 0;
int sum = 0;
vector<bool> selected (size);
  for (int i = 0; i<size; i++)
      selected[i]=false;

  selected[0] = true;
  while (edges < size - 1){
    int inf = 9999999;
    for (int i = 0; i < size; i++){
      if (selected[i]){
        for (int j = 0; j < size; j++){
          if (!selected[j] && matrix[i][j]){
            if (inf > matrix[i][j]){
              inf = matrix[i][j];
              col = j;
              }
            }
          }
        }
      }
    sum = sum + inf % 10;
    inf = inf / 10;
    selected[col] = true;
    edges++;
  }
  return sum;
}
