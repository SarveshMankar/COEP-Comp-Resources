#include "rope.h"

void Rope_create(Rope **node, Rope *par, char *s, int l, int r, int leaf_len)
{
    
    Rope *tmp = malloc(sizeof(Rope));
    tmp->left = tmp->right = NULL;
    tmp->parent = par;

    if (par == NULL) {

        tmp->str = NULL;
        tmp->l_count = r;
        *node = tmp;
        Rope_create(&(tmp->left), tmp, s, l, r, leaf_len);

    } else if ((r - l) > leaf_len) {

        tmp->str = NULL;
        tmp->l_count = (r - l) / 2;
        *node = tmp;
        int m = (l + r) / 2;
        Rope_create(&(tmp->left), tmp, s, l, m, leaf_len);
        Rope_create(&(tmp->right), tmp, s, m, r, leaf_len);

    } else {
        *node = tmp;
        tmp->l_count = (r - l);
        int j = 0;
        tmp->str = malloc(leaf_len);
        for (int i = l; i < r; i++)
            tmp->str[j++] = s[i];
    }
}

Rope *Rope_new(char *s, int leaf_len)
{
    int len = strlen(s);
    if (len == 0)
        return NULL;
    Rope *root = NULL;
    Rope_create(&root, NULL, s, 0, len, leaf_len);
    return root;
}

Rope *Rope_subnew(char *s, int strt, int end, int leaf_len)
{
    if ((end > strlen(s) - 1) || (strt > end))
        return NULL;
    Rope *root = NULL;
    Rope_create(&root, NULL, s, strt, end, leaf_len);
    return root;
}

void Rope_delete(Rope *root)
{
    Rope *prev, *node = root;

    while(node != NULL) {
        
        if ((node->right == NULL) && (node->left == NULL)) {
            prev = node->parent;
            if (node->str != NULL)
                free(node->str);
            free(node);
            node = prev;
            continue;
        }
        
        if (node->right == NULL) {
            prev = node;
            node = node->left;
            prev->left = NULL;

        } else {
            prev = node;
            node = node->right;
            prev->right = NULL;
        }
        
    }
}

Rope *Rope_concat(Rope *root1, Rope *root2)
{
    Rope *tmp = malloc(sizeof(Rope));
    tmp->parent = tmp->right = NULL; 
    tmp->str = NULL;
    tmp->l_count = ROPE_LEN(root1) + ROPE_LEN(root2);

    Rope *r1 = Rope_duplicate(root1);
    Rope *r2 = Rope_duplicate(root2);

    tmp->left = r1;
    r1->parent = tmp;
    r1->right = r2;
    r2->parent = r1;

    return tmp;
}

char *Rope_get_char(Rope *root, int i)
{
    int len = ROPE_LEN(root);

    if ((i > len - 1) || (len == 0))
        return NULL;

    i += 1;

    Rope *node = root->left;
    int pos = node->l_count;

    while(1) {
        if (pos >= i) {
            if (node->left == NULL) {
                int tmp = pos - (node->l_count - 1);
                i -= tmp;
                return &(node->str[i]);
            }
            Rope *par = node;
            node = node->left;
            pos -= (par->l_count - node->l_count);
        } else {
            node = node->right;
            pos += node->l_count;
        }
    }

}

bool Rope_set_char(Rope *root, int i, char c)
{
    int len = ROPE_LEN(root);

    if ((i > len - 1) || (len == 0))
        return false;

    i += 1;

    Rope *node = root->left;
    int pos = node->l_count;

    while(1) {
        if (pos >= i)
        {
            if (node->left == NULL)
            {
                int tmp = pos - (node->l_count - 1);
                i -= tmp;
                node->str[i] = c;
                return true;
            }
            Rope *par = node;
            node = node->left;
            pos -= (par->l_count - node->l_count);
        }
        else
        {
            node = node->right;
            pos += node->l_count;
        }
    }
}

char *Rope_to_str(Rope *root)
{
    int len = ROPE_LEN(root);
    char *s = malloc(len + 1);
    s[len] = '\0';
    char *pos = s;
    int i = 0;
    while(i < len)
        *pos++ = *(Rope_get_char(root, i++));
    return s; 
}

