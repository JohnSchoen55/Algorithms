#include "optimalBST.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

using namespace std;

double optimalBST( vector<double> numbers ){
  int size = numbers.size();
  int col = size + 1;
  int row = size + 2;
  vector<double> prob(size+1);
  prob[0] = 0;
    for(int i = 1; i < size+1; i++){
      prob[i] = numbers[i-1];
    }

  vector< vector<double> > c;
  vector< vector<double> > r;
  c.resize(row,vector<double>(col));
  r.resize(row,vector<double>(col));

    for(int i = 1; i <= size; i++){
      c[i][i-1] = 0;
        c[i][i] = prob[i];
          r[i][i] = i;
    }

    for(int d = 1; d < size; d++){
      for(int i = 1; i<=size - d; i++){
          int j = i + d;
            int kmin = 0; 
              double minval = 999;
        for(int k = i; k <= j; k++){
          if(c[i][k-1] + c[k+1][j] < minval){
              minval = c[i][k-1] + c[k+1][j];
                kmin = k;
          }
        }
        r[i][j] = kmin;
        double sum = prob[i];
          for(int s = i+1; s <= j; s++){
            sum += prob[s];
          }
          c[i][j] = minval + sum;
      }
    }
         /* cout<< "Root Table" << endl;
            for(int i=1; i<size+2; i++){
		            for(int j=0; j<size+1; j++){
			              cout << "  "<< r[i][j]  << "  ";
                }
                    cout << endl;
            }*/
        
  return c[1][size];
}

