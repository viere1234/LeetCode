class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, ans=0;
        bool store[256]={false};
        while(r<s.length()) {
            while(store[s[r]]) store[s[l++]] = false;
            store[s[r]] = true;
            ans = max(ans, r-l+1);
            ++r;
        }
        return ans;
    }
};
