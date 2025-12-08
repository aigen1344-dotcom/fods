#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
    struct Node *root = NULL;

struct Node *insert(struct Node *root,int data){
    if(root == NULL){
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}

void preorder(struct Node *root){
    if(root != NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}

struct Node *search(struct Node *root,int data){
    if(root == NULL || root->data == data) return root;
    if(data < root->data){
        return search(root->left,data);
    }
    else if(data > root->data){
        return search(root->right,data);
    }
}

struct Node *minVal(struct Node *node){
    while(node && node->left != NULL){
        node = node->left;
    }
    return node;
}

struct Node *delete(struct Node *root, int data){
    if(root == NULL) return root;
    if(data < root->data){
        root->left = delete(root->left,data);
    }
    else if(data > root->data){
        root->right = delete(root->right,data);
    }
    else{
        if(root->left == NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node *temp = minVal(root->right);
        root->data = temp->data;
        root->right = delete(root->right,temp->data);
    }
}
int main(){
    int data;
    int choice;
    struct Node *temp;
    while(1){
        printf("\nBinary search tree ");
        printf("\n 1.Insert element");
        printf("\n 2.Preorder traversal");
        printf("\n 3.Inorder traversal");
        printf("\n 4.Postorder traversal");
        printf("\n 5.Search element");
        printf("\n 6.Delete element");
        printf("\n 7.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d" ,&choice);

        switch(choice){
            case 1:
                printf("\n Enter data to be inserted : ");
                scanf("%d",&data);
                root = insert(root , data);
                printf("\nData entered successfully");
                break;

            case 2:
                printf("\nPreorder Traversal : ");
                preorder(root);
                break;

            case 3:
                printf("\nInorder Traversal : ");
                inorder(root);
                break;

            case 4:
                printf("\nPostorder Traversal : ");
                postorder(root);
                break;

            case 5:
                printf("\nEnter data to be searched : ");
                scanf("%d",&data);
                temp = search(root,data);
                if(temp != NULL) printf("Data %d found in tree",data);
                else printf("Data not found");
                break;
            
            case 6:
                printf("\nEnter data to be deleted : ");
                scanf("%d",&data);
                temp = search(root,data);
                if(temp != NULL){
                    root = delete(root,data);
                    printf("\nData %d deleted successfully",data);
                }
                else printf("\nData not found");
                break;

            case 7:
                printf("\nExiting program....");
                exit(0);

            default:
                printf("\nInvalid input");
        }
    }
    return 0;
}