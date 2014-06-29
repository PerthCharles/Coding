/*
 * ChocolatesByNumbers
 *      There are N chocolates in a circle. Count the number of chocolates you will eat.
 */

int solution(int N, int M)
{
    in gcd = 1, result = 0, a = N, b = M;

    while (a != b) {
        if (a % 2 == 0 && b % 2 == 0) {
            gcd *= 2;
            a /= 2;
            b /= 2;
        } else if (a % 2 == 0) {
            a /= 2;
        } else if (b % 2 == 0) {
            b /= 2;
        } else if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    gcd *= a;
    result = N/gcd;

    return result;
}
