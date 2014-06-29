/*
 * Distinct
 *      Compute number of distinct values in an array.
 */

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

// Method one: use qsort()
// Note: qsort can cause timeout for some extreme cases
int solution_1(int A[], int N)
{
    int cnt = 0, i;
    qsort(A, N, sizeof(int), compare);

    for (i = 0; i < N; i++) {
        if (i == 0) cnt = 1;
        else if (A[i] != A[i-1]) cnt++;
    }

    return cnt;
}

// Method two: merge-and-sort
int solution_2(int A[], int N)
{
    int cnt = 0;
    int *tmp = (int *)malloc(sizeof(int)*N);
    memset(tmp, 0, sizeof(int)*N);
    int i, j, k, from, mid, to, steps;

    // non-recursive merget-and-sort: bottom up style
    for (steps = 1; steps <= N; steps += steps) {
        // select two sub-slice to merge which len == steps:
        //      [from, mid) + [mid, to) ==> [from, to)
        for (from = 0; from < N; from += steps + steps) {
            mid = from + steps;
            to  = mid + steps;

            // there is only one slice left, leave to the next round
            if (mid >= N) break;  
            if (to >= N) to = N;

            // merge
            for (i = k = from, j = mid; k < to; k++) {
                if (i == mid) tmp[k] = A[j++];
                else if (j == to) tmp[k] = A[i++];
                else if (A[i] <= A[j]) tmp[k] = A[i++];
                else tmp[k] = A[j++];
            }
        }

        // copy tmp back to A
        // Note: only *k* items is used in tmp!
        for (i = 0; i < k; i++) {
            A[i] = tmp[i];
        }
    }

    for (i = 0; i < N; i++) {
        if (i == 0) cnt = 1;
        else if (A[i] != A[i-1]) cnt++;
    }

    return cnt;
}
