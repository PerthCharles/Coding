/*
 *  Divide Two Integers
 *      Divide two integers without using multiplication, division and mod operator.
 */

// Note: 1. try to double divisor to accelerate the algorithm
// Be careful with overflow

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool sign(false);  // sign == false represent positive
        if ((dividend > 0) ^ (divisor > 0)) sign = true;
        
        unsigned int undividend = abs((long long)dividend);
        unsigned int undivisor  = abs((long long)divisor);
        
        while (undividend >= undivisor) {
            unsigned int new_undivisor = undivisor;
            int multi = 1;
            while (undividend >= new_undivisor) {
                undividend -= new_undivisor;
                result += multi;
                
                if (new_undivisor < INT_MAX >> 1) {
                    multi <<= 1;
                    new_undivisor <<= 1;
                }
            }
        }
        
        return sign ? (0 - result) : result;
    }
};