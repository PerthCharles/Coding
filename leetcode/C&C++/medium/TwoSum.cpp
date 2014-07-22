/*
 *  Two sum
 *      Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *      The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 *      You may assume that each input would have exactly one solution.
 *
 *      Input: numbers={2, 7, 11, 15}, target=9
 *      Output: index1=1, index2=2
 */

// Method one: 
//      1. sort with index
//      2. scan from both begin and end


class Solution_1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
         int i = 0, j = numbers.size() - 1;
         vector<int> result(2, 1);
         vector<pair<int, int> > NumsWithIndex;
         for (int k = 0; k < numbers.size(); k++) {
         NumsWithIndex.push_back(pair<int, int> (numbers[k], k));
         }
         sort(NumsWithIndex.begin(), NumsWithIndex.end());
         
         
         while (i < j) {
         int sum = NumsWithIndex[i].first + NumsWithIndex[j].first;
         if (sum == target) break;
         if (sum > target) {
         j--;
         } else {
         i++;
         }
         }
         
         result[0] += NumsWithIndex[i].second;
         result[1] += NumsWithIndex[j].second;
         sort(result.begin(), result.end());
         return result;
    }
};

// Method two: hash
class Solution_2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mapper;
        vector<int> result;
        
        for (int i = 0; i < numbers.size(); i++) {
            mapper[numbers[i]] = i;
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            int gap = target - numbers[i];
            if (mapper.find(gap) != mapper.end()) {
                if (mapper[gap] == i) continue;
                result.push_back(i+1);
                result.push_back(mapper[gap]+1);
                break;
            }
        }
        
        return result;
    }
};