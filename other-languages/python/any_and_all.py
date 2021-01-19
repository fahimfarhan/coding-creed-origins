# Enter your code here. Read input from STDIN. Print output to STDOUT
#!/bin/python3

import math
import os
import random
import re
import sys


def is_positive(input):
    return int(input) > 0

def is_palindrome(input):
    input_as_str = str(input)
    input_size = len(input_as_str)
    if(input_size == 1):
        return True
    for i in range(0, input_size//2):
        if(input_as_str[i] != input_as_str[input_size - 1 - i]):
            return False
    return True 


if __name__ == '__main__':
    n = input()
    numbers = input().split()

    # print(n)
    # print(numbers)

    result = True
    for i in numbers:
      result = result and is_positive(i)

    if(result):
      result2 = False
      for i in numbers:
        result2 = result2 or is_palindrome(i)
      result = result2
    
    print(result)
