/*
 * CountNonDivisible
 *      Calculate the number of elements of an array that are not divisors of each element.
 */

struct Result solution(int A[], N)
{
    struct Results result;
    result.C = (int *)malloc(sizeof(int)*N);
    memset(result.C, 0, sizeof(int)*N);
 
    int *nums, *divisors;
    nums = (int *)malloc(sizeof(int)*(N*2+1));
    divisors = (int *)malloc(sizeof(int)*(N*2+1));
    memset(nums, 0, sizeof(int)*(N*2+1));
    memset(divisors, 0, sizeof(int)*(N*2+1));
    int i, j;
 
    for (i = 0; i < N; i++) {
        nums[A[i]]++;
    }
     
    // divisors[i] marks how much divisors of *i* that shown up in array A
    for (i = 1; i <= 2*N; i++) {
        if (nums[i] > 0) {
            if (nums[i] > 1) divisors[i] += nums[i] - 1;
            j = i + i;
            while (j <= 2*N) {
                if (nums[j] > 0) {
                    divisors[j] += nums[i];
                }
                j += i;
            }
        }
    }
    
    for (i = 0; i < N; i++) {
        result.C[i] = (N-1) - divisors[A[i]];
    }
    result.L = N;
    
    return result;
}
