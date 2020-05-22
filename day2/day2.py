"""
LeeTCode：数组

date：2020-5-21

作者：张海涛
"""
from typing import List
import time


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        LeeTCode：自己的方案

        思路：先排序，排序后重复元素相邻。

        执行用时：56 ms

        内存消耗：16.9 MB
        """
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                return True
        return False

    def containsDuplicate1(self, nums: List[int]) -> bool:
        """
        LeeTCode：最优方案

        思路：利用元组数据结构不能有重复。

        执行用时：48 ms

        内存消耗：19 MB
        """
        return len(set(nums)) != len(nums)


def main():
    list_input = [2, 2, 1]
    s = Solution()

    start = time.perf_counter()
    print(s.containsDuplicate(list_input))
    end = time.perf_counter()
    print(end - start)

    start = time.perf_counter()
    print(s.containsDuplicate1(list_input))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()
