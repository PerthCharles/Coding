/* 
 * Next Permutation
 *      Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 *      If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 *      The replacement must be in-place, do not allocate extra memory.
 *
 *      Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *      1,2,3 → 1,3,2
 *      3,2,1 → 1,2,3
 *      1,1,5 → 1,5,1
 */


// Reference: http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int changefrom = -1; // the most left number need to be changed
        int changeto;        // the most left number: num[changefrom] <-> num[changeto]
        int len = num.size();
        int i, tmp;
        
        // find changefrom
        for (i = len - 2; i >= 0; i--) {
            if (num[i] < num[i+1]) {
                changefrom = i;
                break;
            }
        }
        
        if (changefrom == -1) {
            swap(num, 0, len-1);
            return;
        }
        
        // find changeto
        for (i = len - 1; i >= 0; i--) {
            if (num[i] > num[changefrom]) {
                changeto = i;
                break;
            }
        }
        
        tmp = num[changefrom];
        num[changefrom] = num[changeto];
        num[changeto] = tmp;
        // swap the right part
        swap(num, changefrom + 1, len-1);
        return;
    }
    
    // swap the right part of the num: [begin, end]
    void swap(vector<int> &num, int begin, int end) {
        int i = begin, j = end, tmp;
        while (i < j) {
            tmp = num[i];
            num[i++] = num[j];
            num[j--] = tmp;
        }
    }
};
