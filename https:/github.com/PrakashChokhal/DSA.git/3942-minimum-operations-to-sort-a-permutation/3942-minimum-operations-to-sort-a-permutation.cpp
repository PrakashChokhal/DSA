class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int x = 1, y = 1;
        for (int i = 1; i<n; i++) {
            x += nums[i] == (nums[i-1] + 1) % n;
            y += nums[i-1] == (nums[i] + 1) % n;
        }
        if (x == n) return nums.front() ? min(n - nums.front(), nums.front() + 2) : 0;
        if (y == n) return min(n - nums.back(), nums.back()) + 1;

        return -1;
    }
};