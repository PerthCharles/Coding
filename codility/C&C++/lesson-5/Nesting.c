/*
 * Nesting
 *      Determine whether given string of parentheses is properly nested.
 */

int solution(char *S)
{
    int i, cnt = 0;
    int n = strlen(S);

    for (i = 0; i < n; i++) {
        if (S[i] == '(') {
            cnt++;
        } else if (cnt > 0) {
            cnt--;
        } else {
            return 0;
        }
    }
    if (cnt == 0) {
        return 1;
    } else {
        return 0;
    }
}
