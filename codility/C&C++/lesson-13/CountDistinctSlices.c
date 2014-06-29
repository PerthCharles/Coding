/*
 * CountDistinctSlices
 *      Count the number of distinct slices (containing only unique numbers).
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int M, int A[], int N) {
    // write your code in C90
    int *hash = (int *)malloc(sizeof(int)*(M+1));
    memset(hash, 0, sizeof(int)*(M+1));
    int head, tail, result = 0;
    int unique = 1;  // default unique is True
    
    for (head = 0, tail = 0; tail < N; tail++) {
        hash[A[tail]]++;
        if (hash[A[tail]] != 1) {
            unique = 0;
            while (head <= tail && (!unique)) {
                if (A[head] == A[tail]) {
                    unique = 1;
                }
                hash[A[head]]--; // clear hash
                head++;
            }
        }
        result += tail - head + 1;
        if (result > 1000000000) return 1000000000;
    }
    
    return result;
}