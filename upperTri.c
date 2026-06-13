#include<stdio.h>
#include<stdlib.h>

struct UTMatrix{
    int *a;
    int n;
};

void Set(struct UTMatrix *m, int i, int j, int x){
    if( i <= j)
        m->a[n(i-1) - (((i-2)*(i-1))/2) + (j-1)]=x;
}

int Get(struct UTMatrix m, int i, int j){
    if(i<=j)
        return m.a[n(i-1) - (((i-2)*(i-1))/2) + (j-1)];
    else
        return 0;
}

void Display(struct UTMatrix m){
    int i, j;
    for( i=1; i<=m.n; i++){
        for(j=1; j<=m.n; j++){
        if(i>=j)
            printf("%d ", m.a[m.n * (i-1) - (((i-2)*(i-1))/2) + (j-1)]);
        else
            printf("0 ");
        }
        printf("\n");
    }
}

int main(){
    struct UTMatrix  m;
    int i, j, x;
    printf("Enter dimension:\n");
    scanf("%d", &m.n);

    m.a = (int *)malloc(m.n*(m.n+1) / 2 * sizeof(int));

    printf("Enter all Elements: \n");
    for(i=1; i<=m.n; i++){
        for(j=1; j<=m.n; j++){
            scanf("%d", &x);
            Set(&m , i, j, x);
        }
    }
    printf("\n\n");
    Display(m);
    return 0;

}