/*
 * MaxDoubleSliceSum
 *      Find the maximal sum of any double slice.
 */

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

int solution(int A[], int N)
{
    int *L, *R;
    int i, max = 0;

    if (N <= 3) return 0;

    L = (int *)malloc(sizeof(int)*N);
    R = (int *)malloc(sizeof(int)*N);
    memset(L, 0, sizeof(int)*N);
    memset(R, 0, sizeof(int)*N);

    for (i = 1; i < N-1; i++) {
        L[i] = MAX(L[i-1] + A[i], 0);
    }
    for (i = N-2; i > 0; i--) {
        R[i] = MAX(R[i+1] + A[i], 0);
    }

    for (i = 1; i < N-1; i++) {
        max = MAX(max, L[i-1] + R[i+1]);
    }

    return max;
}
