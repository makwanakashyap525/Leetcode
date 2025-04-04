 #include <iostream>
#include <vector>
#include <map>       
#include <algorithm>  
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> container;  
        vector<int> ans;

        
        for (auto it = nums.begin(); it != nums.end(); it++) {
            container[*it]++;
        }

        
        for (int i = nums.size(); i >= 1; i--) {
            if (ans.size() == k) break;
            for (auto it = container.cbegin(); it != container.cend(); it++) {
                if (it->second == i) {
                    ans.push_back(it->first);
                    if (ans.size() == k) break;
                }
            }
        }

        return ans;
    }
};

