#include "makeThreeGroups.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <algorithm> 

using namespace std;

bool makeThreeGroups( vector<int> numbers ){

int size = numbers.size();
bool part[999][999]; // don't deallocate
int sum = 0;

  for (int i = 0; i<size; i++){
    sum += numbers[i];
  }

  if(sum % 3 !=0)
    return false;
    
  part[0][0] = true;
  for (int i = 1; i <= sum; i++){
    part[i][i] = false;
  }

  for(int i = 0; i<size; i++){
    for(int j = sum-numbers[i]; j >= 0; j--){
      for(int k = sum-numbers[i]; k >= 0; k--){
        if (part[j][k]){
          part[j+numbers[i]][k] = true;
          part[j][k+numbers[i]] = true;
        }
      }
    }
  }

  return part[sum/3][sum/3];
}
