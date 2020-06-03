"""
LeeTCode：动态规划-打家劫舍

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        :param heights:

        :return: bool （True/False）

        思路：动态规划
        """
        lens = len(heights)
        out_max = 0
        for i in range(lens):
            num = heights[i]
            j = i
            weight = 0
            while heights[j] >= num:
                j -= 1
                weight += 1
                if j < 0:
                    break
            j = i+1
            while j < lens and heights[j] >= num:
                j += 1
                weight += 1
            out = heights[i]*weight
            if out_max < out:
                out_max = out
        return out_max
        pass


def main():
    list_input = [2,1,1,2]
    s = Solution()

    start = time.perf_counter()
    print(s.largestRectangleArea([0,1]))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()
