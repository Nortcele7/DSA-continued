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



void rootPath(Node* root, string path, vector<string>& path_vector)
{

    if(root->left == NULL && root->right == NULL)
    {
        path_vector.push_back(path);
    }

    if(root->left)
    {
        rootPath(root->left, path+"->"+to_string(root->left->data), path_vector);
    }

    if(root->right)
    {
        rootPath(root->right, path+"->"+to_string(root->right->data), path_vector);
    }


}



int main()
{

    vector<int> preOrderSequence = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preOrderSequence);

    string path = to_string(root->data);

    vector<string> path_vector;

    rootPath(root, path, path_vector);

    for(int i=0; i<path_vector.size(); i++)
    {
        cout<<path_vector[i]<<endl;
    }


    

}