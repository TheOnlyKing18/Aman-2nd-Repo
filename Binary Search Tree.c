#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * Left;
    struct Node * Right;
}Node ;

Node * Create_node(int item){
    Node * newnode = malloc(sizeof(Node));
    if(newnode==NULL)
    return NULL;
    newnode->data=item;
    newnode->Left=NULL;
    newnode->Right=NULL;
    return newnode;
}
void Search(Node *Root, int item, Node **loc, Node **par){
    *loc=NULL;
    *par=NULL;

    Node *ptr;
    Node *save;
    ptr=Root;
    save=NULL;
    while(ptr != NULL){
        if(ptr->data==item){
            *loc=ptr;
            *par=save;
            return;
        }
        save=ptr;
        ptr=(item<ptr->data) ? ptr->Left : ptr->Right;
    }
}

void insert(Node **Root, int item){
    Node * loc;
    Node * par;
    Search(*Root,item,&loc,&par);

    if(loc!=NULL)
    return;

    Node * newnode=Create_node(item);
    if(newnode==NULL)
    return;

    if(par==NULL){
        *Root=newnode;
    }
    else{
        if(item<par->data)
        par->Left=newnode;
        else
        par->Right=newnode;
    }
}

int no_of_children(Node * loc){
    int count = 0;
    if(loc->Left != NULL)
    count++;
    if(loc->Right != NULL)
    count++;
    return count;
}

void delete(Node**Root, int item){
    Node*loc;
    Node*par;
    Search(*Root,item,&loc,&par);

    if(loc == NULL) {
        printf("Underflow! Item not found!\n");
        return;
    }

    int n = no_of_children(loc);

    if(n==0){
        if(par==NULL)
            *Root=NULL;
        else if(par->Left==loc)
            par->Left=NULL;
        else
            par->Right=NULL;
        free(loc);
    }

    else if(n==1){
        Node * child=(loc->Left != NULL) ? loc->Left : loc->Right;
        if(par==NULL)
            *Root=child;
        else if(par->Left==loc)
            par->Left=child;
        else
            par->Right=child;
        free(loc);
    }

    else{
        Node *suc;
        Node *suc_par;
        suc=loc->Right;
        suc_par=NULL;
        while(suc->Left!=NULL){
            suc_par=suc;
            suc=suc->Left;
        }
        loc->data=suc->data;

        Node *suc_child=suc->Right;
        if(suc_par->Left == suc)
            suc_par->Left = suc_child;
        else
            suc_par->Right = suc_child;
        free(suc);
    }


}