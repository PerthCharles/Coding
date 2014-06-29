/*
 * Ladder
 *      Count the number of different ways of climbing to the top of a ladder.
 */


struct Results solution(int A[], int B[], int L) {
    struct Results result;
    int i;
    int *fibo;
    // write your code in C90
    result.C = (int *)malloc(sizeof(int)*L);
    memset(result.C, 0, sizeof(int)*L);
    
    if (L == 1) {
        result.C[0] = 1;
        result.L = 1;
        return result;
    }
    
    fibo = (int *)malloc(sizeof(int)*(L+1));
    memset(fibo, 0, sizeof(int)*(L+1));
    fibo[1] = 1;
    fibo[2] = 2;
    for (i = 3; i < L+1; i++) {
        // what if INT is not bigger enough for a fibonacci number?
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    for (i = 0; i < L; i++) {
        result.C[i] = fibo[A[i]] & ((1 << B[i]) - 1);
    }
    
    
    result.L = L;
    return result;
}
