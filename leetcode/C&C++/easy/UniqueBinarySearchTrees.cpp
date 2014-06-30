/*
 * Unique Binary Search Trees
 *      Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 */


class Solution {
public:
    int numTrees(int n) {
        int i, cnt = 0;
        if (n == 0 || n == 1) return 1;
        for (i = 0; i < n; i++) {
            cnt += numTrees(i)*numTrees(n-i-1);
        }
        
        return cnt;
    }
};