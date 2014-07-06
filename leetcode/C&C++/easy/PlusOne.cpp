/*
 * Plus One
 *      Given a non-negative number represented as an array of digits, plus one to the number.
 *
 *      The digits are stored such that the most significant digit is at the head of the list.
 */


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int i, size, current;
        size = digits.size();
        
        for (i = size - 1; i >= 0; i--) {
            current = digits[i] + carry;
            carry = current/10;
            digits[i] = current%10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};