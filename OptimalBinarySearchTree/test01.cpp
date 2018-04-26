#include "optimalBST.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  int number;
  int sum = 0;
    //vector<double> numbers = {5,8,11,7,5,10,12,9,8,8,17};
    vector<double> numbers;
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(11);
    numbers.push_back(7);
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(12);
    numbers.push_back(9);
    numbers.push_back(8);
    numbers.push_back(8);
    numbers.push_back(17);
  /*while( cin >> number ){
    numbers.push_back( number * 1.0 );
    sum += number;
  }

  for( int i = 0; i < numbers.size(); i++ ){
    numbers[i] /= sum;
  }
  */
  
  try{
    fprintf( stdout , "At best, %.2f comparisons are needed on average\n" , optimalBST( numbers ) );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
