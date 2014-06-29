/*
 * FrogRiverOne
 *      Find the earliest time when a frog can jump to the other side of a river.
 */

int solution(int X, int A[], int N)
{
    // write your code in C90
    int *hash = (int *)malloc(sizeof(int)*(X+1));
    int time, leaves = 0;
    memset(hash, 0, sizeof(int)*(X+1));

    for (time = 0; time < N; time++) {
        if (hash[A[time]] == 0) {
            hash[A[time]]++;
            leaves++;  // found a new leave
        }
        if (leaves == X) {
            return time;
        }
    }

    return -1;
}
