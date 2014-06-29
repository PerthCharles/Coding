/*
 * FibFrog
 *      Count the minimum number of jumps required for a frog to get to the other side of a river.
 */


int min(int a, int b)
{
    if (a >= b) return b;
    else return a;
}

int solution(int A[], int N) {
    // write your code in C90
    if (N <= 2) return 1;
    
    int i, j, k, result = -1;
    int *fibo, *cnt;
    fibo = (int *)malloc(sizeof(int)*50);
    cnt = (int *)malloc(sizeof(int)*N);
    memset(fibo, 0, sizeof(int)*50);
    memset(cnt, 0, sizeof(int)*N);
    fibo[1] = 1;
    
    i = 1;
    while(fibo[i++] <= N) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    for (i = N-1; i >= 0; i--) {
        if (A[i] == 1) {
            k = 2;
            j = i + fibo[k++];
            while(j < N) {
                if (A[j] == 1 && cnt[j] != 0) {
                    if (cnt[i] == 0) cnt[i] = cnt[j] + 1;
                    else cnt[i] = min(cnt[i], cnt[j] + 1);
                }
                j = i + fibo[k++];
            }
            if (j == N) cnt[i] = 1;
        }
    }
    
    k = 2;
    j = -1 + fibo[k++];
    while (j < N) {
        if (A[j] == 1 && cnt[j] != 0) {
            if (result == -1) result = cnt[j] + 1;
            else result = min(result, cnt[j] + 1);
        }
        j = -1 + fibo[k++];
    }
    if (j == N) result = 1;
    
    return result > 0 ? result : -1;
}
