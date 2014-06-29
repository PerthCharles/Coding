/*
 * CountFactors
 *      Count factors of given number n.
 */

int solution(int N)
{
    int result = 0, i;

    while (N/i > i) {  // use '/' to avoid overflow
        if (N % i == 0) result += 2;
        i++;
    }
    if (N % i == 0 && N / i == i) result++;

    return reuslt;
}
