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

// Function to find maximum value
Node* findMax(Node* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

int main()
{
    Node* root = new Node(43);
    root->right = new Node(79);
    root->right->right = new Node(90);

    cout << "Maximum Value = ";
    cout << findMax(root)->data;

    return 0;
}
