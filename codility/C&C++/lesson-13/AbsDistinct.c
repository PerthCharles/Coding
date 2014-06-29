/*
 * AbsDistinct
 *      Compute number of distinct absolute values of sorted array elements.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
int abs(int a)
{
    return a >= 0 ? a : -a;
}

int solution(int A[], int N) {
    // write your code in C90
    int result = 0;
    int neg = -1, pos = N, begin = 0;
    int i;
    for (i = 0; i < N; i++) {
        if (A[i] == (1<< (sizeof(int)*8 - 1))) {
            begin++;
        } else if (A[i] < 0) {
            neg = i;
        } else if (A[i] > 0) {
            pos = i;
            break;
        }
    }
    if (begin != 0) result++;  // A[0] = MIN_NEGTIVE_INT
    if (neg != pos - 1) result++;   // A[x] == 0
    
    while (neg >= begin && pos < N) {
        if (abs(A[neg]) == A[pos]) {
            result++;
            neg--;
            while (neg >= begin && A[neg] == A[neg+1]) neg--;
            pos++;
            while (pos < N && A[pos] == A[pos-1]) pos++;
        } else if (abs(A[neg]) < A[pos]) {
            result++;
            neg--;
            while (neg >= begin && A[neg] == A[neg+1]) neg--;
        } else {
            result++;
            pos++;
            while (pos < N && A[pos] == A[pos-1]) pos++;
        }
    }
    
    while (neg >= begin) {
        if (A[neg] != A[neg+1]) {
            result++;
        }
        neg--;
    }
    while (pos < N) {
        if (A[pos] != A[pos-1]) {
            result++;
        }
        pos++;
    }
    
    return result;
}