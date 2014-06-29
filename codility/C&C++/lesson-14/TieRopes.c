/*
 * TieRopes
 *      Tie adjacent ropes to achieve the maximum number of ropes of length >= K.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int K, int A[], int N) {
    // write your code in C90
    int result = 0;
    int i, tmp;
    
    tmp = 0;
    for (i = 0; i < N; i++) {
        tmp += A[i];
        if (tmp >= K) {
            result++;
            tmp = 0;
        }
    }
    
    return result;
}