char *Rope_to_substr(Rope *root, int st, int e)
{
    int len = e - st + 1;
    char *s = malloc(len + 1);
    s[len] = '\0';
    char *pos = s;
    int i = st;
    int end = e + 1;
    while (i < end)
        *pos++ = *(Rope_get_char(root, i++));
    return s;
}

static void Rope_print_int(Rope *r)
{
    if (r == NULL)
        return;
    if ((r->left == NULL) && (r->right == NULL))
    {
        for (int i = 0; i < r->l_count; i++){
            putchar(r->str[i]);
        }
    }
    Rope_print_int(r->left);
    Rope_print_int(r->right);
}

void Rope_print(Rope *r){
    if(r==NULL){
        printf("Empty\n");
        return;
    }
    Rope_print_int(r);
    putchar('\n');
}

void LL_insert(Node **head, int line_num, Rope *s){
    if (*head == NULL){
        *head = malloc(sizeof(Node));
        (*head)->line_num = line_num;

        (*head)->s = malloc(sizeof(Rope *));
        (*head)->s[0] = s;

        (*head)->ref_count = 1;
        (*head)->next = NULL;
        return;
    }else{  
        Node *temp = *head;
        while(temp->next != NULL && temp->line_num != line_num){
            temp = temp->next;
        }
        if(temp->line_num == line_num){
            printf("Latest Version: %d\n", temp->ref_count);
            temp->s = realloc(temp->s, sizeof(Rope *) * (temp->ref_count + 1));
            temp->s[temp->ref_count] = s;
            temp->ref_count++;
            printf("Latest Version Inserted!: %d\n", temp->ref_count);
            return;
        }else{
            Node *nn = (Node *)malloc(sizeof(Node));
            nn->line_num = line_num;
            nn->s = malloc(sizeof(Rope *));
            nn->s[0] = s;
            nn->ref_count = 1;
            nn->next = NULL;
            temp->next = nn;
            return;
        }

    }
}

void LL_complete_display(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("Line Number %d: \n", temp->line_num);
        for(int i = 0; i < temp->ref_count; i++){
            printf("Version No %d: ", i+1);
            Rope_print(temp->s[i]);
        }
        printf("\n----------------\n");
        temp = temp->next;
    }
}

int *Rope_search(Node* head, char *search, int *t){
    int *output = calloc(1, sizeof(int));
    int *total = calloc(1, sizeof(int));
    int *count = calloc(1, sizeof(int));
    while (head != NULL){
        char *s = Rope_to_str(head->s[head->ref_count-1]);
        int *index = calloc(1, sizeof(int));
        int *ans = calloc(1, sizeof(int));
        int *flag = calloc(1, sizeof(int));
        Rope_check(head->s[head->ref_count-1], search, index, ans, flag, strlen(search), count, output, total);
        head=head->next;
    }

    // printf("Output: ");
    // for(int i = 0; i < total[0]; i++){
    //     printf("%d ", output[i]);
    // }
    t[0]=total[0];
    return output;
}

void Rope_check(Rope *r, char *s, int *index, int *ans, int *flag, int str_len, int *count, int *output, int *total){
    if (r == NULL)
        return;
    if ((r->left == NULL) && (r->right == NULL)){
        for (int i = 0; i < r->l_count; i++){
            count[0]++;
            // putchar(r->str[i]);
            if(r->str[i]==s[0] && flag[0]==0){
                ans[0]=count[0];
                // printf("\nYesh: %d\n", ans[0]);
                flag[0]=1;
            }
            if(r->str[i]==s[index[0]]){
                index[0]++;
            }else{
                index[0]=0;
                flag[0]=0;
            }
            if(index[0]==str_len){
                output = realloc(output, sizeof(int) * (total[0]+1));
                output[total[0]] = ans[0];
                total[0]++;
                index[0]=0;
            }
        }
    }
    Rope_check(r->left, s, index, ans, flag, str_len, count, output, total);
    Rope_check(r->right, s, index, ans, flag, str_len, count, output, total);
}

