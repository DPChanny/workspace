def exchangesort(size, array):
    for out_idx in range(0, size):
        for in_idx in range(out_idx + 1, size):
            if array[out_idx] > array[in_idx]:
                array[in_idx], array[out_idx] = array[out_idx], array[in_idx]
