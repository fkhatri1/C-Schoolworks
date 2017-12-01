#include<stdio.h>

int main() {
    int ii;
    int a[] = {1,2,3,4,5,6};
    int * b = &a[1];

    for (ii=0;ii<6;ii++) {
        printf("%d ",*(b+ii));
    }
    printf("\n");
    return 0;
}
