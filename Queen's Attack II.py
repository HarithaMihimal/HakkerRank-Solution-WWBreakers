#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER r_q
#  4. INTEGER c_q
#  5. 2D_INTEGER_ARRAY obstacles
#

def queensAttack(n, k, r_q, c_q, obstacles):
    # Directions: [row change, column change]
    directions = {
        "left": (0, -1),
        "right": (0, 1),
        "up": (1, 0),
        "down": (-1, 0),
        "up-left": (1, -1),
        "up-right": (1, 1),
        "down-left": (-1, -1),
        "down-right": (-1, 1)
    }

    # Initialize the maximum possible moves in all directions
    moves = {
        "left": c_q - 1,
        "right": n - c_q,
        "up": n - r_q,
        "down": r_q - 1,
        "up-left": min(n - r_q, c_q - 1),
        "up-right": min(n - r_q, n - c_q),
        "down-left": min(r_q - 1, c_q - 1),
        "down-right": min(r_q - 1, n - c_q)
    }

    # Adjust moves according to the position of each obstacle
    for obstacle in obstacles:
        r_o, c_o = obstacle
        
        if r_o == r_q:  # Same row
            if c_o < c_q:  # Obstacle to the left
                moves["left"] = min(moves["left"], c_q - c_o - 1)
            elif c_o > c_q:  # Obstacle to the right
                moves["right"] = min(moves["right"], c_o - c_q - 1)
        
        elif c_o == c_q:  # Same column
            if r_o < r_q:  # Obstacle below
                moves["down"] = min(moves["down"], r_q - r_o - 1)
            elif r_o > r_q:  # Obstacle above
                moves["up"] = min(moves["up"], r_o - r_q - 1)
        
        elif abs(r_o - r_q) == abs(c_o - c_q):  # Same diagonal
            if r_o > r_q and c_o < c_q:  # Obstacle up-left
                moves["up-left"] = min(moves["up-left"], r_o - r_q - 1)
            elif r_o > r_q and c_o > c_q:  # Obstacle up-right
                moves["up-right"] = min(moves["up-right"], r_o - r_q - 1)
            elif r_o < r_q and c_o < c_q:  # Obstacle down-left
                moves["down-left"] = min(moves["down-left"], r_q - r_o - 1)
            elif r_o < r_q and c_o > c_q:  # Obstacle down-right
                moves["down-right"] = min(moves["down-right"], r_q - r_o - 1)

    # Sum up all possible moves
    return sum(moves.values())

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
