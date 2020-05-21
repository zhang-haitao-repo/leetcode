"""
LeeTCode：数组

date：2020-5-21

作者：张海涛
"""
from typing import List
import time


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        LeeTCode：自己的方案

        思路：想要获利肯定后一天要比前一天收入多。

        执行用时：76 ms

        内存消耗：15 MB
        """
        profit = 0
        if len(prices) == 0:
            return 0
        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                profit += (prices[i+1] - prices[i])
                pass
        return profit

    def maxProfit1(self, prices: List[int]) -> int:
        """
        LeeTCode：自己的方案

        思路：想要获利肯定后一天要比前一天收入多。

        执行用时：28 ms

        内存消耗：15 MB
        """
        profit = 0
        lens = len(prices)
        for i in range(1, lens):
            j = prices[i] - prices[i-1]
            if j > 0:
                profit += j
        return profit


def main():
    list_input = [1,2,3,4,5]

    s = Solution()

    start = time.perf_counter()
    print(s.maxProfit(list_input))
    end = time.perf_counter()
    print(end - start)

    start = time.perf_counter()
    print(s.maxProfit1(list_input))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()