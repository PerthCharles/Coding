/*
 * PassingCars
 *      Count the number of passing cars on the road
 */

int solution(int A[], int N)
{
    // write your code in C90
    int result = 0;
    int west_sum = 0, west_remain = 0;
    int i;

    for (i = 0; i < N; i++) {
        west_sum += A[i];
    }
    west_remain = west_sum;
    for (i = 0; i < N; i++) {
        if (A[i] == 0) {
            result += west_remain;
        } else {
            west_remain--;
        }
        
        if (result > 1000000000) {
            return -1;
        }
    }

    return result;
}
