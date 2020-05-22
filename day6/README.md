# 第五天  -加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

#### 示例1
输入: [1,2,3] <br>
输出: [1,2,4] <br>
解释: 输入数组表示数字 123。<br>

#### 示例2
输入: [4,3,2,1] <br>
输出: [4,3,2,2] <br>
解释: 输入数组表示数字 4321。 <br>

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