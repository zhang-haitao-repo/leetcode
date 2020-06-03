# 第六天  -移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

#### 示例1
输入: [0,1,0,3,12] <br>
输出: [1,3,12,0,0] <br>

```
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
```

#### *解题思路*：
> *一：*  <br>
> *二：*  <br>