void Check_if_changed(Node *head, int line_num, Rope *s){
    printf("\nChecking!");
    Node *temp = head;
    while(temp != NULL && temp->line_num != line_num){
        temp = temp->next;
    }
    int s1=ROPE_LEN(s);
    int s2=ROPE_LEN(temp->s[temp->ref_count-1]);

    // printf("\n%d %d\n", s1, s2);

    char *str1 = Rope_to_str(s);
    char *str2 = Rope_to_str(temp->s[temp->ref_count-1]);
    int cmp = strcmp(str1, str2);
    if(cmp!=0){
        printf("Line %d has been changed\n", line_num);
        if(cmp>0){
            printf("Appended\n");
        }else{
            printf("Deleted\n");
        }
    }
    else{
        printf("\nLine %d has not been changed\n", line_num);
    }
    printf("\n");
}



void For_calls(Node *head){
    int flag=1;
    while (flag){
        printf("Enter 1 to insert, 2 to delete, 3 to display, 4 to search, 5 to concat, 6 to get substring, 7 to set char, 8 to get char, 9 to exit: \n");
        int choice;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter line number: ");
            int line_num;
            scanf("%d", &line_num);
            printf("Enter string: ");
            char *s = malloc(sizeof(char) * 100);
            // scanf("%s", s);
            scanf(" %[^\n]s", s);
            Rope *r = Rope_new(s, 2);
            LL_insert(&head, line_num, r);
            break;
        case 2:
            printf("Enter line number: ");
            int line_num2;
            scanf("%d", &line_num2);
            Node *temp = head;
            while(temp->next != NULL && temp->line_num != line_num2){
                temp = temp->next;
            }
            if(temp->line_num == line_num2){
                // temp->ref_count--;
                // if(temp->ref_count == 0){
                //     free(temp->s);
                //     temp->s = NULL;
                // }
                Rope_delete(temp->s[temp->ref_count]);
            }
            break;
        case 3:
            LL_complete_display(head);
            break;
        case 4:
            printf("Enter String to search: ");
            char *s2 = malloc(sizeof(char) * 100);
            scanf("%s", s2);
            // Call Search Function
            break;
        case 5:
            printf("Enter line number 1: ");
            int line_num3;
            scanf("%d", &line_num3);
            printf("Enter line number 2: ");
            int line_num4;
            scanf("%d", &line_num4);

            Node *temp1 = head;
            Node *temp2 = head;
            while(temp1->next != NULL && temp1->line_num != line_num3){
                temp1 = temp1->next;
            }
            while(temp2->next != NULL && temp2->line_num != line_num4){
                temp2 = temp2->next;
            }

            if(temp1->line_num == line_num3 && temp2->line_num == line_num4){
                Rope *r1 = temp1->s[temp1->ref_count-1];
                Rope *r2 = temp2->s[temp2->ref_count-1];
                Rope *r3 = Rope_concat(r1, r2);
                // printf("R3: \n");
                // Rope_print(r3);
                LL_insert(&head, line_num3, r3);
            }
            break;
        case 9:
            flag = 0;
            break;
        default:
            break;
        }
    }
    
}


void LL_file_save(FLNode **FLhead, Node *head){
    if(*FLhead == NULL){
        FLNode *nn = (FLNode *)malloc(sizeof(FLNode));
        nn->version_num = 1;
        nn->lines = malloc(sizeof(Rope *));
        int index=0;
        while(head){
            int r=head->ref_count;
            char *s = Rope_to_str(head->s[r-1]);
            Rope *r1 = Rope_new(s, 2);

            nn->lines = realloc(nn->lines, sizeof(Rope*) + 1);
            nn->lines[index]=r1;
            index++;

            head=head->next;
        }
        nn->line_count=index;
        nn->next = NULL;
        *FLhead = nn;
        return;
    }
    
    FLNode *temp = *FLhead;
    while(temp->next != NULL){
        temp = temp->next;
    }

    FLNode *nn = (FLNode *)malloc(sizeof(FLNode));
    nn->version_num = temp->version_num + 1;
    nn->lines = malloc(sizeof(Rope *));
    int index=0;
    while(head){
        int r=head->ref_count;
        char *s = Rope_to_str(head->s[r-1]);
        Rope *r1 = Rope_new(s, 2);

        nn->lines = realloc(nn->lines, sizeof(Rope*) + 1);
        nn->lines[index]=r1;
        index++;

        head=head->next;
    }
    nn->line_count=index;
    nn->next = NULL;
    temp->next = nn;
}

Rope *Rope_duplicate(Rope *r1){
    char *str = Rope_to_str(r1);
    Rope *r2 = Rope_new(str, 2);
    return r2;
}