# quicksort.py
# https://blog.csdn.net/qq_39438086/article/details/95055145
def sort(nums):
    quick_sort(nums, 0, len(nums))

def quick_sort(nums, l, r):
    if r - l <= 1: return
    # print(nums)
    ll, rr = partition(nums, l, r)
    # print("mid: {0}".format(mid))
    # print(ll, rr)
    quick_sort(nums, l, rr+1)
    quick_sort(nums, ll, r)


def partition(nums, l, r):
    r = r - 1
    pivot = nums[r]
    
    while(l <= r):
        while(nums[l] < pivot):
            l = l + 1
        while(pivot < nums[r]):
            r = r - 1
        if (l <= r):
            nums[r], nums[l] = nums[l], nums[r]
            l = l + 1
            r = r - 1
    # 如果仅仅返回l，当l恰好等于函数参数中的r时就会在接下来的quicksort函数中陷入死循环
    # quickSort(nums, l, r)
    # partition(nums, l, r) -> mid == r
    # quickSort(nums, l, mid==r)
    return l, r

def quick_sort2(nums, l, r):
    if r - l <= 1: return
    # print(nums)
    mid = partition2(nums, l, r)
    # print("mid: {0}".format(mid))
    # print(ll, rr)
    quick_sort(nums, l, mid)
    quick_sort(nums, mid, r)

def partition2(nums, l, r):
    """在python中函数返回l和r不是一件难事，但是在c语言或
    c++中这意味着需要为数组开辟存储空间或者声明静态变量

    partition2是一种在底层语言中比较容易实现的方式
    """
    r = r - 1
    pivot = nums[r]

    while True:
        while(nums[l] < pivot):
            l = l + 1
        while(nums[r] > pivot):
            r = r - 1
        if (l >= r):
            return l
        else:
            nums[r], nums[l] = nums[l], nums[r]
            l = l + 1
            r = r - 1
        

def is_sorted(nums):
    ans = True
    for i in range(1, len(nums)):
        ans = ans and (nums[i-1] <= nums[i])
        if not ans: return ans
    return ans

if __name__ == "__main__":
    from random import randint
    lens = [10, 300, 2000, 5023, 10012]
    for length in lens:
        nums = [0] * length
        for i in range(len(nums)):
            nums[i] = randint(0, 60000) % length
        quick_sort2(nums, 0, len(nums))
        print(is_sorted(nums))