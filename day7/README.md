# 第七天  -两数之和

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

#### 示例1
输入: nums = [2, 7, 11, 15], target = 9  <br>
输出: [0, 1] <br>
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Do not return anything, modify nums in-place instead.

        执行用时：6396 ms (9.3%) --- 暴力解法

        内存消耗：14.4 MB
        
        时间复杂度：O（n^2）

        """
        lens = len(nums)
        for i in range(lens-1):
            for j in range(i+1, lens):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        """
        Do not return anything, modify nums in-place instead.

        执行用时：63 ms (80.3%)

        内存消耗：14.4 MB

        时间复杂度：O（n）

        解题思路：将目标值与数组的差值存入另一个字典，循环扫描时找到两个和为目标的数字的序列
        """
        use_num = {}
        for i, num in enumerate(nums):
            if target - num in use_num:
                return [use_num.get(target - num), i]
            use_num[num] = i
```

#### *解题思路*：
> *一：*  暴力解法，遍历整个数组两次，寻找合适的数字。<br>
> *二：*  <br>

