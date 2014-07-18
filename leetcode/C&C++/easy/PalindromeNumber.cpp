/*
 *  Palindrome Number
 *      Determine whether an integer is a palindrome. Do this without extra space.
 *
 *      click to show spoilers.
 *
 *      Some hints:
 *      Could negative integers be palindromes? (ie, -1)
 *
 *      If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 *      You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 *
 *      There is a more generic way of solving this problem.
 */


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int factor = 1, head ,tail ;
        while (x / factor >= 10) factor *= 10;
        
        while (x > 0) {  // spolier: 10000021
            head = x / factor;
            tail = x % 10;
            if (head != tail) return false;
            x = x % factor;  //delete head
            x = x / 10;      //delete tail
            factor /= 100;
        }
        
        return true;
    }
};