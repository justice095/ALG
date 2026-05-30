#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function for preorder traversal
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = new Node(43);
    root->left = new Node(10);
    root->right = new Node(79);

    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}
