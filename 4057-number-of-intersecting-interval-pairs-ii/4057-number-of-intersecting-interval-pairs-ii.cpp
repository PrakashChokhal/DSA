class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long  count = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            int end_i = intervals[i][1];
            // binary search from (i + 1) to (n - 1).
            int l = i + 1;
            int h = n - 1;
            int pos = n;
            while(l <= h){
                int mid = l + (h - l)/2;
                if(intervals[mid][0] > end_i){
                    pos = mid;
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            count += pos - i - 1;
        }
        return count;
    }
};