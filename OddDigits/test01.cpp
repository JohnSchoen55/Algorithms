#include "oddDigits.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;


int main( int argc , char* argv[] ){
  unsigned long long int num;

  cin >> num;

  try{
    fprintf( stdout , "There are %llu odd digits in  %llu.\n" , oddDigits( num ) , num );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
