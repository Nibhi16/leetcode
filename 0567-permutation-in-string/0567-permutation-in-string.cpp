class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        vector<int> freq1(26);
        vector<int> freq2(26);
        for(char c : s1){
            freq1[c - 'a']++;
        }
        int i=0;
        int j=0;
        while(j<m){
            freq2[s2[j]-'a']++;
            if(j-i+1>n){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2) return true;
            j++;
        }
        return false;
    }
};