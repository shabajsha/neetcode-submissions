#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> numMap; // Stores {value: original_index}

                    for (int i = 0; i < nums.size(); i++) {
                                int complement = target - nums[i];
                                            
                                                        // If the complement exists in our map, we found the pair
                                                                    if (numMap.find(complement) != numMap.end()) {
                                                                                    return {numMap[complement], i};
                                                                                                }
                                                                                                            
                                                                                                                        // Otherwise, store current number and its original index
                                                                                                                                    numMap[nums[i]] = i;
                                                                                                                                            }
                                                                                                                                                    return {};
                                                                                                                                                        }
                                                                                                                                                        };
                                                                                                                                                        
