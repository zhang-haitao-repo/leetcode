"""
LeeTCode：数组

date：2020-5-21

作者：张海涛
"""
from typing import List
import time


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        lens = len(nums)
        if lens == 1:
            return nums[0]
        if nums[1] != nums[0]:
            return nums[0]
        for i in range(1, lens, 2):
            if nums[i] != nums[i-1]:
                return nums[i-1]
        return nums[lens-1]

    def singleNumber1(self, nums: List[int]) -> int:
        num = 0
        for n in nums:
            num ^= n
        return num


def main():
    list_input = [1,2,1,2,3,4,3,4,5,6,5,6,7,8,8]
    s = Solution()

    start = time.perf_counter()
    print(s.singleNumber1(list_input))
    end = time.perf_counter()
    print(end - start)

    start = time.perf_counter()
    print(s.singleNumber(list_input))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()

