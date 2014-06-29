/*
 * Triangle
 *      Determine whether a triangle can be built from a given set of edges.
 */

// qsort is too simple, try to practice merge-and-sort
int solution(int A[], int N)
{
    int from, to, mid, steps, i, j, k;
    int *tmp = (int *)malloc(sizeof(int)*N);
    memset(tmp, 0, sizeof(int)*N);

    for (steps = 1; steps <= N; steps += steps) {
        for (from = 0; from < N; from += steps + steps) {
            mid = from + steps;
            to  = mid + steps;
            if (mid >= N) break;
            if (to >= N) to = N;

            for (i = k = from, j = mid; k < to; k++) {
                if (i == mid) tmp[k] = A[j++];
                else if (j == to) tmp[k] = A[i++];
                else if (A[i] <= A[j]) tmp[k] = A[i++];
                else tmp[k] = A[j++];
            }
        }
        for (i = 0; i < k; i++) {
            A[i] = tmp[i];
        }
    }

    for (i = 0; i < N - 2; i++) {
        if (A[i] < 0) continue;
        // be careful with overflow, use sub instead of add
        if (A[i+2] - A[i+1] < A[i]) {
            return 1;
        }
    }

    return 0;
}

