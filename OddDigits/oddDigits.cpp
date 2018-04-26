#include "oddDigits.h"
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

unsigned long long int c;
unsigned long long int oddDigits( unsigned long long int digits){

 unsigned long long int a = digits%10;
 unsigned long long int b = digits/10;
 
  if(a%2==1)
    c++;
  if(digits<10)
    return c;
 
 oddDigits(b);
 }


