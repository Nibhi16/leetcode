class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true, allLower = true;

        for (char c : word) {
            if (!isupper(c)) allUpper = false;
            if (!islower(c)) allLower = false;
        }

        // Case 3: First letter capital + rest lowercase
        bool firstUpperRestLower = isupper(word[0]);
        for (int i = 1; i < word.size(); i++) {
            if (!islower(word[i])) {
                firstUpperRestLower = false;
                break;
            }
        }

        return allUpper || allLower || firstUpperRestLower;
    }
};
