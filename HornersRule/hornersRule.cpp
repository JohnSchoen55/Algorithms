#include <vector>
#include "hornersRule.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hornersRule( vector<int> coeffs , int value ){
  
  int result = coeffs[0];
  for (int i = 1; i < coeffs.size(); i++)
      result = result * value + coeffs[i];

  return result;
}
