/*
 * Climbing Stairs
 *      You are climbing a stair case. It takes n steps to reach to the top.
 *
 *      Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */


class Solution {
public:
    int climbStairs(int n) {
        // method one: recursive which can cause timeout
        /*
         if (n == 0) return 0;
         else if (n == 1) return 1;
         else if (n == 2) return 2;
         else return climbStairs(n-1) + climbStairs(n-2);
         */
        
        // method two: Fibonacci numbers
        int a = 0, b = 1;
        int i, result = 0;;
        
        for (i = 0; i < n; i++) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};