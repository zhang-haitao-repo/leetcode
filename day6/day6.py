"""
LeeTCode：数组

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        LeeTCode：自己的方案

        思路：将列表转为整型数字，然后加一在转会列表。

        执行用时：36 ms

        内存消耗：13.9 MB
        """
        lens = len(digits)
        data = []
        num = 0
        for i in range(lens):
            num = (num * 10) + digits[i]
        num += 1
        while num != 0:
            data.append(num % 10)
            num = num // 10
        data.reverse()
        return data

    def plusOne1(self, digits: List[int]) -> List[int]:
        pass


def main():
    list_input = [9]
    s = Solution()

    start = time.perf_counter()
    print(s.plusOne(list_input))
    print(s.plusOne1(list_input))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()