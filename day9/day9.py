"""
LeeTCode：数组-旋转图像

date：2020-6-02

作者：张海涛
"""
from typing import List
import time


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        :param matrix:

        思路：暴力解法
        """

        lens = len(matrix)
        a = matrix
        for i in range(lens):
            matrix[i][i]

        pass

    def rotate1(self, board: List[List[str]]) -> bool:
        pass


def main():

    s = Solution()

    start = time.perf_counter()
    print(s.isValidSudoku([
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()

