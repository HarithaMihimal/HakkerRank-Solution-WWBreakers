#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'decentNumber' function below.
#
# The function accepts INTEGER n as parameter.
#

# def decentNumber(n):
#     if (n<3):
#         print(-1)
#     elif (n==3):
#         print("555")
#     elif (n==5):
#         print("33333")
#     else:
#         k=''
        
#         for i in range(n//3+1):
#             y=(n-3*i) % 5
#             z=(n-3*i) // 5
#             if(y==0):
#                 k="555"*i+"33333"*z
            
#         print(k)

def decentNumber(n):
    num_fives = n
    while num_fives % 3 != 0:
        num_fives -= 5
    
    if num_fives < 0:
        print(-1)
    else:
        num_threes = n - num_fives
        print('5' * num_fives + '3' * num_threes)
        
        
if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        decentNumber(n)
