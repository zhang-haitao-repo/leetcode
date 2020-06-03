"""
LeeTCode：递归--对称树

date：2020-5-22

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
    def isSymmetric(self, root: TreeNode) -> bool:
        """
        :param root:

        :return: bool （True/False）

        思路：动态规划
        """

        left = TreeNode(0)
        right = TreeNode(0)
        if root:
            left = root.left
            right = root.right
        else:
            return True
        while left and right:
            if left.val != right.val and left.left.val != right.right.valcr2:
                return False


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