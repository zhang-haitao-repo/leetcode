# 第四天  -两个数组的交集 II

给定两个数组，编写一个函数来计算它们的交集。 <br>

说明：<br>
> 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。<br>
> 我们可以不考虑输出结果的顺序。<br>

进阶:<br>
>如果给定的数组已经排好序呢？你将如何优化你的算法？<br>
>如果 nums1 的大小比 nums2 小很多，哪种方法更优？<br>
>如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

#### 示例1
输入: nums1 = [1,2,2,1], nums2 = [2,2] <br>
输出: [2,2] <br>

#### 示例2
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4] <br>
输出: [4,9] <br>

```
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
```

#### *解题思路*：
> *一：* 将无序数组先进行排序，然后逐个判断是左右数组的大小，从而找到相同的值。<br>
> *二：* 使用python的元组数据结构进行判断，利用元组结构找出重复的值，再用列表统计值的个数。（元组中不能出现重复的数据）