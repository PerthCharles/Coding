/*
 * CountSemiprimes
 *      Count the semiprime numbers in the given range [a..b]
 */


struct Results solution(int N, int P[], int Q[], int M) {
    struct Results result;
    result.A = (int *)malloc(sizeof(int)*M);
    memset(result.A, 0, sizeof(int)*M);

    int *divisors, *counter, i, k;
    divisors = (int *)malloc(sizeof(int)*(N+1));
    counter = (int *)malloc(sizeof(int)*(N+1));
    memset(divisors, 0, sizeof(int)*(N+1));
    memset(counter, 0, sizeof(int)*(N+1));
    
    i = 2;
    while (i*i <= N) {
        if (divisors[i] == 0) {
            k = i*i;
            while (k <= N) {
                if (divisors[k] == 0) divisors[k] = i;
                k += i;
            }
        }
        i++;
    }
    
    for (i = 1; i <= N; i++) {
        if (divisors[i] != 0 && divisors[i/divisors[i]] == 0)
            counter[i] = counter[i-1] + 1;
        else
            counter[i] = counter[i-1];
    }
    
    for (i = 0; i < M; i++) {
        result.A[i] = counter[Q[i]] - counter[P[i] - 1];
    }
    
    result.M = M;
    return result;
}
