'''
Created on Jul 20, 2017

@author: John
'''
from sys import argv
def binary_exp(base, mod, exp):
    product=1
    while exp>0: # repeated squaring
        if exp%2==0:
            base = base*base%mod
            exp=exp/2
        else:
            product = product*base%mod
            exp=exp-1
    return product

    
base=int(argv[1])
mod=int(argv[2])
exp=int(argv[3])
result = binary_exp(base, mod, exp)
print result
    
