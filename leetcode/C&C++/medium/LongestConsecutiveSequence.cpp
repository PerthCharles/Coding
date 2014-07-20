/*
 *  Longest Consecutive Sequence
 *      Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 *      For example,
 *      Given [100, 4, 200, 1, 3, 2],
 *      The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 *      Your algorithm should run in O(n) complexity.
 */

class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            unordered_map<int, bool> used;
            int i, j, len = num.size();
            int longest = 0, length = 0;

            for (i = 0; i < n; i++) {
                used[num[i]] = false;
            }

            for (i = 0; i < n; i++) {
                if (used[num[i]]) continue;
                length = 1;
                
                // find the leftest for num[i]
                for (j = num[i] - 1; used.find(j) != used.end(); j--) {
                    used[j] = true;
                    length++;
                }
                // find the rightest for num[i]
                for (j = num[i] + 1; used.find(j) != used.end(); j++) {
                    used[j] = true;
                    length++;
                }

                longest = length > longest ? length : longest;
            }

            return longest;
        }
}
