class Solution {
    vector<string> res;
public:
    void dfs(int idx, unordered_map<char, string>& mp, string part, string& digits) {
        if (idx == digits.size()) {
            res.push_back(part);
            return;
        }
        char num = digits[idx];
        for (auto v : mp[num]) {
            part += v;
            dfs(idx + 1, mp, part, digits);
            part.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        dfs(0, mp, "", digits);
        return res;
    }
};