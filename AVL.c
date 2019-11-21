#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

typedef struct node* node;

int max(int height, int height1) {
    return height >= height1? height : height1;
}

int height(node root){
    if(!root)
        return -1;
    else
        return root->height;
}

int getBalance(node N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


node RotateRight(node X){
    node w = X->left;
    X->left = w->right;
    w->right = X;

    X->height = max(height(X->left), height(X->right)) + 1;
    w->height = max(height(w->left), height(w->right)) + 1;

    return w;
}

node RotateLeft(node X){
    node w = X->right;
    X->right = w->left;
    w->left = X;

    X->height = max(height(X->left), height(X->right)) + 1;
    w->height = max(height(w->left), height(w->right)) + 1;

    return w;
}

node RotateLeftRight(node root){
    root->left = RotateLeft(root->left);
    return RotateRight(root);
}

node RotateRightLeft(node root){
    root->right = RotateRight(root->right);
    return RotateLeft(root);
}

node Insert(node root, int data) {
    if(!root){
        root = (node) malloc(sizeof(struct node));
        if(!root){
            printf("Memory Error");
            return NULL;
        }
        else
        {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if(data < root->data){
        root->left = Insert(root->left, data);
        if( height(root->left) - height(root->right) == 2){
            if(data < root->left->data) root = RotateRight(root);
            else root = RotateLeftRight(root);
        }
    }
    else if(data > root->data){
        root->right = Insert(root->right, data);
        if(height(root->right) - height(root->left) == 2){
            if(data < root->right->data) root = RotateRightLeft(root);
            else root = RotateLeft(root);
        }
    }
    root->height = max(height(root->left),height(root->right)) + 1;
    return root;
}
node minValueNode(node root)
{
    node current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node deleteNode(node root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left,data);
    }else if(data> root->data){
        root->right = deleteNode(root->right,data);
    }else{
        if( (root->left == NULL) || (root->right == NULL) )
        {
            node temp = root->left ? root->left :
                                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else  *root = *temp;
            free(temp);
        }
        else
        {
            node temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;

    root->height = max(height(root->left),height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return RotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  RotateLeft(root->left);
        return RotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return RotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

void preorder_traverse(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder_traverse(root->left);
    preorder_traverse(root->right);

}

void inorder_traverse(struct node* root)
{
    if(root==NULL) return;

    inorder_traverse(root->left);
    printf("%d ",root->data);
    inorder_traverse(root->right);

}

void postorder_traverse(struct node* root)
{
    if(root==NULL) return;

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d ",root->data);

}

int main() {
    int a;
    printf("AVL Tree Implementation\n\n");
    node AVL = NULL;

    do
    {
        printf("\n1: Insert");
        printf("\n2: Del_node");
        printf("\n3: In-order Traverse");
        printf("\n4: Pre-order Traverse");
        printf("\n5: Post-order Traverse");
        printf("\n0: Quit");

        printf("\n\nEnter your option :\n");
        scanf("%d",&a);
        printf("\n");

        switch(a)
        {
            case 1:;
                int x;
                printf("\nEnter the data to insert: ");
                scanf("%d",&x);
                AVL = Insert(AVL, x);
                break;
            case 2:
                 printf("Enter the data that you want to del_node : ");
                 scanf("%d",&x);
                 AVL =  deleteNode(AVL,x);
                break;
            case 3:
                inorder_traverse(AVL);
                break;
            case 4:
                preorder_traverse(AVL);
                break;
            case 5:
                postorder_traverse(AVL);
                break;
            case 0:
                printf("\nBye");
                break;
            default:
                printf("\nInvalid Input\n");
                break;
        }
    }while(a!=0);


    return 0;
}