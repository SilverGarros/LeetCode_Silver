from typing import List


class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]


solution1 = Solution1()
result = solution1.twoSum([2, 7, 11, 15], 9)
print(result)
