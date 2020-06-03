"""
LeeTCode：数组-有效的数独

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        :param board: board (数独)

        :return: bool （True/False）

        思路：暴力解法
        """

        lens = len(board)
        high = [[] for a in range(lens)]
        wight = [[] for a in range(lens)]
        box = [[] for a in range(lens)]
        for i in range(lens):
            for j in range(lens):
                if board[i][j] in wight[i] and board[i][j] != ".":
                    return False
                if board[j][i] in high[i] and board[j][i] != ".":
                    return False
                if board[i][j] in box[(i//3)*3 + j//3] and board[i][j] != ".":
                    return False
                wight[i].append(board[i][j])
                high[i].append(board[j][i])
                box[(i//3)*3 + j//3].append(board[i][j])
        return True

    def isValidSudoku1(self, board: List[List[str]]) -> bool:
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
