from typing import List


def partition(low: int, high: int, S: List[int]) -> int:
    pivot = S[low]
    j = low

    for i in range(low + 1, high + 1):
        if S[i] < pivot:
            j += 1
            S[j], S[i] = S[i], S[j]
    S[low], S[j] = S[j], S[low]
    return j


def quicksort(low: int, high: int, S: List[int]) -> None:
    if low < high:
        pivot = partition(low, high, S)
        quicksort(low, pivot - 1, S)
        quicksort(pivot + 1, high, S)
