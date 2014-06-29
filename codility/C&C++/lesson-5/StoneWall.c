/*
 * StoneWall
 *      Cover "Manhattan skyline" using the minimum number of rectangles.
 */

int solution(int H[], int N)
{
    int top, i, cnt = 0;
    int *stack = (int *)malloc(sizeof(int)*N);
    memset(stack, 0, sizeof(int)*N);

    for (top = 0, i = 0; i < N; i++) {
        while (top > 0 && H[i] < stack[top-1]) {
            top--;
            cnt++;
        }

        if (top == 0 || H[i] < stack[top-1]) {
            stack[top++] = H[i];
        }
    }

    return cnt + top;
}
