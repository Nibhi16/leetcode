class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int numWords = words.size();
        int substringLen = wordLen * numWords;
        int n = s.size();

        unordered_map<string, int> wordCount;
        for (const auto& word : words) wordCount[word]++;

        for (int i = 0; i < wordLen; ++i) { // shift start to cover all alignments
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int j = i; j <= n - wordLen; j += wordLen) {
                string w = s.substr(j, wordLen);
                if (wordCount.count(w)) {
                    window[w]++;
                    count++;

                    while (window[w] > wordCount[w]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                        // move left to search next possible
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
