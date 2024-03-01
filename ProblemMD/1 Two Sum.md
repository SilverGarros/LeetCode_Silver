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
想出一个时间复杂度小于 `O(n2)` 的算法吗？

## Solution/解法:

1.穷举法

#### Python

``` python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
```

C++
