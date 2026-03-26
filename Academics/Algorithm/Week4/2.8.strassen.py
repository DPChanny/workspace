from typing import Tuple


class Matrix:
    def __init__(self, mat):
        self.n = len(mat)
        self.matrix = mat

    def __add__(self, other):
        mat = [[0] * self.n for _ in range(self.n)]
        for i in range(self.n):
            for j in range(self.n):
                mat[i][j] = self.matrix[i][j] + other.matrix[i][j]
        return Matrix(mat)

    def __sub__(self, other):
        mat = [[0] * self.n for _ in range(self.n)]
        for i in range(self.n):
            for j in range(self.n):
                mat[i][j] = self.matrix[i][j] - other.matrix[i][j]
        return Matrix(mat)

    def __mul__(self, other):
        mat = [[0] * self.n for _ in range(self.n)]
        for i in range(self.n):
            for j in range(self.n):
                for k in range(self.n):
                    mat[i][j] += self.matrix[i][k] * other.matrix[k][j]
        return Matrix(mat)


def partition(n: int, M: Matrix) -> Tuple[Matrix, Matrix, Matrix, Matrix]:
    m = n // 2
    m1 = [[0] * m for _ in range(m)]
    m2 = [[0] * m for _ in range(m)]
    m3 = [[0] * m for _ in range(m)]
    m4 = [[0] * m for _ in range(m)]
    for i in range(m):
        for j in range(m):
            m1[i][j] = M.matrix[i][j]
            m2[i][j] = M.matrix[i][j + m]
            m3[i][j] = M.matrix[i + m][j]
            m4[i][j] = M.matrix[i + m][j + m]

    return Matrix(m1), Matrix(m2), Matrix(m3), Matrix(m4)


def combine(n: int, M1: Matrix, M2: Matrix, M3: Matrix, M4: Matrix) -> Matrix:
    m = n // 2
    mat = [[0] * n for _ in range(n)]
    for i in range(m):
        for j in range(m):
            mat[i][j] = M1.matrix[i][j]
            mat[i][j + m] = M2.matrix[i][j]
            mat[i + m][j] = M3.matrix[i][j]
            mat[i + m][j + m] = M4.matrix[i][j]

    return Matrix(mat)


def strassen(n: int, A: Matrix, B: Matrix) -> Matrix:
    global threshold

    if n <= threshold:
        return A * B
    else:
        A11, A12, A21, A22 = partition(n, A)
        B11, B12, B21, B22 = partition(n, B)

        M1 = strassen(n // 2, A11 + A22, B11 + B22)
        M2 = strassen(n // 2, A21 + A22, B11)
        M3 = strassen(n // 2, A11, B12 - B22)
        M4 = strassen(n // 2, A22, B21 - B11)
        M5 = strassen(n // 2, A11 + A12, B22)
        M6 = strassen(n // 2, A21 - A11, B11 + B12)
        M7 = strassen(n // 2, A12 - A22, B21 + B22)

        C11 = M1 + M4 - M5 + M7
        C12 = M3 + M5
        C21 = M2 + M4
        C22 = M1 - M2 + M3 + M6

        return combine(n, C11, C12, C21, C22)


threshold = 1
