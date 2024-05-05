#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left,*right;
    int height;
}*root=NULL;
typedef struct node NODE;
NODE *create(int key)
{
    NODE *newnode=(NODE*)malloc(sizeof(NODE));
    newnode->key=key;
    newnode->left=newnode->right=NULL;
    newnode->height=1;
    return (newnode);
}
int height(NODE *N)
{
    if(N==NULL)
        return 0;
    else
        return N->height;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
NODE *rightrotate(NODE *y)
{
    NODE *x=y->left;
    NODE *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
NODE *leftrotate(NODE *x)
{
    NODE *y=x->right;
    NODE *T2=y->left;
    y->left=x;
    x->right=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return y;
}
int getbalance(NODE *N)
{
    if(N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}
NODE *insert(NODE *node,int key)
{
    if(node==NULL)
        return (create(key));
    if(key<node->key)
        node->left=insert(node->left,key);
    else if(key>node->key)
        node->right=insert(node->right,key);
    else
        return node;
    node->height=1+max(height(node->left),height(node->right));
    int balance=getbalance(node);
    if(balance>1&&key<node->left->key)
        return rightrotate(node);
    if(balance<-1&&key>node->right->key)
        return leftrotate(node);
    if(balance>1&&key>node->left->key){
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance<-1&&key<node->right->key){
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
NODE *minvaluenode(NODE *node)
{
    NODE *current=node;
    while(current->left!=NULL){
        current=current->left;
        return current;
    }
}
NODE *deletenode(NODE *root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->key)
        root->left=deletenode(root->left,key);
    else if(key>root->key)
        root->right=deletenode(root->right,key);
    else{
        if(root->left==NULL||root->right==NULL)
        {
            NODE *temp=root->left?root->left:root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
                *root=*temp;
            free(temp);
        }
        else{
            NODE *temp=minvaluenode(root->right);
            root->key=temp->key;
            root->right=deletenode(root->right,temp->key);
        }
    }
    if(root==NULL)
        return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getbalance(root);
    if(balance>1&&getbalance(root->left)>=0)
        return rightrotate(root);
    if(balance<-1&&getbalance(root->right)<=0)
        return leftrotate(root);
    if(balance>1&&getbalance(root->left)<0){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1&&getbalance(root->left)>0){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int op,i,n,key;
    printf("---AVL Tree---\n1.create\n2.insert\n3.delete\n4.display\n5.exit\n");
    do{
        printf("Enter a option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter no of nodes to construct a AVL tree:");
                   scanf("%d",&n);
                   for(i=1;i<=n;i++){
                       printf("Enter NODE data:");
                       scanf("%d",&key);
                       root=insert(root,key);
                   }
                   break;
            case 2:printf("Enter NODE data:");
                   scanf("%d",&key);
                   root=insert(root,key);
                   break;
            case 3:printf("Enter NODE data:");
                   scanf("%d",&key);
                   root=deletenode(root,key);
                   break;
            case 4:printf("Pre-order Traversal:");
                   preorder(root);
                   printf("\n");
                   break;
            case 5:break;
            default:printf("Invalid option\n");
        }
    }while(op!=5);
    return 0;
}
