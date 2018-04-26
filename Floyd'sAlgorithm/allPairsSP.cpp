#include <vector>
#include "allPairsSP.h"
#include <cmath>
#include <iostream>
#include <iterator> 
#include <algorithm>
#include <limits.h>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > mat , int n ){
  int verts = mat.size();
  vector<vector<double>> d; 
  for (int i = 0; i < verts; i++){ // Mask -1 (infinity) to number large enough so it gets skipped in computation
      for (int j = 0; j < verts; j++){
          if (mat[i][j] == -1){ 
              mat[i][j] = 99; 
      }
              d = mat;
    }
  }
  // Floyd's algorithm
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < verts; i++) {
      for (int j = 0; j < verts; j++) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < verts; i++){ // Rows and columns left with 99 get turned back into -1 for infinity representation
      for (int j = 0; j < verts; j++){
          if (d[i][j] == 99){ 
              d[i][j] = -1; 
      }
    }
  }
    return d;
}
