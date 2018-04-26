#include <vector>
#include "overlappingIntervals.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int overlappingIntervals( vector<int> start , vector<int> end ){
 sort(end.begin(),end.end());
 int total = 0;
 int max = 0;
 size_t i = 0;
 size_t j = 0;
 while (i<start.size() && j<end.size()){
    if (start[i]<end[j]){
        max++;
        total = std::max(total, max);
        i++;
    }
    else{
        max--;
        j++;
    }
 }
    

  return total;
}

