/*
 * MinPerimeterRectangle
 *      Find the minimal perimeter of any rectangle whose area equals N.
 */

int solution(int N)
{
    int biggest_factor = 1;
    int i = 1, j;

    while (i*i <= N) {
        if (N % i = 0) biggest_factor = i;
        i++;
    }
    j = N/biggest_factor;

    return 2*(j + biggest_factor);
}
