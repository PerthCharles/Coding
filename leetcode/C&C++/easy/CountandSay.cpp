/*
 *  Count and Say
 *      The count-and-say sequence is the sequence of integers beginning as follows:
 *      1, 11, 21, 1211, 111221, ...
 *
 *      1 is read off as "one 1" or 11.
 *      11 is read off as "two 1s" or 21.
 *      21 is read off as "one 2, then one 1" or 1211.
 *      Given an integer n, generate the nth sequence.
 *
 *      Note: The sequence of integers will be represented as a string.
 */


class Solution {
public:
    string countAndSay(int n) {
        string result, tmp;
        char *p;
        if (n <= 0) return result;
        
        
        int count;
        char say;
        int i, j, k, len;
        
        for (i = 0; i < n; i++) {
            len = result.length();
            if (len == 0) result += '1';
            else {
                count = 0;
                tmp = "";
                for (j = 0; j < len; j++) {
                    if (count == 0) {
                        count = 1;
                        say = result[j];
                    } else if (result[j] == result[j-1]) {
                        count++;
                    } else {  // find a new char
                        tmp += (char)(count + '0');
                        tmp += say;
                        
                        count = 1;
                        say = result[j];
                    }
                }
                tmp += (char)(count + '0');
                tmp += say;
                
                result = tmp;
            }
        }
        
        return result;
    }
};