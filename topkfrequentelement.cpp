#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); ++i) {
            freqMap[nums[i]]++;
        }

        // Step 2: Bucket sort - buckets[index] = list of numbers with that frequency
        int n = nums.size();
        vector<vector<int>> buckets(n + 1); // index = frequency

        for (unordered_map<int, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
            int num = it->first;
            int freq = it->second;
            buckets[freq].push_back(num);
        }

        // Step 3: Collect top k frequent elements from the buckets
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};

int main() {
    // Sample input
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Create Solution object
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);

    // Output the result
    cout << "Top " << k << " frequent elements are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
