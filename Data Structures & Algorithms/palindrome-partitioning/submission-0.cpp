class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, 0, s, part);
        return res;
    }

    void dfs(int j, int i, string &s, vector<string> &part) {
        if (i >= s.size()) {
            if (i == j) {
                res.push_back(part);
            }
            return;
        }

        if (isPali(s, j, i)) {
            string piece;
            for (int k = j; k <= i; k++) {
                piece += s[k];
            }

            part.push_back(piece);
            dfs(i + 1, i + 1, s, part);
            part.pop_back();
        }

        dfs(j, i + 1, s, part);
    }
    bool isPali(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};