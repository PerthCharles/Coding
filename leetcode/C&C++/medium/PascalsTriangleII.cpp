/*
 *  Pascal's Triangle II 
 *      Given an index k, return the kth row of the Pascal's triangle.
 *
 *      For example, given k = 3,
 *      Return [1,3,3,1].
 *
 *      Note:
 *      Could you optimize your algorithm to use only O(k) extra space?
 */

// Note: 
//      1. it is C(k,i) for the ith item
//      2. lookout overflow

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i, item = 1, a, b, c, d;
        vector<int> result;
        for (i = 0; i <= rowIndex; i++) {
            result.push_back(item);
            a = (rowIndex-i)/(i+1);
            b = (rowIndex-i)%(i+1);
            c = item/(i+1);
            d = item%(i+1);
            item = a * item + b * c + (b * d)/(i+1);
            if (item == 0) item = 1;
        }
        
        return result;
    }
};
