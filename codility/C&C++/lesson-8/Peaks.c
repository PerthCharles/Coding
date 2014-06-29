/*
 * Peaks
 *      Divide an array into the maximum number of same((-))sized blocks, each of which should contain an index P such that A[P - 1] < A[P] > A[P + 1].
 */

int solution(int A[], int N)
{
    int i, step, flag, result = 0;
    int *peak = (int *)malloc(sizeof(int)*N);
    memset(peak, 0, sizeof(int)*N);

    if (N < 3) return 0;

    for (i = 1; i < N-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peak[i] = peak[i-1] + 1;
        } else {
            peak[i] = peak[i-1];
        }
    } 
    peak[N-1] = peak[N-2];

    step = 2;
    while(step <= N) {
        if (N%step == 0) {
            flag = 1;  // when step is an candidate, flag == 1
            for (i = step - 1; i < N; i += step) {
                // No peak in the first slice *OR* no peak in the rest slices
                if ((i == step - 1 && peak[i] <= 0)
                    || (i > step - 1 && peak[i] - peak[i-step] <= 0)) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                result = N/step;
                break;
            }
        }
    }

    return result;
}
