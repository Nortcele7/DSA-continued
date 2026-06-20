#include<iostream>
#include<vector>
#include<climits>
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


int height(Node* root, int& currDiam)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left, currDiam);
    int rightHeight = height(root->right, currDiam);

    currDiam = max(currDiam, leftHeight+rightHeight);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    vector<int> v = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(v);
 
    int currDiam = 0;

    height(root, currDiam);

    cout<<currDiam;

}