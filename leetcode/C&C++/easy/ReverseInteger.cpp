/*
 * Reverse Integer
 *      Reverse digits of an integer
 */


class Solution {
public:
    int reverse(int x) {
        int abs_x, flag, result = 0;
        int of_check;  // overflow check

        if (x >= 0) {
            abs_x = x;
            flag = 0;
        } else {
            abs_x = -x;
            flag = 1;
        }
        
        while(abs_x > 0) {
            of_check = result * 10;
            if (of_check < 0) return -1;
            
            result = of_check + abs_x%10;
            abs_x = abs_x/10;
        }
        
        if (flag == 1) {
            of_check = -result;
            if (of_check >= 0) return -1;
            
            result = of_check;
        }
        
        return result;
    }
};
