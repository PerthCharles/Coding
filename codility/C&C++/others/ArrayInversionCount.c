/*
 * ArrayInversionCount
 *      Compute number of inversion in an array.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C90
    int result = 0;
    
    // Merge-and-Sort
    int from, to, mid, steps;
    int i = 0, j = 0, k = 0;
    int *tmp;
    tmp = (int *)malloc(sizeof(int)*N);
    
    for (steps = 1; steps <= N; steps += steps) {
        for (from = 0; from < N; from += steps + steps) {
            mid = from + steps;
            to = mid + steps;
            if (mid >= N) break;
            if (to >= N) to = N;
            
            for (i = k = from, j = mid; k < to; k++) {
                if (i == mid) {
                    tmp[k] = A[j++];
                } else if (j == to) {
                    tmp[k] = A[i++];
                } else if (A[i] <= A[j]) {
                    tmp[k] = A[i++];
                } else {
                    tmp[k] = A[j++];
                    result += mid - i;
                }
            }
        }
        // Swap tmp and A
        for (i = 0; i < k; i++) {  // tmp is only used up to 'k'
            A[i] = tmp[i];
        }
    }
    
    return result;
}