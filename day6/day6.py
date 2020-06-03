"""
LeeTCode：数组-移动零

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.

        执行用时：720 ms

        内存消耗：14.4 MB
        """
        lens = len(nums)
        for i in range(lens - 1):
            j = 1
            if nums[i] == 0:
                while nums[i + j] == 0 and (i + j) < lens - 1:
                    j += 1
                a = nums[i + j]
                nums[i+j] = nums[i]
                nums[i] = a

    def moveZeroes1(self, nums: List[int]) -> None:
        n = len(nums)
        if n == 0:
            return
        j = 0
        for i in range(n):
            if nums[i] != 0:
                if i > j:
                    nums[j] = nums[i]
                    nums[i] = 0
                j += 1


def main():
    list_input = [1,0,1,0,0,0,0,2,3,4]
    s = Solution()

    start = time.perf_counter()
    print(s.moveZeroes(list_input))
    print(list_input)
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()