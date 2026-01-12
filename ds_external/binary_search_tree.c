/*  programiz.com

    1. Create node
    2. Insert node
    3. Inorder tree traversal
    4. freeTree()
    5. Inorder successor
    6. Delete node - 3 cases
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Create a node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *Node, int data)
{
    if (Node == NULL)
    {                           // When you reach a NULL pointer, 
        return newNode(data);   // it means you’ve found the correct position to insert the new value.
    }

    // Traverse to the correct place and insert the node
    if (data < Node->data)
    {
        Node->left = insert(Node->left, data);
    }
    else
    {
        Node->right = insert(Node->right, data);
    }
    return Node;
}

void inorder_traversal(struct Node *root)   // L-V-R
{
    if (root != NULL)
    {
        // Traverse left
        inorder_traversal(root->left);

        printf("%d -> ", root->data);

        // Traverse right
        inorder_traversal(root->right);
    }
}

// freeTree() isn’t technically mandatory if your program just exits right away,
// but it is good practice and expected in real C programs.
// The compiler will not free heap memory for you.

// freeTree() deletes a BST using postorder traversal, ensuring that child nodes 
// are freed before their parent to avoid memory leaks and dangling pointers.
void freeTree(struct Node *root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);  // L-R-V, POST-Order
    free(root);
}

void search(struct Node *root, int value){
    if(root == NULL){
        printf("Invalid value");
    }
    else if(root -> data == value){
        printf("%d is found in the BST", value);
    }
    else if(value < root -> data){
        search(root -> left, value);
    }
    else{
        search(root -> right, value);
    }
}

// Find the inorder successor
// inorder successor - the leftmost (smallest) node in its right subtree.

struct Node *minValueNode(struct Node *Node){   // we need the minimum of a particular subtree, not the whole tree.
    struct Node *current_node = Node;

    while(current_node && current_node -> left != NULL){
        current_node = current_node -> left;
    }
    return current_node;
}
// minValueNode finds the minimum in the BST and does not find the In-order successor
// minValueNode(root -> right); finds the In-order successor


struct Node *deleteNode(struct Node *root, int value){
    // Return if the tree is empty
    if(root == NULL){
        return root;
    }

    // Find the node to be deleted
    if(value < root -> data){
        root -> left = deleteNode(root -> left, value); // This line automatically connects whatever deleteNode() returns.
    }
    else if(value > root -> data){
        root -> right = deleteNode(root -> right, value);
    }

    // The case where the value matches
    else{

        // If the node is with only one child or no child
        if(root -> left == NULL){
            struct Node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            struct Node *temp = root -> left;
            free(root);
            return temp;
        }

        // CASE 3 : If the node has two children
        struct Node *temp = minValueNode(root -> right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        // Place the inorder successor in place of 
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    printf("\nInorder traversal:\n");
    inorder_traversal(root);

    printf("\n\nSearching for a value in a BST: ");
    search(root, 14);
    printf("\n\n");

    //
    root = deleteNode(root, 10);
    printf("Inorder traversal after deleting 50:\n");
    inorder_traversal(root);
    printf("\n");
    //
    free(root);

    return 0;
}

// Case 3 deletion is still to be completed