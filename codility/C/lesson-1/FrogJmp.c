/*
 * FrogJmp
 *      Count minimal number of jumps from position X to Y.
 */

int solution(int X, int Y, int D)
{
    // write your code in C90
    int steps = 0;
    steps = (Y - X)/D; // look out '/' in C
    if ((Y - X)%D != 0) {
        steps++;
    }
    return steps
} 
