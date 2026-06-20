#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left=right=NULL;
        }
};

static int idx = -1;

Node* buildTree(vector<int>& preOrder)
{
    idx++;

    if(idx >= preOrder.size())   // ⭐ FIX
        return NULL;

    if(preOrder[idx]==-1)
    {
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

void printPreOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}


void printLevelOrder(Node* root)
{
    queue<Node*> q1;

    q1.push(root);
    q1.push(NULL);

    while(!q1.empty())
    {
        Node* curr = q1.front();
        q1.pop();

        if(curr==NULL)
        {
            cout<<endl;

            if(!q1.empty())
            {
                q1.push(NULL);
            }

        }

        else
        {

            cout<<curr->data<<" ";
            if(curr->left!=NULL)
            {
                q1.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q1.push(curr->right);
            }
    }
    }
}

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    if(leftHeight==-1)
    {
        return -1;
    }
    int rightHeight = height(root->right);
    if(rightHeight==-1)
    {
        return -1;
    }
    int diff = abs(leftHeight-rightHeight);
    if(diff>1)
    {
        return -1;
    }
    return (max(leftHeight, rightHeight) + 1);
}

int main()
{
    // vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> preOrder = {1, 2, -1, 3, -1, 4, -1};

    Node* root = buildTree(preOrder);

    printPreOrder(root);

    cout<<endl;

    printInOrder(root);

    cout<<endl;

    printPostOrder(root);

    cout<<endl;

    printLevelOrder(root);

    cout<<endl;

    cout<<height(root);





}