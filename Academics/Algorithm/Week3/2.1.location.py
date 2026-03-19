from typing import List


def location(low: int, high: int, S: List[int], x: int) -> int:
    if low > high:
        return -1
    else:
        mid = (low + high) // 2
        if S[mid] == x:
            return mid
        elif S[mid] > x:
            return location(low, mid - 1, S, x)
        else:
            return location(mid + 1, high, S, x)
