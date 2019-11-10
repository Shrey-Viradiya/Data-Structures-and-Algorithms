#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int balanceFactor;
    struct node* left;
    struct node* right;

};

int findMin(struct node* root)
{

    while(root->left != NULL)
        root = root->left;
    return root->data;


}

struct node* createNode(int data)
{
    struct node* n = (struct node*)malloc (sizeof(struct node*));
    n->left = NULL;
    n->right = NULL;
    n->balanceFactor = 0;
    n->data = data;
    return n;
}

int height(struct node* node){
    if(node==NULL)
        return 0;
    else
    {
        int lh = height(node->left);
        int rh = height(node->right);
        if (lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}

int balanceFactor(struct node* node)
{
    return (height(node->left)-height(node->right));
}

struct node* rotateRight(struct node* node)
{
    struct node* newParent = node->left;
    struct node* shift = newParent->right;

    newParent->right =  node;
    node->left = shift;

    node->balanceFactor = balanceFactor(node);
    newParent->balanceFactor = balanceFactor(node);

    return newParent;
}

struct node* rotateLeft(struct node* node)
{
    struct node* newParent = node->right;
    struct node* shift = newParent->left;

    newParent->left = node;
    node->right = shift;

    node->balanceFactor = balanceFactor(node);
    newParent->balanceFactor = balanceFactor(node);

    return newParent;
}

struct node* insert(struct node* node , int data)
{
    if(node == NULL)
        return createNode(data);
    if(data > node->data)
        node->right = insert(node->right,data);
    else if (data < node->data)
        node->left = insert(node->left,data);
    else
        return node;

    node->balanceFactor=balanceFactor(node);

    if(node->balanceFactor > 1 && data < node->left->data)
        return rotateRight(node);
    else if(node->balanceFactor < -1 && data > node->right->data)
        return rotateLeft(node);
    else if(node->balanceFactor > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    else if(node->balanceFactor<-1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

struct node* del_node(struct node* root,int x)
{
    if(root==NULL)  {
        printf("Tree is empty");
        return root;
    }

    else if (x<root->data)
    {
        root->left=del_node(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=del_node(root->right,x);
    }
    else  // data found
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node* temp = root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node* temp = root;
            root=root->left;
            free(temp);
        }
        else
        {
            int minimum = findMin(root->right);
            root->data = minimum;
            root->right = del_node(root->right,minimum);
        }
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

void min(struct node* root)
{
    struct node* temp = root;

    while(temp->left != NULL)
    {
        temp=temp->left;
    }

    printf("*Minimun is %d \n",temp->data);

}

void max(struct node* root)
{

    while(root->right != NULL)
    {
        root=root->right;
    }
    printf("*Maximun is %d \n",root->data);

}

int main()
{
    int a;
    int x;
    printf("\nEnter the data of root: ");
    scanf("%d",&x);
    struct node* root = createNode(x);

    do
    {
        printf("\n1: Insert");
        printf("\n2: Del_node");
        printf("\n3: In-order Traverse");
        printf("\n4: Pre-order Traverse");
        printf("\n5: Post-order Traverse");
        printf("\n6: Get Minimum");
        printf("\n7: Get Maximum");
        printf("\n0: Quit");

        printf("\n\nEnter your option :\n");
        scanf("%d",&a);
        printf("\n");

        switch(a)
        {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d",&x);
                root = insert(root,x);
                break;
            case 2:
                printf("Enter the data that you want to del_node : ");
                scanf("%d",&x);
                root =  del_node(root,x);
                break;
            case 3:
                inorder_traverse(root);
                break;
            case 4:
                preorder_traverse(root);
                break;
            case 5:

                postorder_traverse(root);
                break;
            case 6:
                min(root);
                break;
            case 7:
                max(root);
                break;
        }
    }while(a!=0);
}