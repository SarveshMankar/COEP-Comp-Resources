#include "rope.h"
Node *head=NULL;
FLNode *fhead=NULL;

int main(void)
{
    Rope *r = Rope_new("My name is Sean", 2);
    // printf("%d \n", r->l_count);
    Rope *l = r->left;
    // printf("%d \n", l->l_count);
    l = l->left;
    // printf("%d \n", l->l_count);
    l = l->right;
    // printf("%d \n", l->l_count);
    // printf("%d\n", l->str == NULL);
    // Rope_print(r);
    // printf("%ld %ld\n", sizeof("me"), strlen("me"));
    Rope_delete(r);
    Rope *a = Rope_new("Hello world!", 2);
    Rope *c = Rope_new("Error!", 2);
    LL_insert(&head, 1, a);
    LL_insert(&head, 1, c);
    Check_if_changed(head, 1, a);

    Rope *b = Rope_new("How are you?", 2);
    LL_insert(&head, 2, b);

    LL_complete_display(head);
    LL_file_save(&fhead, head);

    printf("\n--------\n");

    Rope *d = Rope_new("I am fine", 2);
    LL_insert(&head, 1, d);
    LL_complete_display(head);
    LL_file_save(&fhead, head);
    
    printf("\n--------\n");
    FLNode *temp = fhead;
    while(temp != NULL){
        printf("%d\n", temp->version_num);
        for(int i=0;i<temp->line_count;i++){
            Rope_print(temp->lines[i]);
        }
        temp = temp->next;
    }



    // LL_insert(&head, 1, a);
    
    // Check_if_changed(head, 1, b);


    // int *total = calloc(1, sizeof(int));
    // int *n = Rope_search(head, "o", total);
    // if(total[0]==0){
    //     printf("Not found\n");
    // }else{
    //     printf("\nFound at: ");
    //     for (int i=0; i<total[0]; i++){
    //         printf("%d ", n[i]);
    //     }
    //     printf("\n");
        
    // }



    // printf("\n----------------\n");

    // LL_complete_display(head);
    // Rope *c = Rope_concat(b, a);
    // LL_complete_display(head);

    // int line_num3 = 2;
    // int line_num4 = 1;

    // Node *temp1 = head;
    // Node *temp2 = head;
    // while(temp1->next != NULL && temp1->line_num != line_num3){
    //     temp1 = temp1->next;
    // }
    // while(temp2->next != NULL && temp2->line_num != line_num4){
    //     temp2 = temp2->next;
    // }


    // if(temp1->line_num == line_num3 && temp2->line_num == line_num4){
    //     Rope *r1 = temp1->s[temp1->ref_count-1];
    //     Rope *r2 = temp2->s[temp2->ref_count-1];
    //     printf("R1: \n");
    //     Rope_print(r1);
    //     printf("R2: \n");
    //     Rope_print(r2);

    //     Rope *r3 = Rope_concat(r1, r2);

    //     printf("R3: \n");
    //     Rope_print(r3);

    //     LL_insert(&head, line_num3, r3);
    // }

    // line_num3 = 2;
    // line_num4 = 1;

    // temp1 = head;
    // temp2 = head;
    // while(temp1->next != NULL && temp1->line_num != line_num3){
    //     temp1 = temp1->next;
    // }
    // while(temp2->next != NULL && temp2->line_num != line_num4){
    //     temp2 = temp2->next;
    // }


    // if(temp1->line_num == line_num3 && temp2->line_num == line_num4){
    //     Rope *r1 = temp1->s[temp1->ref_count-1];
    //     Rope *r2 = temp2->s[temp2->ref_count-1];
    //     printf("R1: \n");
    //     Rope_print(r1);
    //     printf("R2: \n");
    //     Rope_print(r2);

    //     Rope *r3 = Rope_concat(r1, r2);

    //     printf("R3: \n");
    //     Rope_print(r3);

    //     LL_insert(&head, line_num3, r3);
    // }

    // LL_complete_display(head);




    // Rope_print(c);
    // Rope_delete(c);

    For_calls(head);
    return 0;
}


// 1 = Insert
// 2 = Delete
// 3 = Display
// 4 = Search
// 5 = Concat
// 6 = Get Substring
// 7 = Get Substring Position