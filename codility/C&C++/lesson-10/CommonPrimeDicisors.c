/*
 * CommonPrimeDivisors
 *      Check whether two numbers have the same prime divisors.
 */


int gcd(int a, int b)
{
    int gcd = 1;
    while (a != b) {
        if (a % 2 == 0 && b % 2 == 0) {
            a /= 2;
            b /= 2;
            gcd *= 2;
        } else if (a % 2 == 0) {
            a /= 2;
        } else if (b % 2 == 0) {
            b /= 2;
        } else if (a > b) {
            a = a-b;
        } else {
            b = b-a;
        }
    }
    gcd *= a;
    
    return gcd;
}

int solution(int A[], int B[], int Z) {
    // write your code in C90
    int result = 0;
    int a, b, gcd_ab, gcd_a, gcd_b, i;
    
    for (i = 0; i < Z; i++) {
        gcd_ab = gcd(A[i], B[i]);
        a = A[i];
        b = B[i];
        
        while (a != 1) {
            gcd_a = gcd(a, gcd_ab);
            if (gcd_a == 1) break;
            a /= gcd_a;
        }
        if (a != 1) continue;
        
        while (b != 1) {
            gcd_b = gcd(b, gcd_ab);
            if (gcd_b == 1) break;
            b /= gcd_b;
        }
        if (b != 1) continue;
        
        result++;
    }
    
    return result;
}
