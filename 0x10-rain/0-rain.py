#!/usr/bin/python3

""" calculate how many square units of water will be retained after it rains.
"""


def rain(walls):
    """ Integer indicating total amount of rainwater retained.
    """
    water = 0
    for i in range(1, len(walls) - 1):

        last = walls[i]
        for j in range(i):
            last = max(last, walls[j])
        first = walls[i]
        for j in range(i + 1, len(walls)):
            first = max(first, walls[j])

        water += (min(last, first) - walls[i])

    return water
