class Solution {

private:
   bool isValid(int n, vector<int>& arr, int d) {
        for (int m : arr) {
            if (abs(m - n) <= d) return false;
        }
        return true;
   }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int n : arr1) {
            if (isValid(n, arr2, d)){
                ans++;
            }
        }
        return ans;
    }
};