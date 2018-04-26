#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "hornersRule.h"
using namespace std;

int main(int argc , char* argv[]){
  
  ifstream cFile( "part03test01.coeffs.input");
  istream_iterator<int> cStart(cFile),cEnd;
  vector<int> coeffs(cStart,cEnd);

  ifstream vFile( "part03test01.x.input" );
  istream_iterator<int> vStart(vFile),vEnd;
  vector<int> value(vStart,vEnd);

  int val = hornersRule( coeffs , value[0] );
  
  printf( "Value of %dx^%d" , coeffs[ 0 ] , coeffs.size() - 1 );
  for( int i = 1; i < coeffs.size() - 1; i++ ){
    printf( "%+dx^%d" , coeffs[ i ] , coeffs.size() - 1 - i );
    }
  printf( "%+d at %d is %d\r\n" , coeffs[ coeffs.size() - 1 ] , value[0] , val );

	return 0;
}
