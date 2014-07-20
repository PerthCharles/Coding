/*
 *  Add Binary
 *      Given two binary strings, return their sum (also a binary string).
 *
 *      For example,
 *      a = "11"
 *      b = "1"
 *      Return "100".
 */


class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int la = a.size();
        int lb = b.size();
        const int N = la > lb ? la : lb;
        // reverse two adder
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0, sum, ai, bi;
        for (int i = 0; i < N; i++) {
            ai = i < la ? a[i] - '0' : 0;
            bi = i < lb ? b[i] - '0' : 0;
            sum = (carry + ai + bi)%2;
            carry = (carry + ai + bi)/2;
            result.insert(result.begin(), sum + '0');
        }
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }
        
        return result;
    }
};