class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int curr = 0;
        bool down = true;

        for (char c : s) {
            rows[curr] += c;

            if (down) {
                curr++;
                if (curr == numRows - 1) down = false;
            } else {
                curr--;
                if (curr == 0) down = true;
            }
        }

        string result = "";
        for (string &row : rows) result += row;
        return result;
    }
};
