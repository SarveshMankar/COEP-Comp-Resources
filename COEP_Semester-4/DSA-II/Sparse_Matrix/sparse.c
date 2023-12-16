#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "sparse.h"

void init_Sparse(sparse **s, char *filename){
    FILE *fp = fopen(filename, "r");

    int row, col;
    fscanf(fp, "%d", &row);
    fscanf(fp, "%d", &col);
    (*s)->row=row;
    (*s)->col=col;

    (*s)->rows = (node**)malloc(sizeof(node*)*row);
    (*s)->cols = (node**)malloc(sizeof(node*)*col);
    for(int i=0;i<row;i++){
        (*s)->rows[i] = NULL;
    }
    for(int i=0;i<col;i++){
        (*s)->cols[i] = NULL;
    }
}


void insert_Sparse(sparse **s, char *filename){
    FILE *fp = fopen(filename, "r");

    int row, col;
    fscanf(fp, "%d", &row);
    fscanf(fp, "%d", &col);
    
    int val;
    for(int i=0; i<row; i++){
        node *rowNode=NULL;

        for (int j = 0; j < col; j++){
            fscanf(fp,"%d",&val);
            if(val!=0){
                // printf("%d ",val);
                node *temp=(node *)malloc(sizeof(node));
                temp->val=val;
                temp->row=i;
                temp->col=j;
                temp->down=temp->next=NULL;

                if(!rowNode){
                    rowNode=temp;
                }else{
                    node *p=rowNode;
                    while (p->next){
                        p=p->next;
                    }
                    p->next=temp;
                }

                if(!(*s)->cols[j]){
                    (*s)->cols[j]=temp;
                }else{
                    node *p=(*s)->cols[j];
                    while (p->down){
                        p=p->down;
                    }
                    p->down=temp;
                }
            }   
        }
        (*s)->rows[i]=rowNode;
        // printf("\n");
    }
}


void insert_Node(sparse **s, int row, int col, int val){
    node *temp=(node *)malloc(sizeof(node));
    temp->val=val;
    temp->row=row;
    temp->col=col;
    temp->down=NULL;

    if(!(*s)->cols[col]){
        (*s)->cols[col]=temp;
    }else{
        node *p=(*s)->cols[col];
        while (p->down){
            p=p->down;
        }
        p->down=temp;
    }

    if(!(*s)->rows[row]){
        (*s)->rows[row]=temp;
    }else{
        node *p=(*s)->rows[row];
        while (p->next){
            p=p->next;
        }
        p->next=temp;
    }
}


void display_Sparse(sparse *s){
    int r=s->row;
    int c=s->col;

    printf("\nNumber of rows: %d",s->row);
    printf("\nNumber of cols: %d",s->col);

    printf("\n\nRow Wise\n");

    for (int i=0;i<r;i++){
        node *row = s->rows[i];
        while (row){
            printf("\nVal = %d Row = %d Col = %d",row->val,row->row,row->col);
            row=row->next;
        }            
    }

    printf("\n\nCol Wise\n");

    for (int i=0;i<c;i++){
        node *col = s->cols[i];
        while (col){
            printf("\nVal = %d Row = %d Col = %d",col->val,col->row,col->col);
            col=col->down;
        }
                   
    }
    printf("\n\n");
}


sparse *add_Sparse(sparse *s1, sparse *s2){
    sparse *ans = (sparse *)malloc(sizeof(sparse));
    init_Sparse(&ans, "data.txt");

    int r=s1->row;
    int c=s1->col;

    node *r1,*r2, *c1, c2;

    int data,n1,n2;
    for(int i=0; i<r; i++){
        for(int j=0; j<c;j++){
            r1=s1->rows[i];
            r2=s2->rows[i];
            
            while(r1){
                if(r1->col==j){
                    break;
                }
                r1=r1->next;
            }
            while (r2){
                if(r2->col==j){
                    break;
                }
                r2=r2->next;
            }

            if(r1 && r2){
                data=r1->val+r2->val;
            }else if(r1){
                data=r1->val;
            }else if(r2){
                data=r2->val;
            }else{
                data=0;
            }
            
            // printf("%d ",data);
            if(data!=0){
                insert_Node(&ans, i, j, data);
            }
        }
        // printf("\n");    
    }
        
    // printf("\n");
    // printf("\n");
    // display_Sparse(ans);

    return ans;
}


sparse *sub_Sparse(sparse *s1, sparse *s2){
    sparse *ans = (sparse *)malloc(sizeof(sparse));
    init_Sparse(&ans, "data.txt");

    int r=s1->row;
    int c=s1->col;

    node *r1,*r2, *c1, c2;

    int data,n1,n2;
    for(int i=0; i<r; i++){
        for(int j=0; j<c;j++){
            r1=s1->rows[i];
            r2=s2->rows[i];
            
            while(r1){
                if(r1->col==j){
                    break;
                }
                r1=r1->next;
            }
            while (r2){
                if(r2->col==j){
                    break;
                }
                r2=r2->next;
            }

            if(r1 && r2){
                data=r1->val-r2->val;
            }else if(r1){
                data=r1->val;
            }else if(r2){
                data=-r2->val;
            }else{
                data=0;
            }
            
            // printf("%d ",data);
            if(data!=0){
                insert_Node(&ans, i, j, data);
            }
        }
        // printf("\n");    
    }
        
    // printf("\n");
    // printf("\n");
    // display_Sparse(ans);

    return ans;
}


int ifSymmetric(sparse *s){
    int r=s->row;
    int c=s->col;


    if(r!=c){
        return 0;
    }

    for(int i=0; i<r; i++){
        node *row = s->rows[i];
        node *col = s->cols[i];
        while (row && col){
            if(row->val!=col->val){
                return 0;
            }
            row=row->next;
            col=col->down;
        }            
    }

    return 1;
}


sparse *transpose_Sparse(sparse *s){
    int r=s->row;
    int c=s->col;

    sparse *ans = (sparse *)malloc(sizeof(sparse));
    init_Sparse(&ans, "data2.txt");

    for(int i=0; i<r; i++){
        node *row = s->rows[i];
        while (row){
            insert_Node(&ans, row->col, row->row, row->val);
            row=row->next;
        }            
    }

    return ans;
}