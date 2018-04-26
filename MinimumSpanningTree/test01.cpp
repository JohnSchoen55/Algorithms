#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <cmath>
#include "minimumST.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream matrixFile( "part01test01.matrix.output");
  istream_iterator<double> mStart(matrixFile),mEnd;
  vector<double> matrixArray(mStart,mEnd);

  int dimensions = (int)(sqrt( matrixArray.size() ));
  vector<double> row(dimensions,0);
  vector< vector<double> > matrix(dimensions,row);

  for( int i = 0; i < dimensions; i++ ){
    for( int j = 0; j < dimensions; j++ ){
      matrix[j][i] = matrixArray[j*dimensions+i];
    }
  }

  try{
    cout << "The minimum spanning tree value: " << minimumST( matrix );
    cout << endl;
  }
  catch( int e ){
    cerr << "An error occurred" << endl;
  }
  return 0;
}
