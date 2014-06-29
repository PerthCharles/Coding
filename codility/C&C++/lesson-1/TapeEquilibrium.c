/*
 * TapeEquilibrium
 *      Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.  
 */

#define ABS(a) (((a) >= 0) ? (a) : (-(a)))
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))

int solution(int A[], int N)
{
   // write your code in C90
    int diff, min_diff = 0;
    int split, sum = 0, l_sum = 0, r_sum, i;

    // get the sum of A[]
    for (i = 0; i < N; i++) {
        sum += A[i];
    }

    // find min_diff fot these two pieces:
    // [0, split] and [split+1, N)
    for (split = 0; split < N-1; split++) {
        l_sum += A[split];   // left sum
        r_sum = sum - l_sum;
        diff = ABS(r_sum - l_sum);

        if (split == 0) {
            min_diff = diff;
        } else {
            min_diff = MIN(min_diff, diff);
        }
    }

    return min_diff;
}
