
#include <iostream>
using namespace std;

// TBST

class Node
{
public:
    int data;
    Node *left, *right;
    int lbit, rbit; // 0 == thread // 1 == pointer

    Node(int value)
    {
        data = value;
        left = right = nullptr;
        lbit = rbit = 0;
    }
};

class ThreadedBST
{
public:
    Node *root;
    Node *dummy;

    ThreadedBST()
    {
        root = nullptr;
        dummy = new Node(999); // Sentinel node
        dummy->left = dummy;
        dummy->right = dummy;
        dummy->lbit = 0; // No left child initially
        dummy->rbit = 1; // Points to itself
    }

    void insert(Node *root, Node *temp)
    {
        if (temp->data < root->data)
        { // go left
            if (root->lbit == 0)
            {
                temp->left = root->left;// thread
                root->left = temp;  
                temp->right = root; // thread
                root->lbit = 1;
            }
            else
            {
                insert(root->left, temp);
            }
        }
        else if (temp->data > root->data)
        { // go right
            if (root->rbit == 0)
            {
                temp->right = root->right;
                root->right = temp; // thread
                temp->left = root;  // thread
                root->rbit = 1;
            }
            else
            {
                insert(root->right, temp);
            }
        }
    }

    void create(int val)
    {
        Node *temp = new Node(val);

        if (root == NULL)
        {
            root = temp;
            dummy->left = root;
            dummy->lbit = 1; // Indicates root exists
            root->left = dummy;
            root->right = dummy;
        }
        else
        {
            insert(root, temp);
        }
    }

    void inOrder(Node *dummy)
    {
        Node *temp = dummy->left; // Start with the root

        while (temp != dummy)
        {
            // Go to the leftmost node
            while (temp->lbit == 1)
            {
                temp = temp->left;
            }

            cout << temp->data << " ";

            // Follow threads if present
            while (temp->rbit == 0)
            {
                temp = temp->right;
                if (temp == dummy)
                    return;
                cout << temp->data << " ";
            }

            // Move to the right subtree
            temp = temp->right;
        }
    }
};

int main()
{
    ThreadedBST T;
    T.create(1);
    T.create(3);
    T.create(2);
    T.create(7);
    T.create(14);
    T.create(17);
    T.inOrder(T.dummy);
}
