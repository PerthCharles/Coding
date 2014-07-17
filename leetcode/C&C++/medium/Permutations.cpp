/*
 * Permutations
 *      Given a collection of numbers, return all possible permutations.
 *
 *      For example,
 *      [1,2,3] have the following permutations:
 *      [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0) return result;
        sort(num.begin(), num.end());
        
        result.push_back(num);
        while(next_permute(num) != -1) {
            result.push_back(num);
        }
        
        return result;
    }
    
private:
    // Read NextPermutation.cpp, please !
    int next_permute(vector<int> &num) {
        int changefrom = -1, changeto;
        int i, j, tmp, len = num.size();
        for (i = len-2; i >= 0; i--) {
            if (num[i] < num[i+1]) {
                changefrom = i;
                break;
            }
        }
        
        if (changefrom == -1) return -1;
        
        for (i = len-1; i >= 0; i--) {
            if (num[i] > num[changefrom]) {
                changeto = i;
                break;
            }
        }
        
        tmp = num[changefrom];
        num[changefrom] = num[changeto];
        num[changeto] = tmp;
        
        i = changefrom + 1;
        j = len - 1;
        while(i < j) {
            tmp = num[i];
            num[i++] = num[j];
            num[j--] = tmp;
        }
        
        return 0;
    }
};