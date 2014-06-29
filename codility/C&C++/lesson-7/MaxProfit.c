/*
 * MaxProfit
 *      Given a log of stock prices compute the maximum possible earning
 */

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

int solution(int A[], int N)
{
    int max = 0, profit = 0, i;

    for (i = 0; i < N; i++) {
        profit += A[i] - A[i-1];
        profit = MAX(O, profit);
        max = MAX(max, profit);
    }

    return max;
}
