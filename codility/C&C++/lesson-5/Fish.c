/*
 * Fish
 *      N voracious fish are moving along a river. Calculate how many fish are alive.
 */

int solution(int A[], int B[], int N)
{
    int cnt = 0, i, top;
    int *stack = (int *)malloc(sizeof(int)*N);
    memset(stack, 0, N);

    for (top = 0, i = 0; i < N; i++) {
        if (B[i] == 1) {
            stack[top++] = A[i];    // downstream fishes
        } else {
            while (top > 0 && stack[top-1] < A[i]) {
                top--;
            }
            if (top == 0) {
                cnt ++; // this fish is bigger then all the lived downstream fishes
            }
        }
    }

    return cnt + top;
}
