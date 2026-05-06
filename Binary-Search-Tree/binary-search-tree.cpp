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

bool search(Node* root, int key)
{
    
    if(root==NULL)
    {
        return false;
    }

    if(root->data == key)
    {
        return true;
    }

    if(key<root->data)
    {
        return search(root->left, key);
    }

    else
    {
        return search(root->right, key);
    }
}

Node* findIS(Node* IS)
{
    while(IS->left!=NULL)
    {
        IS = IS->left;
    }

    return IS;
}

Node* delNode(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left = delNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = delNode(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else
        {

            // Find IS
            Node* IS = findIS(root->right);

            root->data = IS->data;

            root->right = delNode(root->right, IS->data);


        }

        
    }

    return root;
}

int main()
{
    
    vector<int> arr = {3,2,1,5,6,4};

    Node* root = NULL;

    for(int val: arr)
    {
        root = binarySearchTree(root, val);
    }

    cout<<root->data<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    cout<<boolalpha;
    cout<<search(root, 4);

    cout<<endl;

    root = delNode(root, 2);

    inOrder(root);



}