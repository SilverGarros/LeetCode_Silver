# 1. Two Sum

https://leetcode.com/problems/two-sum/description

`Easy`

## **Description**

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.
给定一个整数数组 `nums` 和一个整数目标数 `target` ，返回 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

You may assume that each input would have exactly one solution, and you may not use the same element twice.
可以假设每个输入只有一个解，数组中同一个元素在解里不能重复出现。

You can return the answer in any order.
可以按任何顺序返回答案。

Example 1:

> Input: nums = [2,7,11,15], target = 9
> Output: [0,1]
> Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
> 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

Example 2:

> Input: nums = [3,2,4], target = 6
> Output: [1,2]

Example 3:

> Input: nums = [3,3], target = 6
> Output: [0,1]

## **Constraints**:
- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **Only one valid answer exists.**
  **只会存在一个有效答案**

## **Follow-up/进阶**: 

Can you come up with an algorithm that is less than O(n2) time complexity?
想出一个时间复杂度小于 `O(n2)` 的算法

## Solution/解法:

#### 1.暴力穷举法

###### 复杂度分析

- 时间复杂度：O(N^2)，其中 NN*N* 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。
- 空间复杂度：O(1)

###### Python

``` python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
```

###### C++

``` C++
public:vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }
        return {};
    }
};
```

#### 2.散列表哈希表法

> #### **哈希表HashTable**
>
> 散列表（Hash table，也叫哈希表），**是根据键（Key）而直接访问在内存存储位置的数据结构。也就是说，它通过计算一个关于键值的函数，将所需查询的数据映射到表中一个位置来访问记录，这加快了查找速度。这个映射函数称做哈希函数，存放记录的数组称做哈希表**

> #### 常见的哈希函数
>
> 一个哈希函数的好不好，取决于以下三点
>
> - 哈希函数的定义域必须包括需要存储的全部关键码，而如果哈希表允许有m个地址时，其值域必须在0 到m-1之间
> - 哈希函数计算出来的地址能均匀分布在整个空间中
> - 哈希函数应该比较简单

###### python

``` python
class Solution2:
    @staticmethod
    def twoSum(nums: List[int], target: int) -> List[int]:
        hashtable = dict() # 建立hash表
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return [-1,-1]
```

###### C++

``` C++
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a; //建立hash表a存放数组元素
        vector<int> b(2, -1); //建立数组b存放结果
        for (int i = 0; i < nums.size(); i++)
            a.insert(map<int, int>::value_type(nums[i], i));
            // a[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
            {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }          
        }
        return b;
    };
};
```

