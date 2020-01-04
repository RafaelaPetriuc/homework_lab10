#include <stdio.h>
//ex 3.2
int H(int x, int n){
    if(n==0)
        return 1;
    else
        if(n==1)
            return 2*x;
        else
            return 2*n*H(x, n-1)-2*(n-1)*H(x, n-2);
}

int HNonR(int n, int x){
    if(n==0)
        return 1;
    else
        if(n==1)
            return 2*x;
    int n0 = 1;
    int n1 = 2*x;
    int nn;
    for (int i=1; i<n; i++) {
        nn = 2*(i+1)*n1 -  2*i*n0;
        n0=n1;
        n1=nn;
    }
    return nn;
}

int main() {
    int n=3, x=2, r, nr;
    r=H(x,n);
    nr=HNonR(n, x);
    printf("the recursive result is %d\n", r);
    printf("the non recursive result is %d", nr);
    return 0;
}