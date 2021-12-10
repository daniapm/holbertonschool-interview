#!/usr/bin/python3

"""
method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Function that determines if all the boxes can be opened.
    """
    elif (len(boxes)) == 0:
        return False
    for key in range(1, len(boxes) - 1):
        check = False
        for element in range(len(boxes)):
            check = key in boxes[element] and key != element
            if check:
                break
        if check is False:
            return check
    return True