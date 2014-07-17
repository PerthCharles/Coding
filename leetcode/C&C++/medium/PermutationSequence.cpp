/*
 * Permutation Sequence
 *      The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 *      By listing and labeling all of the permutations in order,
 *      We get the following sequence (ie, for n = 3):
 *
 *      "123"
 *      "132"
 *      "213"
 *      "231"
 *      "312"
 *      "321"
 *      Given n and k, return the kth permutation sequence.
 *
 *      Note: Given n will be between 1 and 9 inclusive.
 */


class Solution {
public:
    string getPermutation(int n, int k) {
        int map[10] = {0};
        int factor = 1;
        int i;
        string result;
        string list;
        for (i = 1; i <= n; i++) {
            list += (char)(i + '0');
        }
        
        for (i = 1; i < n; i++) {
            factor *= i;
        }
        k = k - 1;   // This is very trick!
        for (i = 0; i < n; i++) {
            result += list[find(k/factor, n)];
            k %= factor;
            if (i < n-1) factor /= (n-1) - i;
        }
        //result += '\0';
        return result;
    }
    
private:
    int map[10] = {0};
    int find(int cnt, int n) {
        int i;
        for (i = 0; i < n; i++) {
            if (cnt == 0 && map[i] == 0) {
                map[i] = 1;
                return i;
            }
            if (map[i] == 0) cnt--;
        }
    }
};