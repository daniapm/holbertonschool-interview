#!/usr/bin/python3

""" Rotate it 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """
    rotate 2d matrix
    """

    len_matrix = len(matrix[0])

    for i in range(len_matrix - 1, -1, -1):
        for j in range(0, len_matrix):
            matrix[j].append(matrix[i].pop(0))
