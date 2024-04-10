#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

typedef struct node* NODE;

void preorder(NODE root){
    if(root!=NULL){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

NODE create_node(int item){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE insertBST(NODE root, int item){
    NODE temp;
    temp = create_node(item);
    if(root == NULL) return temp;
    if(item < root->data)
        root->left = insertBST(root->left,item);
    else 
        root->right = insertBST(root->right, item);
    
    return root;
}

NODE inordersuccessor(NODE root){
    NODE cur = root;
    while(cur->left != NULL) cur = cur->left;
    
    return cur;
}

NODE deletenode(NODE root, int key){
    NODE temp;
    if(root == NULL) return root;
    if(key < root->data) 
        root->left = deletenode(root->left, key);
    else if(key > root->data)                                                                                                                                                                                                                                                                                                                                                                                                                                                           
        root->right = deletenode(root->right, key);
    else{
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int main(){
    NODE root = NULL;
    int ch, item, key;
    while(1){
        printf("\nOPERATIONS\n----------\n1. Insert\n2. Delete\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n");
        printf("Enter: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertBST(root, item);
                break;

            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                root = deletenode(root, key);
                break;

            case 3:
                printf("Preorder Traversal is:\n");
                preorder(root);
                break;
            
            case 4:
                printf("Inorder Traversal is:\n");
                inorder(root);
                break;

            case 5:
                printf("Postorder Traversal is:\n");
                postorder(root);
                break;
            
            default: exit(0);
        }
    }
}