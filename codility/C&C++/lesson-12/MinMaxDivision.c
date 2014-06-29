/*
 * MinMaxDivision
 *      Divide array A into K blocks and minimize the largest sum of any block.
 */


int compute_mgn(int A[], int N, int ems)
{
    int cursum = 0;
    int mgn = 0;
    int i;
    
    for (i = 0; i < N; i++) {
        cursum += A[i];
        if (cursum > ems) {
            mgn++;
            cursum = A[i];
        }
    }
    if (cursum > 0) mgn++;
    
    return mgn;
}


int solution(int K, int M, int A[], int N) {
    // write your code in C90
    int ems;  // expected minimum sum
    int mgn;  // minimum group number
    int big = 0;  // biggest in A[]
    int sum = 0;  // sum of A[]
    int i, beg, end;
    
    for (i = 0; i < N; i++) {
        sum += A[i];
        if (i == 0) big = A[i];
        else if (A[i] > big) big = A[i];
    }
    
    beg = big;
    end = sum;
    while (beg <= end) {
        ems = (beg + end)/2;
        mgn = compute_mgn(A, N, ems);
        if (mgn <= K) {
            end = ems - 1;
        } else {
            beg = ems + 1;
        }
    }
    
    return beg;
}
