// Problem Statement:Beginning with an empty binary search tree, Construct binary search tree by inserting the
// values in the order given. After constructing a binary tree -
// i. Insert new node,
// ii. Find number of nodes in longest path from root,
// iii. Minimum data value found in the tree,
// iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
// v. Search a value

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *create(int item)
{
    Node *node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}
Node *insertion(Node *root, int item)
{
    if (root == NULL)
        return create(item);
    if (item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int min_node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
void mirror(Node *root)
{
    if (root == NULL)
        return;
    else
    {

        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << "   ";
    inorder(root->right);
}

bool Searching(Node *root, int key)
{

    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    bool res1 = Searching(root->left, key);

    if (res1)
        return true;

    bool res2 = Searching(root->right, key);

    return res2;
}
int main()
{
    int ch, key, node;
    Node *root = NULL;
    do
    {
        cout << "\n"
             << "1.Insertion"
             << "\n";
        cout << "2.Longest path"
             << "\n";
        cout << "3.Mini data from the treee"
             << "\n";
        cout << "4.Swap the tree"
             << "\n";
        cout << "5.Search"
             << "\n";
        cout << "6.Display"
             << "\n";
        cout << "Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the node to be inserted";
            cin >> node;
            root = insertion(root, node);
            break;
        case 2:
            cout << "\n"
                 << "The Depth of the binary tree is " << height(root);
            break;
        case 3:
            cout << "\n"
                 << "The Minimum data value from the tree is:-" << min_node(root);

            break;
        case 4:
            cout << "\n"
                 << "After the swapping roots";
            mirror(root);
            inorder(root);
            break;
        case 5:
            cout << "\n"
                 << "Enter the key to be search";
            cin >> key;
            if (Searching(root, key))
            {
                cout << "Key" << key << "is found";
            }
            else
            {
                cout << "Key" << key << "is not found";
            }
            break;
        case 6:
            inorder(root);
        }
    } while (ch != 7);
    return 0;
}
