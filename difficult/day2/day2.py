"""
LeeTCode：动态规划-打家劫舍

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        :param nums:
        :param board: board (数独)

        :return: bool （True/False）

        思路：动态规划
        """
        if not nums:
            return 0

        size = len(nums)
        if size == 1:
            return nums[0]

        dp = [0] * size
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, size):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

        return dp[size - 1]


def main():
    list_input = [2,1,1,2]
    s = Solution()

    start = time.perf_counter()
    print(s.rob(list_input))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()
