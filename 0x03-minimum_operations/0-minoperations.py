#!/usr/bin/python3

def minOperations(n):
    """
    Minimum Operations
    """
    if (n < 2):
        return 0
    my_list = []
    index = 1
    while (n != 1):
        index = index + 1
        if n % index == 0:
            while n % index == 0:
                n /= i
                my_list.append(index)
    return sum(my_list)