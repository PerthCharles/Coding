/*
 * MaxSliceSum
 *      Find a maximum sum of a compact subsequence of array elements.
 */

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

int solution(int A[], int N)
{
    int sum = 0, max = 0, i;

    if (N == 0) return 0;
    max = A[0];
    
    for (i = 0; i < N; i++) {
        sum += A[i];
        sum = MAX(0, sum);
        max = MAX(max, sum);
    }

    return max;
}
