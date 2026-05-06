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

int sum(Node* root)
{
    int leftSum, rightSum;

    if(root==NULL)
    {
        return 0;
    }

    leftSum = sum(root->left);
    rightSum = sum(root->right);
    
    return leftSum+rightSum+root->data;
}

int main()
{

    vector<int> preOrderSequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrderSequence);

    cout<<sum(root);


    

}