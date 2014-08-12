/*
 *  Median of Two Sorted Arrays
 *      There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 == 0) {
            return (findkth(A, m, B, n, total/2) + findkth(A, m, B, n, total/2+1)) / 2.0;
        } else {
            return findkth(A, m, B, n, total/2+1);
        }
    }
    
private:
    int findkth(int A[], int m, int B[], int n, int k) {
        if (m > n) return findkth(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);
        
        // divide k into two parts
        int mida = min(k/2, m);
        int midb = k - mida;
        if (A[mida - 1] < B[midb - 1]) {
            return findkth(A+mida, m-mida, B, n, k-mida);
        } else if (A[mida - 1] > B[midb - 1]) {
            return findkth(A, m, B+midb, n-midb, k-midb);
        } else {
            return A[mida - 1];
        }
    }
};