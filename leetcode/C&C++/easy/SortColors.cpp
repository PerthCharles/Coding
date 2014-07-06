/*
 * Sort Colors
 *      Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 *
 *      Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 */


class Solution_1 {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0};
        int index = 0;
        int i, j;
        
        for (i = 0; i < n; i++) {
            count[A[i]]++;
        }
        
        for (i = 0; i < 3; i++) {
            for (j = 0; j < count[i]; j++) {
                A[index++] = i;
            }
        }
    }
};


class Solution_2 {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n - 1;
        int i, tmp;
        
        for (i = 0; i < blue + 1;) {
            if (A[i] == 0) {
                A[i++] = A[red];
                A[red++] = 0;
            } else if (A[i] == 2) {
                A[i] = A[blue];
                A[blue--] = 2;
            } else {
                i++;
            }
        }
    }
};