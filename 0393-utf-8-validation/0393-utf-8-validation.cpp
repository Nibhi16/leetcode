class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remaining = 0; // number of expected continuation bytes
        
        for (int num : data) {
            if (remaining == 0) {
                // Check how many leading 1s
                if ((num >> 7) == 0b0) {
                    // 1-byte character (0xxxxxxx)
                    continue;
                } else if ((num >> 5) == 0b110) {
                    remaining = 1;
                } else if ((num >> 4) == 0b1110) {
                    remaining = 2;
                } else if ((num >> 3) == 0b11110) {
                    remaining = 3;
                } else {
                    return false; // invalid leading byte
                }
            } else {
                // Must be continuation byte (10xxxxxx)
                if ((num >> 6) != 0b10)
                    return false;
                
                remaining--;
            }
        }
        return remaining == 0; // all sequences complete
    }
};
