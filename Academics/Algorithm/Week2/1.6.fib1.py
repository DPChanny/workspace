# name: 박경찬
# student id: 2025105371


def fib1(n: int) -> int:
    if n <= 1:
        return n

    return fib1(n - 1) + fib1(n - 2)
