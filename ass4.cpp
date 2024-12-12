#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *right;
    Node *left;
    Node(char data)
    {
        this->data = data;
        right = left = nullptr;
    }
};

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// ExpressionTree class for constructing and traversing the expression tree
class ExpressionTree
{
public:
    // Function to build an expression tree from a postfix expression

    Node *constructFromPostfix(string Postfix)
    {
        stack<Node *> s;
        for (int i = 0; i < Postfix.length(); i++)
        {

            Node *node = new Node(Postfix[i]);
            if (isOperator(Postfix[i]))
            {

                // Pop two nodes for operator nodes

                node->right = s.top();
                s.pop();

                node->left = s.top();
                s.pop();

                s.push(node);
            }
            else
            {
                s.push(node); // Push operand nodes directly
            }
        }
        return s.top(); // returning pointer of root node from the pointer stack
    }

    Node *constructFromPrefix(string Prefix)
    {

        stack<Node *> s;

        // reverse loop for prefix

        for (int i = Prefix.length() - 1; i >= 0; i--)
        {
            Node *node = new Node(Prefix[i]);
            if (isOperator(Prefix[i]))
            {
                node->left = s.top(); // exactly opposite of prefix
                s.pop();

                node->right = s.top();
                s.pop();

                s.push(node);
            }
            else
            {
                s.push(node);
            }
        }
        return s.top(); // Root of the constructed expression tree
    }

    void recInorder(Node *root)
    {
        if (root == NULL)
            return;
        recInorder(root->left);
        cout << root->data << " ";
        recInorder(root->right);
    }
    void recPreorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        recInorder(root->left);
        recInorder(root->right);
    }
    void recPostorder(Node *root)
    {
        if (root == NULL)
            return;
        recInorder(root->left);
        recInorder(root->right);
        cout << root->data << " ";
    }
    void ittPreorder(Node *root)
    {
        stack<Node *> st;
        if (root != NULL)
        {
            st.push(root);
        }
        while (st.size() > 0)
        {
            Node *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            if (temp->right != NULL)
            {
                st.push(temp->right);
            }
            if (temp->left != NULL)
            {
                st.push(temp->left);
            }
        }
        cout<<endl;
    }

    void ittPostorder(Node *root)
    {
        stack<Node *> st;
        stack<Node*> tempst;

        if (root != NULL)
        {
            st.push(root);
        }
        while (st.size()>0)
        {
            Node* temp = st.top();
            st.pop();
            tempst.push(temp);
            if(temp->left != NULL){
                st.push(temp->left);
            }
              if(temp->right != NULL){
                st.push(temp->right);
            }
        }

        // print that temp stack

        while(tempst.size()>0){
            cout<<tempst.top()->data<<" ";
            tempst.pop();
        }
        
    }
};
int main()
{
    ExpressionTree E;

    E.recInorder(E.constructFromPostfix("ab+"));
    cout << endl;
    E.recPostorder(E.constructFromPostfix("ab+"));
    cout << endl;
    E.recPreorder(E.constructFromPostfix("ab+"));
    cout << endl;
    
    E.ittPostorder(E.constructFromPostfix("ab+"));
}