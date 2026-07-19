class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp; // stores last-seen index of each character
        int l = 0;
        int max_length = 0;
        
        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                // duplicate found INSIDE the current window -> jump l past it
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r; // record/update last-seen index of s[r]
            max_length = max(max_length, r - l + 1);
        }
        
        return max_length;
    }
};