/*
 * PermMissingElem
 *      Find the missing element in a given permutation.
 */

int solution(int A[], int N)
{
    // write your code in C90
    // Look out for overflow of 'int'
    int miss = 0, i;

    for (i = 0; i < N; i++) {
        miss += (i+1) - A[i];
    }
    miss += N + 1;

    return miss;
}
