# 第三天  -只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。<br>

说明：<br>

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？<br>

#### 示例1
输入: [1,2,2,1,3] <br>
输出: 3 <br>

#### 示例2
输入: [1,2,2] <br>
输出: 1 <br>

#### 示例3
输入: [4,1,2,1,2] <br>
输出: 4 <br>

```
def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        lens = len(nums)
        if lens == 1:
            return nums[0]
        if nums[1] != nums[0]:
            return nums[0]
        for i in range(1, lens, 2):
            if nums[i] != nums[i-1]:
                return nums[i-1]
        return nums[lens-1]
```
#### *解题思路*：
> *一：* 将无序数组先进行排序，然后判断是否有连续的数字,在遍历数组时一次进两位。<br>
> *二：* 使用python的异或运算。（0^num = num / num ^ num = 0 /n ^ m = m -n）