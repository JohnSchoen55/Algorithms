#include "sumToN.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
//-94,-93,-92,-82,-68,-48,-42,-24,-24,26,28,31,33,34,44,48,53,68,73,84,89
using namespace std;

int main( int argc , char* argv[] ){
  int sum=7;

vector<int> number {2,4,8,8,10};
//for(int i=0; i<number.size(); ++i)
  //std::cout << number[i] << ' ';
  //vector<int> number;
  if( sumToN( number , sum ) ){
    cout << "There are two numbers." << endl;
  }
  else{
    cout << "There are not two numbers." << endl;
  }
  return 0;
}
