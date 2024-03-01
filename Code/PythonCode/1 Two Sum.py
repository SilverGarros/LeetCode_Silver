from typing import List


# Solution1 暴力穷举法
class Solution1:
    @staticmethod
    def twoSum(nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]


# Solution2 哈希表HashTable法
class Solution2:
    @staticmethod
    def twoSum(nums: List[int], target: int) -> List[int]:
        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []


def test_twoSum(solution):
    nums = [2, 7, 11, 15]
    target = 9
    assert solution.twoSum(nums, target) == [0, 1]
    nums = [3, 2, 4]
    target = 6
    assert solution.twoSum(nums, target) == [1, 2]
    nums = [3, 3]
    target = 6
    assert solution.twoSum(nums, target) == [0, 1]
    nums = [3, 2, 3]
    target = 6
    assert solution.twoSum(nums, target) == [0, 2]
    print("通过")


test_twoSum(solution=Solution1)
test_twoSum(solution=Solution2)
