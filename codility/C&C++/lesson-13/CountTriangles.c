/*
 * CountTriangles
 *      Count the number of triangles that can be built from a given set of edges.
 */


void merge_sort(int A[], int N)
{
    int *tmp, steps, mid, from, to, i, j, k;
    tmp = (int *)malloc(sizeof(int)*N);
    memset(tmp, 0, sizeof(int)*N);
    
    for (steps = 1; steps <= N; steps += steps) {
        for (from = 0; from < N; from += steps + steps) {
            mid = from + steps;
            if (mid > N) break;;
            to = from + steps + steps;
            if (to > N) to = N;
            
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
}

int solution(int A[], int N) {
    if (N < 3) return 0;
    // write your code in C90
    int result = 0, i, j, k;
    //qsort(A, N, sizeof(int), compare);   // qsort can cause timeout :(
    merge_sort(A, N);
    
    for (i = 0; i < N-2; i++) {
        for (j = i+1; j < N-1; j++) {
            k = j+1;  // Lookout that this statement cannot be in the second loop
            while (k < N && A[i] + A[j] > A[k]) {
                k++;
            }
            result += (k-1) - j;
        }
    }
    
    return result;
}
