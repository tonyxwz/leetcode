def quicksort2(nums, l, r):
    if (l + 1 >= r): return
    pivot = nums[r - 1]
    lp  = l
    rp = r - 1
    while(1):
        while(nums[lp] < pivot): lp = lp + 1
        while(pivot < nums[rp]): rp = rp - 1
        if (lp >= rp): break
        else:
            nums[lp], nums[rp] = nums[rp], nums[lp]
            lp = lp + 1
            rp = rp - 1
    quicksort2(nums, l, lp)
    quicksort2(nums, lp, r)

if __name__ == "__main__":
    numbers = [1, 1, 3, 2, 4, 1]
    quicksort2(numbers, 0, len(numbers))
    print(numbers)
