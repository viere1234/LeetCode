class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0;i<nums.size();++i) {
            const int complement = target - nums[i];
            if (map.count(complement)) return {map[complement], i};
            else map[nums[i]] = i;
        }
        return {};
    }
};
