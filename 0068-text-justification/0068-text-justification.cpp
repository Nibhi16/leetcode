class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            // Find how many words fit in this line
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Case 1: Last line OR only one word in this line
            if (j == n || gaps == 0) {
                line = words[i];
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                line += string(maxWidth - line.size(), ' ');
            } 
            else { 
                // Case 2: Fully justify
                int totalSpace = maxWidth - (lineLen - gaps);
                int spaceEach = totalSpace / gaps;
                int extra = totalSpace % gaps;

                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    int spaces = spaceEach + (extra > 0 ? 1 : 0);
                    line += string(spaces, ' ');
                    line += words[k];
                    extra--;
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
