/*
 * Flags
 *      Find the maximum number of flags that can be set on mountain peaks.
 */

int solution(int A[], int N)
{
    int i, result, pos, sum;
    int *next = (int *)malloc(sizeof(int)*N);
    memset(next, 0, sizeof(int)*N);

    if (N < 3) return 0;

    // initial next peaks
    next[N-1] = -1; // -1 means no peak after this point
    for (i = N-2; i > 0; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            next[i] = i;
        } else {
            next[i] = next[i+1];
        }
    }
    next[0] = next[1];

    i = 1;
    result = 0;
    while ( N/(i-1) >= (i-1) ) {
        pos = 1;
        sum = 0;
        while (pos < N && sum < i) {
                pos = next[pos];
                if (pos == -1) break;
                sum += 1;   // number of flags for step == i
                pos += i;
        }
        result = sum >= result ? sum : result;
        i++;
    }

    return result;
}
