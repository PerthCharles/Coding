/*
 *  Multiply Strings
 *      Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 *      Note: The numbers can be arbitrarily large and are non-negative.
 */

// TODO: learn overlapp of operator in C++

typedef vector<int> bigint;

class Solution {
public:
    string multiply(string num1, string num2) {
        bigint x, y, z;
        string result;
        
        to_bigint(num1, x);
        to_bigint(num2, y);
        
        multiply(x, y, z);
        to_string(z, result);
        if (result.size() == 0) result += '0';  // result is zero
        return result;
    }
    
private:
    void to_bigint(string &s, bigint &n) {
        for (int i = s.size()-1; i >= 0; i--) {
            n.push_back(s[i] - '0');
        }
    }
    
    void to_string(bigint &n, string &s) {
        bool start = false;
        for (int i = n.size()-1; i >= 0; i--) {
            if (!start && n[i] != 0) start = true;;
            if (start) s += (char)(n[i] + '0');
        }
    }
    
    void multiply(bigint &x, bigint &y, bigint &z) {
        z.resize(x.size() + y.size(), 0);
        
        for (int i = 0; i < x.size(); i++) {
            for (int j = 0; j < y.size(); j++) {
                z[i+j] += x[i] * y[j];
                z[i+j+1] += z[i+j]/10;
                z[i+j] = z[i+j]%10;
            }
        }
    }
};
