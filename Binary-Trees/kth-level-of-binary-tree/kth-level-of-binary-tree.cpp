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

void kthlevel(Node* root, int k )
{

    if(root==NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<root->data<<" ";
    }

    kthlevel(root->left, k-1);
    kthlevel(root->right, k-1);



}

int main()
{

    vector<int> preOrderSequence = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrderSequence);

    kthlevel(root, 3);

    

    

}