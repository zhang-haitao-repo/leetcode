"""
LeeTCode：动态规划-拥有最多糖果的孩子

date：2020-6-02

作者：张海涛
"""
from typing import List
import time


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        """
        :param extraCandies:
        :param candies:

        :return: bool （True/False）

        思路：动态规划
        """

        bool_list = []
        lens = len(candies)
        max_data = max(candies)
        for i in range(lens):
            data = extraCandies + candies[i]
            if data >= max_data:
                bool_list.append(True)
            else:
                bool_list.append(False)
        return bool_list

    def kidsWithCandies1(self, candies: List[int], extraCandies: int) -> List[bool]:
        """
        :param extraCandies:
        :param candies:

        :return: bool （True/False）

        思路：动态规划
        """

        maxCandies = max(candies)
        ret = [candy + extraCandies >= maxCandies for candy in candies]
        return ret


def main():
    s = Solution()

    start = time.perf_counter()
    print(s.kidsWithCandies([4,2,1,1,2],2))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()
