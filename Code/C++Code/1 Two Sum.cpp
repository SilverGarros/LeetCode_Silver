#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Solution1 暴力穷举法
class Solution1 {
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
//Solution2 哈希表HashTable法
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

int main() {
    // 创建 Solution 类的一个实例
    Solution1 solution1;
    Solution2 solution2;

    // 创建一个整数向量 nums，并初始化它
    vector<int> nums = {3,2,4};

    // 设置目标整数 target
    int target = 6;

    // 调用 twoSum 方法，并传入 nums 和 target 作为参数
    vector<int> hash,result = solution2.twoSum(nums, target);

    // 打印结果
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
