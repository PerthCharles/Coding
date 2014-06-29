/*
 * EquiLeader
 *      Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
 */

int solution(int A[], int N)
{
    int cnt = 0, lcnt, rcnt, i, candidate;
    int result = 0;

    // find candidate
    for (i = 0; i < N; i++) {
        if (cnt == 0) {
            candidate = A[i];
            cnt = 1;
        } else if (A[i] == candidate) {
            cnt++;
        } else {
            cnt--;
        }
    }
    // double check candidate
    if (cnt > 0) {
        cnt = 0;
        for (i = 0; i < N; i++) {
            if (A[i] == candidate) cnt++;
        }
        if (cnt <= N/2) return 0;
    } else {
        return 0;
    }

    lcnt = rcnt = 0;
    for (i = 0; i < N; i++) {
        if (A[i] == candidate) lcnt++;
        rcnt = cnt - lcnt;
        if (lcnt > (i+1)/2 && rcnt > (N-i-1)/2) {
            result++;        
        }
    }

    return result;
}
