#include<iostream>
#include<vector>
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

int sumTree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    root->data = root->data+sumTree(root->left)+sumTree(root->right);

    return root->data;
}

int main()
{

    vector<int> preOrderSequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrderSequence);

    preOrder(root);

    cout<<endl;

    sumTree(root);

    preOrder(root);
    

}