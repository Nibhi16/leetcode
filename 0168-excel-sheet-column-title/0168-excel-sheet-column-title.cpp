class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--;  // Adjust because Excel is 1-indexed
            int rem = columnNumber % 26;
            result.push_back('A' + rem);
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
