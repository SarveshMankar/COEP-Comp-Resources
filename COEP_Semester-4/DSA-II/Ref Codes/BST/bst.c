#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//tree functions

void initBST(bst *t){ // to initialize the tree
    *t = NULL;
    return;
}

void insertNode(bst *t, double d, char a[LEN]){ // recursive function to add a new node to the tree

    node *nn = (node*)malloc(sizeof(node));
    if(!nn)
        return;
    nn->mis = d;
    strcpy(nn->name, a);
    nn->right = NULL;
    nn->left = NULL;
    nn->parent = NULL;
    //when tree is empty
    if(*t == NULL){
        *t = nn; //nn is the first node in tree i.e., root node
        return;
    }
    node *p = *t;
    if(d < p->mis){
        nn->parent = p;
        insertNode(&p->left, d, a);

    }
    else if(d > p->mis){
        nn->parent = p;
        insertNode(&p->right, d, a);
    }
    else
        return;
}

int search(bst t, double d){ // to recursive search for a node with the key and return a boolean value
    if(!t)//if tree empty
        return 0;//hence node not present
    node *p;
    //set the pointer p to root
    p = t;
    //searching for d in the tree
    if(d == p->mis)
        return 1;
    if(d < p->mis)
        return search(p->left, d);
    if(d > p->mis)
        return search(p->right, d);
    else
        return 0;
}

void removeNode(bst *t, double d){// to remove a node from a tree
    if(!t)//if tree empty
        return;
    node *p, *q = NULL;
    //set the pointer p to root
    p = *t;
    int side;
    //searching for d in the tree
    while(p){
        if(d == p->mis)
            break;
        q = p;
        if(d <p->mis){
            p = p->left;
            side = 0;
        }
        else{
            p = p->right;
            side = 1;
        }
    }
    //p is NULL means d not found
    if(!p)
        return;
    //p is not NULL means node is found
    //leaf
    if(!p->left && !p->right){
        if(!q){ //only one node in tree
            *t = NULL;
            free(p);
            return;
        }
        if(side)
            q->right = NULL;
        else
            q->left = NULL;
        free(p);
        return;
    }
    //one child
    //left child
    if(p->left && !p->right){
        if(!q){//means p is a root node with only left child
            *t = p->left;
            p->left->parent = p->parent;
            free(p);
            return;
        }
        if(side == 0)//p is the left child of q
            q->left = p->left;
        else //p is right child of q
            q->right = p->left;
        free(p);
    }
    //only right
     if(!p->left && p->right){
        if(!q){//means p is a root node with only right child
            *t = p->right;
            p->right->parent = p->parent;
            free(p);
            return;
        }
        if(side == 0)
            q->left = p->right;
        else
            q->right = p->right;
        free(p);
    }
    //two children node
    if (p->right && p->left){
        node *r = NULL, *s = NULL;//r as parent of s like q was parent of p
      //go to left then to the rightmost node
        s = p->left;
        while(s->right){
            r = s;
            s = s->right;
        }
        //r is null
        //copy s value to p
        //p->left as null &free s
        if(!r){
            p->mis = s->mis;
            strcpy(p->name, s->name);
            p->parent = s->parent;
            p->left = s->left;
            free(s);
            return;
        }
        //copy key of node s to p
        //make right of r as null
        //free s
        p->mis = s->mis;
        strcpy(p->name, s->name);
        p->parent = s->parent;
        r->right = s->left;
        free(s);
        return;
    }
    return;

}

//void r_postorder(bst t){
//    if(!t)
//        return;
//    r_postorder(t->left);
//
//    r_postorder(t->right);
//    printf(" %0.f->%s  ", t->mis, t->name);
//    return;
//}

void postorder(bst t){ // non-recursive function for post order traversal

    stack s1, s2; //creating 2 stacks
    node *n = t;
    initStack(&s1, 50);
    initStack(&s2, 50);
    if(!t)//if tree is empty just return
        return;
    push(&s1, *t);//push root node into first stack
    while(!isempty(s1)){
        *n = pop(&s1);//pop root node from stack 1 and push it into stack 2
        push(&s2, *n);
        if(n->left)
            push(&s1, *(n->left));
        if(n->right)
            push(&s1, *(n->right));
    }
    while(!isempty(s2))
    {
        *n = pop(&s2);
        printf(" %0.f->%s  ", n->mis, n->name);

    }
}
void destroyTree(bst *t){// to delete all nodes of a tree
    if(t == NULL)//if tree empty
        return;
    node *p = *t;
    if(p->left){//destroying left subtree
        destroyTree(&p->left);
    }
    if(p->right){//destroying right subtree
        destroyTree(&p->right);
    }
    free(p);//deleting node
    *t = NULL;//setting root node to NULL
        return;
    //traversing tree in post order to delete every node of tree
    //destroying subtrees
//    destroyTree(t->left);
//    destroyTree(t->right);
//  //deleting node
    // free(t);
   // *t = NULL;
}

void Display_Level(bst t, int curr_level, int level){ // to display all nodes of ith level
    if(t == NULL)
        return;
    if(curr_level == level){
        printf(" %0.f->%s", t->mis, t->name);
        return;
    }
    Display_Level(t->left, curr_level+1, level);
    Display_Level(t->right, curr_level+1, level);

}

//stack functions
void initStack(stack *s, int i){
    s->A = (node*)malloc(sizeof(node)*i);
    s->size = i;
    s->top = -1;
}
void push(stack *s, node n){
    if(isfull(*s)){
        return;
    }
    s->top++;
    s->A[s->top] = n;
    return;
}

node pop(stack *s){
    node empty;
    empty.mis = INT_MIN;
    strcpy(empty.name,"empty");
    if (isempty(*s)){
        return empty;
    }
    return s->A[s->top--];
}

node peek(stack s){
    node empty, n;
    empty.mis = INT_MIN;
    strcpy(empty.name,"empty");
    if (isempty(s))
        return empty;
    n = s.A[s.top];
    return n;
}

int isfull(stack s){
    if(s.top == s.size - 1)
        return 1;
    else
        return 0;
}

int isempty(stack s){
    if(s.top == -1)
        return 1;
    else
        return 0;
}

