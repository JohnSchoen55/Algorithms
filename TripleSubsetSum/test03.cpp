#include "makeThreeGroups.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  int number;
 // 6 2 5 8 4
  vector<int> numbers = {3,2,9,9,4,7,5,3,1,8,7,9,8,8,2,7,6,9,2,2};
  //{3,2,9,9,4,7,5,3,1,8,7,9,8,8,2,7,6,9,2,2}
  //while( cin >> number ){
   // numbers.push_back( number );
  //}

  try{
    if( makeThreeGroups( numbers ) ){
      cout << "Three equal groups can be made" << endl;
    }
    else{
      cout << "Three equal groups cannot be made" << endl;
    }
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
