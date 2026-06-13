#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i; int j; int x;
};

struct Sparse{
    int m, n, num;
    struct Element *e;
};

void Create(struct Sparse *s){
    printf("Enter Dimenssion:\n");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter number of Non-zero elements:\n");
    scanf("%d", &s->num);

    s->e = (struct Element*)malloc(s->num * sizeof(struct Element));

    printf("Enter non-zero element:\n");
    for(int i=0; i<s->num; i++){
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void Display(struct Sparse s){
    int i, j, k=0; 
    
    for(i=0; i<s.m; i++){
        for(j=0; j<s.n; j++){
            if(i==s.e[k].i && j==s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}


int main(){
    struct Sparse s;

    Create(&s);
    Display(s);
    return 0;
}