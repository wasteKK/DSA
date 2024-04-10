#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

typedef struct node* NODE;

NODE create_node(int item){
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE createTree(){
    int val;
    scanf("%d",&val);
    if(val == -1) return NULL;
    NODE temp = create_node(val);
    printf("Enter left of %d: /n",val);
    temp->left = createTree();
    printf("Enter right of %d: /n",val);
    temp->right = createTree();
    return temp;
}

NODE insert_left(NODE root, int item){
    root->left = create_node(item);
    return root->left;
}

NODE insert_right(NODE root, int item){
    root->right = create_node(item);
    return root->right;
}

void display(NODE root){
    if(root!=NULL){
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

int count_nodes(NODE root){
    if(root == NULL) return 0;
    return count_nodes(root->left)+count_nodes(root->right)+1;
}

int height(NODE root){
    if(root==NULL) return -1;
    else{
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>rh) return lh+1;
        else return rh+1;
    }
}

int leaf_count(NODE root){
    if(root == NULL) return 0;
    else if(root->left == NULL && root->right == NULL) return 1;
    else return leaf_count(root->left)+leaf_count(root->right);
}

int internal_count(NODE root){
    if(root==NULL || root->left ==NULL && root->right == NULL) return 0;
    else return internal_count(root->left)+internal_count(root->right)+1;
}

int main(){
    NODE root = NULL;
    printf("Enter root val: /n");
    root = createTree();
    // root=create_node(10);
    // insert_left(root,20);
    // insert_right(root,120);
    // insert_right(root->left,40);
    // insert_right(root->left->right,80);
    // insert_right(root->right,60);
    // insert_left(root->right->right,90);
    printf("The content of tree is:\n");
    display(root);
    printf("\n\nThe total no of nodes is: %d\n", count_nodes(root));
    printf("The height of tree is: %d\n", height(root));
    printf("The no of leaf nodes is: %d\n", leaf_count(root));
    printf("The no of internal nodes is: %d\n", internal_count(root));

}