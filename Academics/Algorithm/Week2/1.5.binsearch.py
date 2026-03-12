# name: 박경찬
# student id: 2025105371

from typing import List


def binsearch(n: int, S: List[int], x: int) -> int:
    low, high = 0, n - 1
    location = -1

    while low <= high:
        mid = (low + high) // 2
        if S[mid] == x:
            location = mid
            break

        if S[mid] > x:
            high = mid - 1
        if S[mid] < x:
            low = mid + 1

    return location
