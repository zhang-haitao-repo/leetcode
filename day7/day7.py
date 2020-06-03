"""
LeeTCode：数组-移动零

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Do not return anything, modify nums in-place instead.

        执行用时：6396 ms (9.3%) --- 暴力解法

        内存消耗：14.4 MB
        """
        lens = len(nums)
        for i in range(lens-1):
            for j in range(i+1, lens):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        """
        Do not return anything, modify nums in-place instead.

        执行用时：63 ms (80.3%)

        内存消耗：14.4 MB

        解题思路：将目标值与数组的差值存入另一个字典，循环扫描时找到两个和为目标的数字的序列
        """
        use_num = {}
        for i, num in enumerate(nums):
            if target - num in use_num:
                return [use_num.get(target - num), i]
            use_num[num] = i


def main():
    list_input = [1,0,1,0,0,0,0,2,3,4]
    s = Solution()

    start = time.perf_counter()
    print(s.twoSum1([3, 3, 3], 6))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()