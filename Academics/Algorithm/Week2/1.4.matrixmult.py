# name: 박경찬
# student id: 2025105371

from typing import List


def matrixmult(n: int, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
    C = [[0] * n for _ in range(n)]

    for a_row in range(n):
        for b_col in range(n):
            C[a_row][b_col] = 0
            for i in range(n):
                C[a_row][b_col] = C[a_row][b_col] + A[a_row][i] * B[i][b_col]

    return C
