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

Node* binarySearchTree(Node* root, int val)
{

    if(root == NULL)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->left = binarySearchTree(root->left, val);
    }

    else
    {
        root->right = binarySearchTree(root->right, val);
    }

    return root;



}

void inOrder(Node* root, vector<int>& arr)
{

    if(root==NULL)
    {
        return;
    }

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);

}

Node* sArrayToBST(Node* root, int start, int end, vector<int>& temp)
{
    if(start>end)
    {
        return NULL;
    }

    int mid = start + (end-start)/2;

    root = new Node(temp[mid]);
    root->left = sArrayToBST(root->left, start, mid-1, temp);
    root->right = sArrayToBST(root->right, mid+1, end, temp);

    return root;
}

Node* mergeBSTs(Node* root1, Node* root2)
{
    vector<int> arr1;
    vector<int> arr2;

    vector<int> temp;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    int i=0,j=0;

    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            temp.push_back(arr1[i]);
            i++;
        }
        else
        {
            temp.push_back(arr2[j]);
            j++;
        }
    }

    while(i<arr1.size())
    {
        temp.push_back(arr1[i]);
        i++;
    }
    while(j<arr2.size())
    {
        temp.push_back(arr2[j]);
        j++;
    }

    Node* root = NULL;

    int start = 0;
    int end = temp.size()-1;

    return sArrayToBST(root, start, end, temp);

}

int main()
{

    vector<int> arr1 = {1,2,8,10};
    vector<int> arr2 = {0,3,5};

    Node* root1 = NULL;
    Node* root2 = NULL;

    for(int val: arr1)
    {
        root1 = binarySearchTree(root1, val);
    }

    for(int val: arr2)
    {
        root2 = binarySearchTree(root2, val);
    }

    Node* root = mergeBSTs(root1, root2);

    vector<int> ans;

    inOrder(root, ans);

    for(int val: ans)
    {
        cout<<val<<" ";
    }


    

}