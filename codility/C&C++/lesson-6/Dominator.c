/*
 * Dominator
 *      Find an index of an array such that its value occurs at more than half of indices in the array.
 */

// This is a very classic problem disscussed here:
//      http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
int solution(int A[], int N)
{
    int dominator, index;
    int cnt = 0, i;
    
    for (i = 0; i < N; i++) {
        if (cnt == 0) {
            dominator = A[i];
            index = i;
            cnt = 1;
        } else if (A[i] == dominator) {
            cnt++;
        } else {
            cnt--;
        }
    }

    if (cnt > 0) {
        // double check dominator
        cnt = 0;;
        for (i = 0; i < N; i++) {
            if (A[i] == dominator) cnt++;
        }
        if (cnt > N/2) return index;
        else return -1;
    } else {
        return -1;
    }
}
