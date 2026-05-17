#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i = 1; i<n; i++){
         t=(struct Node*)malloc(sizeof(struct Node)); 
         t->data = A[i];
         t->next = NULL;
         last ->next = t;
         last = t;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}
void Rdisplay(struct Node *p){
    while(p!=NULL){
        Rdisplay(p->next);
        printf("%d ", p->data);
    }
}
int count(struct Node *p){
    int l=0;
    while(p!=NULL){
        l++;
        p= p->next;
    }
    return l;
}

int sumData(struct Node *p){
    int sum=0;
    while(p!=0){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int main(){
    int A[]={1,3,5,7,9, 10};

    create(A, 6);
    //display(first);  
    // Rdisplay(first);
   // count(first);
   // sumData(first);
    printf("Length is %d \n", count(first));
    printf("Sum is %d ", sumData(first));

    return 0;
}