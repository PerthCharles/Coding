/*
 * GenomicRangeQuery
 *      Find the minimal nucleotide from a range of sequence DNA.
 */
#include <stdlib.h>
#include <string.h>

struct Results solution(char *S, int P[], int Q[], int M)
{
    struct Results result;
    result.A = (int *)malloc(sizeof(int)*M);
    result.M = M;

    int i, j, N, from, to;
    int **counter;  
    N = strlen(S);

    // initial counter
    counter = (int **)malloc(sizeof(int *)*4);
    for (i = 0; i < 4; i++) {
        counter[i] = (int *)malloc(sizeof(int)*(N+1));
        memset(counter[i], 0, sizeof(int)*(N+1));
    }

    // 1. record the appearance of nucleotides respectively
    // 2. the index of counter starts from 1!
    for (i = 0; i < N; i++) {
        if (S[i] == 'A') counter[0][i+1]++; // note.2
        else if (S[i] == 'C') counter[1][i+1]++;
        else if (S[i] == 'G') counter[2][i+1]++;
        else if (S[i] == 'T') counter[3][i+1]++;
        else return -1;
    }
    // 3. get the appearance from [1, k] for queries
    for (i = 0; i < 4; i++) {
        for (j = 2; j <= N; j++) {
            counter[j][i] += counter[j][i-1];
        }
    }

    // 4. get the final result
    // 5. The index of P&Q starts from 0, 
    //    so [P, Q] "==" (from, to] in counter.
    for (i = 0; i < M; i++) {
        from = P[i];    // note.5
        to   = Q[i] + 1;

        if (counter[0][to] - counter[0][from] > 0) {
            result.A[i] = 1;
        } else if (counter[1][to] - counter[1][from] > 0) {
            result.A[i] = 2;
        }
        } else if (counter[2][to] - counter[2][from] > 0) {
            result.A[i] = 3;
        }
        } else if (counter[3][to] - counter[3][from] > 0) {
            result.A[i] = 4;
        } else {
            return -1;
        }
    }

    return result;
}
