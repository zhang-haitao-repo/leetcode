"""
LeeTCode：动态规划-新21点

date：2020-6-03

作者：张海涛
"""
from typing import List
import time


class Solution:
    def new21Game(self, N: int, k: int, w: int) -> float:

        dp = [0] * (k + w)
        s = 0
        for i in range(k, k + w):
            dp[i] = 1 if i <= N else 0
            s += dp[i]
        for i in range(k-1, -1, -1):
            dp[i] = s/w
            s = s - dp[i + w] + dp[i]
        print(dp)

        return dp[0]


def main():
    s = Solution()

    start = time.perf_counter()
    print(s.new21Game(21, 17, 10))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()
