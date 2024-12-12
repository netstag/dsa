#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    void insert(Node *root, int val)
    {
        Node *N = new Node(val);
        if (root == NULL)
        {
            root = N;
            cout << "Element successfully inserted" << endl;
        }
        else if (root->val > val)
        { // go left
            if (root->left == NULL)
            {
                root->left = N;
                cout << "Element successfully inserted" << endl;
            }
            else
            {
                insert(root->left, val);
            }
        }
        else
        { // go right
            if (root->right == NULL)
            {
                root->right = N;
                cout << "Element successfully inserted" << endl;
            }
            else
            {
                insert(root->right, val);
            }
        }
    }

    void display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }

    Node *Search(Node *root, int key)
    {
        if (root == NULL)
        {

            return NULL;
        }
        else if (root->val == key)
        {
            cout << endl;
            cout << "Key found!" << endl;
            return root;
        }
        else if (root->val > key)
        { // go left
            return Search(root->left, key);
        }
        else
        {
            return Search(root->right, key);
        }
    }

    Node *inorderpredecessor(Node *root) // helper function for delete
    {
        Node *pred = root->left;
        while (pred->right != NULL)
        {
            pred = pred->right;
        }
        return pred;
    }
    Node *deleteNode(Node *&root, int key)
    {
        // after deleting a particular node sturucture of bst should be maintained
 if (root == NULL) {
        return NULL;
    }

    if (root->val == key) { // Node to delete found
        if (root->left == NULL && root->right == NULL) { // Case 1: Leaf node
            cout << "Node deleted successfully" << endl;
            delete root;
            return NULL;
        } else if (root->left == NULL || root->right == NULL) { // Case 2: One child
            Node* temp;
            if (root->left != NULL) {
                temp = root->left;
            } else {
                temp = root->right;
            }
            cout << "Node deleted successfully" << endl;
            delete root;
            return temp;
        } else { // Case 3: Two children
            Node *pred = inorderpredecessor(root);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val); // Remove the predecessor node
        }
    } else if (root->val > key) { // Go left
        root->left = deleteNode(root->left, key);
    } else { // Go right
        root->right = deleteNode(root->right, key);
    }
    return root;
    }
    void DepthOfTree(Node* root ){
        

    }
};
int main()
{
    BST b1;
    Node *root = new Node(10);
    b1.insert(root, 1);
    b1.insert(root, 2);
    b1.insert(root, 3);
    b1.insert(root, 11);
    b1.insert(root, 12);
    b1.insert(root, 34);
    b1.insert(root, 7);
    b1.display(root);
    b1.Search(root, 222);
    b1.deleteNode(root, 2);
    b1.display(root);
}