/*
 * MissingInteger
 *      Find the minimal positive integer not occurring in a given sequence.
 */

int solution(int A[], int N)
{
    // write your code in C90
    int *hash = (int *)malloc(sizeof(int)*(N+1));
    memset(hash, 0, sizeof(int)*(N+1));

    int result = 1, i;

    for (i = 0; i < N; i++) {
        if (A[i] > 0 && A[i] <= N) {
            hash[A[i]] = 1;
        }
    }

    for (result = 1; result <= N; result++) {
        if (hash[result] == 0) {
            return result;
        }
    }

    return result;
}
