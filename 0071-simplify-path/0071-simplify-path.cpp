class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr = "";

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!curr.empty()) {
                    if (curr == "..") {
                        if (!stack.empty()) stack.pop_back();
                    } else if (curr != ".") {
                        stack.push_back(curr);
                    }
                    curr.clear();
                }
            } else {
                curr.push_back(path[i]);
            }
        }

        // Process last collected segment
        if (!curr.empty()) {
            if (curr == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (curr != ".") {
                stack.push_back(curr);
            }
        }

        // Build result
        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i < stack.size() - 1) result += "/";
        }
        return result;
    }
};
