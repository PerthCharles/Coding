/*
 * MinAvgTwoSlice
 *      Find the minimal average of any slice containing at least two elements.
 */

int solution(int A[], int N)
{
    int i, start = 0;
    float mean, min;

    min = (A[0], A[i])/2.0;

    /* The len of MinAvgTwoSlice can only be 2 or 3.
     * The proven can be found in here: 
     *      http://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/
     */

    // For slices which len == 2
    for (i = 0; i < N - 1; i++) {
        mean = (A[i] + A[i+1])/2.0;
        if (mean < min) {
            min = mean;
            start = index;
        }
    }

    // For slices which len == 3
    for (i = 0; i < N - 2; i++) {
        mean = (A[i] + A[i+1] + A[i+2])/3.0;
        if (mean < min) {
            min = mean;
            start = index;
        }
    }

    return start;
}
