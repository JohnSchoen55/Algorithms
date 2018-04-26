#include "pellNumber.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  unsigned long long int i;
  cin >> i;
  
  try{
    fprintf( stdout , "Pell number %llu is %llu\n" , i , pellNumber( i ) );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
