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

struct BinomialNode 
{
    int data;
    int degree;
    BinomialNode* child;
    BinomialNode* sibling;
    BinomialNode* parent;

    BinomialNode(int val) 
    {
        data = val;
        degree = 0;
        child = NULL;
        sibling = NULL;
        parent = NULL;
    }
};

//Insert Node in BST
Node* insert(Node* root, int value)
{
    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

//Inorder Traversal
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//Preorder Traversal
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal
void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//Search Key in BST
Node* search(Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

//Find Minimum in BST
Node* findMin(Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

//Find Maximum in BST
Node* findMax(Node* root)
{
    while(root->right != NULL)
        root = root->right;

    return root;
}

//Delete Node from BST
Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

BinomialNode* mergeBinomialTrees(BinomialNode* b1, BinomialNode* b2) 
{
    if (b1->data < b2->data) 
    {
        swap(b1, b2);
    }
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;
    
    return b1;
}

//Merging of Binomial Tree
void mergeHeaps()
{
    cout << "\n--- Binomial Tree Merging Operation ---\n";
    
    // Creating two Binomial Trees of order 0 (Single Nodes)
    BinomialNode* tree1 = new BinomialNode(40);
    BinomialNode* tree2 = new BinomialNode(50);
    
    cout << "Tree 1 Root Value (Order 0): " << tree1->data << endl;
    cout << "Tree 2 Root Value (Order 0): " << tree2->data << endl;
    
    // Merging the two order 0 trees into one order 1 tree
    BinomialNode* mergedRoot = mergeBinomialTrees(tree1, tree2);
    
    cout << "\nSuccessfully merged into a Binomial Tree of Order 1!\n";
    cout << "New Parent Root Value : " << mergedRoot->data << endl;
    cout << "Leftmost Child Value  : " << mergedRoot->child->data << endl;
    cout << "Combined Tree Degree  : " << mergedRoot->degree << endl;
}

int main()
{
    Node* root = NULL;
    root = insert(root, 43);
    root = insert(root, 10);
    root = insert(root, 79);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 54);
    root = insert(root, 90);

    int choice, value;

    do
    {
        cout << "\n===== TREE OPERATIONS =====\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Merge Binomial Tree\n";
        cout << "5. Search Key\n";
        cout << "6. Insert Node\n";
        cout << "7. Find Maximum\n";
        cout << "8. Find Minimum\n";
        cout << "9. Delete Node\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 4:
                mergeHeaps();
                break;

            case 5:
                cout << "Enter key to search: ";
                cin >> value;

                if(search(root, value))
                    cout << "Key Found\n";
                else
                    cout << "Key Not Found\n";

                break;

            case 6:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Node Inserted\n";
                break;

            case 7:
                if (root == NULL) {
                    cout << "Tree is currently empty!\n";
                } else {
                    cout << "Maximum Value = " << findMax(root)->data << endl;
                }
                break;

            case 8:
                if (root == NULL) {
                    cout << "Tree is currently empty!\n";
                } else {
                    cout << "Minimum Value = " << findMin(root)->data << endl;
                }
                break;

            case 9:
                if (root == NULL) {
                    cout << "Tree is empty. Nothing to delete.\n";
                } else {
                    cout << "Enter value to delete: ";
                    cin >> value;
                    root = deleteNode(root, value);
                    cout << "Node Operation Completed\n";
                }
                break;

            case 0:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 0);

    return 0;
}