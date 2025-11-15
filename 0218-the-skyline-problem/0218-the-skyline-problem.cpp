#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events; // (x, height), use negative height for start
        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]}); // start
            events.push_back({b[1], b[2]});  // end
        }
        
        sort(events.begin(), events.end()); // sort by x, then height
        
        multiset<int> heights;
        heights.insert(0); // initial ground level
        int prev = 0;
        vector<vector<int>> res;
        
        for (auto &[x, h] : events) {
            if (h < 0) {
                heights.insert(-h); // start of building
            } else {
                heights.erase(heights.find(h)); // end of building
            }
            
            int curr = *heights.rbegin();
            if (curr != prev) {
                res.push_back({x, curr});
                prev = curr;
            }
        }
        
        return res;
    }
};
