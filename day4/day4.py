"""
LeeTCode：数组

date：2020-5-22

作者：张海涛
"""
from typing import List
import time


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        list_add = []
        num1 = set(nums1)
        num2 = set(nums2)
        for i in num1:
            if i in num2:
                count = min(nums1.count(i), nums2.count(i))
                for j in range(count):
                    list_add.append(i)
        return list_add

    def intersect1(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        r = []
        left,right = 0,0
        while left < len(nums1) and right < len(nums2):
            if nums1[left] < nums2[right]:
                left += 1
            elif nums1[left] == nums2[right]:
                r.append(nums1[left])
                left += 1
                right += 1
            else:
                right += 1
        return r


def main():
    list_input = [2, 2, 1]
    s = Solution()

    start = time.perf_counter()
    print(s.intersect([1,2,2,1], [2,2]))
    print(s.intersect1([1,2,2,1], [2,2]))
    end = time.perf_counter()
    print(end - start)


if __name__ == '__main__':
    main()