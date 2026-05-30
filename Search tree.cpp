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

// Function to search for a value
Node* search(Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    Node* root = new Node(43);
    root->left = new Node(10);
    root->right = new Node(79);

    int key = 79;

    if(search(root, key))
        cout << "Value Found";
    else
        cout << "Value Not Found";

    return 0;
}
