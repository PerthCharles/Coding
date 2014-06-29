/*
 * MaxProductOfThree
 *      Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
 */

// There is a O(n) method, but the code can be really messy:
//      1. find three smallest negtive numbers: n1 <= n2 <= n3 < 0
//      2. find three biggest postive numbers: p1 >= p2 >= p3 > 0
//      3. result = MAX(p1*p2*p3, p1*n1*n2)
//      4. some other extremely cases needs to be discussed.

// Method: sort then get the result
#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

int compare(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

int solution(int A[], int N) 
{
    // write your code in C90
    qsort(A, N, sizeof(int), compare);
    
    return MAX(A[0]*A[1]*A[N-1], A[N-3]*A[N-2]*A[N-1]);
}
