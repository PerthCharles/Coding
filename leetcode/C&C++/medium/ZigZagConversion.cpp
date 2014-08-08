/*
 *  ZigZag Conversion
 *      The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 *      P   A   H   N
 *      A P L S I I G
 *      Y   I   R
 *      And then read line by line: "PAHNAPLSIIGYIR"
 *      Write the code that will take a string and make this conversion given a number of rows:
 *
 *      string convert(string text, int nRows);
 *      convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */


class Solution {
public:
    string convert(string s, int nRows) {
        string result;
        int tmp;
        if (nRows <= 1) return s;   // why is this needed ?  becaused you will use (nRows - 1)
        
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.size(); j += 2*(nRows - 1)) {
                if (i == 0 || i == nRows - 1) {    // for the first and last row
                    result.append(1, s[j]);
                } else {
                    result.append(1, s[j]);
                    tmp = j + 2*(nRows - i - 1);   // the letter in the diagonal
                    if (tmp < s.size()) {
                        result.append(1, s[tmp]);
                    }
                }
            }
        }
        return result;
    }
};