class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];

        vector<int> results;
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') results.push_back(a + b);
                        else if (c == '-') results.push_back(a - b);
                        else if (c == '*') results.push_back(a * b);
                    }
                }
            }
        }

        // If results is empty, expression was only a number
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        memo[expression] = results;
        return results;
    }
};
