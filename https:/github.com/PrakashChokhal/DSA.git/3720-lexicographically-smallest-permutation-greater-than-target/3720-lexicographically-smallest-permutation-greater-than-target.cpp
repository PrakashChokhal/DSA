class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // Try making the answer greater at this position
            for (int y = x + 1; y < 26; y++) {
                if (cnt[y] > 0) {
                    string res = target.substr(0, i);

                    // Put the smallest greater character
                    res += char('a' + y);

                    cnt[y]--;

                    // Put all remaining characters in sorted order
                    for (int k = 0; k < 26; k++)
                        res += string(cnt[k], char('a' + k));

                    ans = res;

                    cnt[y]++;
                    break;
                }
            }

            // To continue matching target, this character must exist
            if (cnt[x] == 0)
                break;

            cnt[x]--;
        }

        return ans;
    }
};