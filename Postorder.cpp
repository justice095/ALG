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

// Function for postorder traversal
void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = new Node(43);
    root->left = new Node(10);
    root->right = new Node(79);

    cout << "Postorder Traversal: ";
    postorder(root);

    return 0;
}
