/*
 * MinAbsSumOfTwo
 *      Find the minimal absolute value of a sum of two elements.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define ABS(a) (((a) >= 0) ? (a) : (-(a)))

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int solution(int A[], int N) {
    // write your code in C90
    if (N < 2) return ABS(2*A[0]);
    
    int head, tail, min, tmp;
    qsort(A, N, sizeof(int), compare);
    if (A[0] >= 0) return ABS(2*A[0]);      // A[i] >= 0
    if (A[N-1] <=0) return ABS(2*A[N-1]);   // A[i] <= 0
    
    head = 0;
    tail = N - 1;
    min = ABS(A[head] + A[tail]);
    while (head <= tail) {
        tmp = A[head] + A[tail];
        min = MIN(min, ABS(tmp));
        if (tmp == 0) return 0;
        else if (tmp > 0) tail--;
        else head++;
    }
    
    return min;
}
