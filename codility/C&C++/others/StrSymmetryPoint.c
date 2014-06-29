/*
 * StrSymmetryPoint
 *      Find a symmetry point of a string, if any.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *S) {
    // write your code in C90
    int i, j, pivot, len;
    
    len = strlen(S);
    if (len % 2 == 0) return -1;
    pivot = len/2;
    
    for (i = pivot - 1, j = pivot + 1; i >= 0; i--, j++) {
        if (S[i] != S[j]) return -1;
    }
    
    return pivot;
}
