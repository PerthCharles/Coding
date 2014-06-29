/*
 * BinaryGap
 *      Find longest sequence of zeros in binary representation of an integer.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int N) {
    // write your code in C90
    int max, tmp, start;
    
    max = 0;
    start = 0;
    tmp = 0;
    while (N > 0) {
        if (N & 1) {
            if (start == 1) {
                if (tmp > max) max = tmp;
            }
            tmp = 0;
            start = 1;
        } else {
            tmp++;
        }
        N = (N >> 1);
    }
    
    return max;
}