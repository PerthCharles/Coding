/*
 * TreeHeight
 *      Compute the height of a binary link-tree.
 */


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

// This recursive version in C can cause timeout
/*
 #define MAX(a, b) (((a) >= (b)) ? (a) : (b))
 
 int solution(struct tree * T) {
     // write your code in C90
    if (T->r == NULL && T->l == NULL) {
        return 0;
     } else if (T->r == NULL) {
         return 1 + solution(T->l);
     } else if (T->l == NULL) {
         return 1 + solution(T->r);
     } else {
         return 1 + MAX(solution(T->r), solution(T->l));
    }
 }
 */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <queue>

using namespace std;

int solution(tree * T) {
    // write your code in C++11
    int height = 0;
    queue<tree *> current, next, tmp;
    current.push(T);
    
    while(!current.empty()) {
        while(!current.empty()) {
            tree *p = current.front();
            current.pop();
            if (p->l != NULL) next.push(p->l);
            if (p->r != NULL) next.push(p->r);
        }
        
        // swap current and next
        tmp = next;
        next = current;
        current = tmp;
        
        // count height
        if (!current.empty()) {
            height++;
        }
    }
    
    return height;
}

