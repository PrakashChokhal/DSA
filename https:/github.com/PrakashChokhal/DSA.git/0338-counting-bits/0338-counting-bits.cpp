class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (ans * 2 == i) {
                ans = i;
            }
            dp[i] = dp[i - ans] + 1;
        }
        return dp;
    }
};