/*
 * NumberOfDiscIntersections
 *      Compute intersections between sequence od discs
 */

#include <algorithm>

// Find this method from:
//      http://blog.csdn.net/caopentcs/article/details/9327069

int solution(const vector<int> &A)
{
    // write your code in C++98
    int N = A.size();
    int M = N << 1;
    int result = 0, intersect = 0, i, j;
    vector< pair<long long, int> > end_points(M);

    for (i = 0, j = 0; i < N; i++) {
        end_points[j++] = make_pair((long long)i - A[i], -1); // -1 means left edge point
        end_points[j++] = make_pair((long long)i + A[i], 1);  // 1 means right edge point
    }

    sort(end_points.begin(), end_points.end());

    for (j = 0; j < M; j++) {
        if (end_points[j].second < 0) {
            // new disc comes, so this new disc has intersect with all the discs left
            result += intersect;
            intersect++;
        } else {
            intersect--;
        }
        if (result > 10000000) {
            return -1;
        }
    }

    return result;
}
