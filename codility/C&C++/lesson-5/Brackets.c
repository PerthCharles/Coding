/*
 * Brackets
 *      Determine whether a given string of parentheses is properly nested.
 */

int solution(char *S)
{
    int i, top;
    int n = strlen(S);
    char *stack;
    stack = (char *)malloc(sizeof(char)*n);

    for (top = 0, i = 0; i < n; i++) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{') {
            stack[top++] = S[i];
        } else if (top > 0 && ( (S[i] == ']' && stack[top-1] == '[')
                             || (S[i] == ')' && stack[top-1] == '(')
                             || (S[i] == '}' && stack[top-1] == '}') )) {
            top--;
        } else {
            return 0;
        }
    }

    if (top == 0) {
        return 1;
    } else {
        return 0;
    }
}
