/*
 * PermCheck
 *      Check whether array A is a permutation
 */

int solution(int A[], int N)
{
    int i;
    int *hash = (int *)malloc(sizeof(int)*(N+1));
    memset(hash, 0, sizeof(int)*(N+1));

    for (i = 0; i < N; i++) {
        if (A[i] > N || hash[A[i]] != 0) {
            return 0;
        }
        hash[A[i]]++;
    }

    return 1;
}
