#include <vector>
#include "sumToN.h"
#include <cmath>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool sumToN( vector<int> number , int value ){
  int count=1;
  int i = 0;
  int j = number.size()-1;
  while (number[i]<number[j]){
         if (number[i] + number[j] == value)
          count++;
         if (count==2)
          return true;
         if (number[i] + number[j] < value)
              i++;
         else j--;
         }
        
          return false;
  }
