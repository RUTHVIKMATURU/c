#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node NODE;
NODE* insert(NODE* root, int data) {
    if (root == NULL) {
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
NODE* minValueNode(NODE* node) {
    NODE* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
NODE* deleteNode(NODE* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
        NODE* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(NODE* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(NODE* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(NODE* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
NODE* search(NODE* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    return search(root->left, key);
}
int main() {
    NODE* root = NULL;
    int choice, key;
    printf("\nBinary Search Tree Operations\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Search\n7. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("In-order traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal of the BST: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal of the BST: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key %d found\n", key);
                } else {
                    printf("Key %d not found\n", key);
                }
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=7);

    return 0;
}
