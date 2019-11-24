#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int value;
    int bf;
    struct tnode* left;
    struct tnode* right;
    
};
int findMin(struct tnode* root);

struct tnode* createNode(int value)
{
    struct tnode* n = (struct tnode*)malloc (sizeof(struct tnode*));
    n->left = NULL;
    n->right = NULL;
    n->bf = 0;  
    n->value = value;
    return n;  
} 

int height(struct tnode* node)
{
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


int balanceFactor(struct tnode* node)
{
    return (height(node->left)-height(node->right));
}

struct tnode* rotateRight(struct tnode* node)
{
    struct tnode* newParent = node->left;
    struct tnode* shift = newParent->right;

    newParent->right =  node;
    node->left = shift;

    node->bf = balanceFactor(node);
    newParent->bf = balanceFactor(newParent);

    return newParent;
}

struct tnode* rotateLeft(struct tnode* node)
{
    struct tnode* newParent = node->right;
    struct tnode* shift = newParent->left;

    newParent->left = node;
    node->right = shift;

    node->bf = balanceFactor(node);
    newParent->bf = balanceFactor(newParent);

    return newParent; 
}

struct tnode* insert(struct tnode* node , int value)
{
    
    if(node == NULL)
       
        return createNode(value);
    if(value>node->value)
        node->right = insert(node->right,value);
    else if (value<node->value)
        node->left = insert(node->left,value);
    else
        return node;

    node->bf=balanceFactor(node);

    if(node->bf>1 && value < node->left->value)
        return rotateRight(node);
    else if(node->bf<-1 && value > node->right->value)
        return rotateLeft(node);
    else if(node->bf>1 && value > node->left->value)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }    
    else if(node->bf<-1 && value > node->right->value)
    {
        node->left = rotateRight(node->right);
        return rotateLeft(node);
    }    

    return node;
}


struct tnode* del_node(struct tnode* root,int x)
{
  

  if(root==NULL)  {
    printf("Tree is empty");
    return root;
  }

  else if (x<root->value)
  {
    root->left=del_node(root->left,x);
  }
  else if(x>root->value)
  {
    root->right=del_node(root->right,x);
  }
  else  // value found
  {
    if(root->left==NULL)
    {
      struct tnode* temp = root;
      root=root->right;
      free(temp);
    }
    else if(root->right==NULL)
    {
      struct tnode* temp = root;
      root=root->left;
      free(temp);
    }
    else
    {
      int minimum = findMin(root->right);
      root->value = minimum;
      root->right = del_node(root->right,minimum);
    }
  }
   if (root == NULL) 
      return root; 
   
  root->bf=balanceFactor(root);

  int balance = root->bf;

  if((root->left)->bf>=0 && balance>1)
        return rotateRight(root);
    else if((root->right)->bf<=0  && balance<-1)
        return rotateLeft(root);
    else if((root->left)->bf<0 && balance > 1)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }    
    else if((root->right)->bf>0 && balance <-1)
    {
        root->left = rotateRight(root->right);
        return rotateLeft(root);
    }    


        return root;

}


int findMin(struct tnode* root)
{

  while(root->left != NULL) 
  root = root->left;
  return root->value;
   

}


void preorder_traverse(struct tnode* root)
{
    if(root==NULL) return;
    printf("%d ",root->value);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
          
}



void inorder_traverse(struct tnode* root)
{
    if(root==NULL) return;
    
    inorder_traverse(root->left);
    printf("%d ",root->value);
    inorder_traverse(root->right);
          
}

void postorder_traverse(struct tnode* root)
{
    if(root==NULL) return;
    
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d ",root->value);
          
}

void min(struct tnode* root)
{
  struct tnode* temp = root;
    
      while(temp->left != NULL)
      {
          temp=temp->left;
      }
      
      printf("*Minimun is %d \n",temp->value);
    
}

void max(struct tnode* root)
{
    
      while(root->right != NULL)
      {
          root=root->right;
      }
      printf("*Maximun is %d \n",root->value);
    
}

int main()
{
   int a;
   int x;
   printf("\nEnter the value of root: ");
   scanf("%d",&x);
   struct tnode* root = createNode(x);


    do
    {

        printf("\nEnter 1 to insert");
        printf("\nEnter 2 to del_node");
        printf("\nEnter 3 to preorder_traverse");
        printf("\nEnter 4 to inorder_traverse");
        printf("\nEnter 5 to postorder_traverse");
        printf("\nEnter 6 to print_minimun");
        printf("\nEnter 7 to print_maximun");
        
        printf("\nEnter 0 to exit");

        printf("\n\nEnter your option : ");
        scanf("%d",&a);
        printf("\n\n");

        switch(a)
        {
        case 1:
             
             printf("\nEnter the value to insert: ");
             scanf("%d",&x);
             root = insert(root,x);
            break;
        case 2:
             
             printf("Enter the value that you want to del_node : ");
             scanf("%d",&x);
             root =  del_node(root,x);
             break;
        case 3:
             preorder_traverse(root);
             break;
       case 4:
            inorder_traverse(root);
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