#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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

    int main() {
        // 创建 Solution 类的一个实例
        Solution solution;

        // 创建一个整数向量 nums，并初始化它
        vector<int> nums = { 2, 7, 11, 15 };

        // 设置目标整数 target
        int target = 9;

        // 调用 twoSum 方法，并传入 nums 和 target 作为参数
        vector<int> result = solution.twoSum(nums, target);

        // 打印结果
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;

        return 0;
    }
