/*
 * CountDiv
 *      Compute number of integers divisible by k in range [a..b]
 */

int solution(int A, int B, int K)
{
    if (A%K == 0) {
        return (B - A)/K + 1;
    } else {
        return (B - (A - A%K))/K;
    }
}
