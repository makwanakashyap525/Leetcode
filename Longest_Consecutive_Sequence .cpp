 #include <iostream>
    #include <vector>
    #include <unordered_set> 
    #include <algorithm>     
    using namespace std;
    
    class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> numSet(nums.begin(), nums.end());
    
            int longStreak = 0;
    
            for (int num : numSet) {
                if (!numSet.count(num - 1)) {
                    int currNum = num;
                    int currStreak = 1;
    
                    while (numSet.count(currNum + 1)) {
                        currNum++;
                        currStreak++;
                    }
    
                    longStreak = max(longStreak, currStreak);
                }
            }
    
            return longStreak;
        }
    };
    