#include "pellNumber.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int pellNumber( unsigned long long int number ){
  int i = 3;
  vector<unsigned long long int> memo;
  memo.push_back(0);
  memo.push_back(1);
  memo.push_back(2);
    if(number > 2){
      while(i <= number){
          memo[i%3] = (2*memo[(i-1)%3]) + memo[(i-2)%3];
          i+=1;
      }
    }
  return memo[number % 3];
}
