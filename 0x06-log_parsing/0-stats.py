#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""
from sys import stdin


def print_status(file_size, status_codes):
    """
    prints statistics
    """
    print("File size: {:d}".format(file_size))
    for statusCode, times in sorted(status_codes.items()):
        if times:
            print("{:s}: {:d}".format(statusCode, times))

status_codes = {"200": 0,
                "301": 0,
                "400": 0,
                "401": 0,
                "403": 0,
                "404": 0,
                "405": 0,
                "500": 0
                }

number = 0
size = 0
status = 0


try:
    for line in stdin:
        number += 1
        split_line = line.split()

        if len(split_line) > 1:
            size += int(split_line[-1])

        if len(split_line) > 2 and split_line[-2].isnumeric():
            status = split_line[-2]
        else:
            status = 0

        if status in status_codes.keys():
            status_codes[status] += 1

        if number % 10 == 0:
            print_status(size, status_codes)

    print_status(size, status_codes)

except (KeyboardInterrupt):
    print_status(size, status_codes)
    raise
