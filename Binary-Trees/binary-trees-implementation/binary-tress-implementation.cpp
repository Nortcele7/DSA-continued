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

Node* buildTree(vector<int>& preOrderSequence)
{
    idx++;
    
    if(preOrderSequence[idx]==-1)
    {
        return NULL;
    }

    Node* root = new Node(preOrderSequence[idx]);
    root->left = buildTree(preOrderSequence);
    root->right = buildTree(preOrderSequence);

    return root;

}

// Traversal Algorithms

// Recursive Approach

// 1. PreOrder Traversal

void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// 2. InOrder Traversal

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// 3. PostOrder Traversal

void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// Iterative Approach

// Level Order Traversal

queue<Node*> q1;

void levelOrder(Node* root)
{


    q1.push(root);

    while(!q1.empty())
    {
        Node* curr = q1.front();
        cout<<curr->data<<" ";
        q1.pop();
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




int main()
{

    vector<int> preOrderSequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrderSequence);

    preOrder(root);

    cout<<endl;

    inOrder(root);

    cout<<endl;

    postOrder(root);

    cout<<endl;

    levelOrder(root);
    


   return 0; 
}