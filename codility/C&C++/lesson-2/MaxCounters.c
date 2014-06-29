/*
 * MaxCounters
 *      Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
 */

struct Results solution(int N, int A[], int M)
{
    // write your code in C90
    struct Results result;
    int i, counter, base = 0, max = 0;
    result.C = (int *)malloc(sizeof(int)*N);
    memset(result.C, 0, sizeof(int)*N);
    result.L = N;

    for (i = 0; i < M; i++) {
        if (A[i] > N) {
            base = max;
        } else {
            counter = A[i] - 1;
            if (result.C[counter] >= base) {
                result.C[counter]++;
            } else {
                result.C[counter] = base + 1;
            }
            // reset max
            if (result.C[counter] > max) {
                max = result.C[counter];
            }
        }
    }

    // build the last result
    for (i = 0; i < N; i++) {
        if (result.C[i] < base) {
            result.C[i] = base;
        }
    }

    return result;
}
