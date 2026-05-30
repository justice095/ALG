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

// Function to find minimum value
Node* findMin(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

int main()
{
    Node* root = new Node(43);
    root->left = new Node(10);
    root->left->left = new Node(9);

    cout << "Minimum Value = ";
    cout << findMin(root)->data;

    return 0;
}
