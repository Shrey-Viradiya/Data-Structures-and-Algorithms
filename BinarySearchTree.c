#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct stackNode
{
    struct node* subtree;
    struct stackNode * next;
};

typedef struct node* node;

// Utility Functions

int isEmpty(struct stackNode *top)
{
    return (top == NULL)? 1 : 0;
}

struct stackNode* push(struct stackNode* first, struct node* subtree){
    struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
    temp->subtree = subtree;
    temp->next = NULL;

    if(first == NULL){
        first = temp;
        return first;
    }

    temp->next = first;
    first = temp;
    return first;
}

struct node* pop(struct stackNode** top_ref){
    struct node *res;
    struct stackNode *top;

    /*If sNode is empty then error */
    if(isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->subtree;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

// Binary Search Tree Functions

struct node* insert(struct node* root, int data){
    if(root == NULL){
        root = (node)malloc(sizeof(struct node*));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    struct node* iterNode = root;
    while (1) {

        if(data <= iterNode->data && iterNode->left != NULL){
            iterNode = iterNode->left;
            continue;
        }
        else if(data > iterNode->data && iterNode->right != NULL){
            iterNode = iterNode->right;
            continue;
        }
        else if(data <= iterNode->data && iterNode->left == NULL){
            iterNode->left = (node)malloc(sizeof(struct node*));
            iterNode->left->data = data;
            iterNode->left->left = NULL;
            iterNode->left->right = NULL;
            break;
        }
        else if(data > iterNode->data && iterNode->right == NULL){
            iterNode->right = (node)malloc(sizeof(struct node*));
            iterNode->right->data = data;
            iterNode->right->left = NULL;
            iterNode->right->right = NULL;
            break;
        }
    }

    return root;
}

void traverseRECinorder(struct node* root){
    if(root != NULL){
        traverseRECinorder(root->left);
        printf("%d ",root->data);
        traverseRECinorder(root->right);
    }
}

void traverseRECpreorder(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        traverseRECinorder(root->left);
        traverseRECinorder(root->right);
    }
}

void traverseRECpostorder(struct node* root){
    if(root != NULL){
        traverseRECinorder(root->left);
        traverseRECinorder(root->right);
        printf("%d ",root->data);
    }
}

int findMin(struct node* root){
    struct node* iter= NULL;
    iter = root;
    while (iter->left != NULL)
    {
        iter = iter->left;
    }
    return iter->data;

}

struct node* deleteNode(struct node* root,int data){
    if (root == NULL)
    {
        printf("Tree is Empty");
        return root;
    }

    //

    if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
        return root;
    }
    else if(root->left == NULL){
        root = root->right;
        return root;
    }
    else if(root->right == NULL){
        root= root->left;
        return root;
    }

    // Reach to that Node

    struct node* iterNode = root;
    struct node* pre = root;
    while (iterNode->data != data) {

        if(data < iterNode->data && iterNode->left != NULL){
            pre = iterNode;
            iterNode = iterNode->left;
            continue;
        }
        else if(data > iterNode->data && iterNode->right != NULL){
            pre = iterNode;
            iterNode = iterNode->right;
            continue;
        }

    }

    if (iterNode->data != data)
    {
        printf("Data not Found!");
        return root;
    }

    if (iterNode->left == NULL && iterNode->right == NULL)
    {
        iterNode = NULL;
        return root;
    }
    else if(iterNode->left == NULL){
        if(pre->right == iterNode)
            pre->right = iterNode->right;
        else
            pre->left = iterNode->right;
        return root;
    }
    else if(iterNode->right == NULL){
        if(pre->right == iterNode)
            pre->right = iterNode->left;
        else
            pre->left = iterNode->left;
        return root;
    }
    else
    {
        int min = findMin(iterNode->right);
        iterNode->data = min;
        deleteNode(iterNode->right,min);
        return root;
    }

}

void traverseInorder(struct node* root){
    struct node* iter = root;
    struct stackNode* s = NULL;
    int done = 0;

    while (!(done))
    {
        if(iter != NULL){
            s = push(s, iter);
            iter = iter->left;
        }
        else if(!isEmpty(s)){
            iter = pop(&s);
            printf("%d ", iter->data);
            iter = iter->right;
        }else{
            done = 1;
        }
    }
}

int main(){
    struct node* root = NULL;

    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 3);

    traverseInorder(root);
    printf("\n");

    traverseRECinorder(root);
    printf("\n");

    traverseRECpostorder(root);
    printf("\n");

    traverseRECpreorder(root);

    root = deleteNode(root, 5);

    printf("\n");
    traverseRECinorder(root);

    return 0;
}
