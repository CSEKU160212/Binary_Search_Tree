/* **********Md. Abdul Lotif********************** */

#include <bits/stdc++.h>

using namespace std;

struct BSTnode
{
    int data;
    BSTnode *leftptr;
    BSTnode *rightptr;
};
BSTnode* createNewNode(int value); //Function prototype
BSTnode* insertNode(BSTnode *root, int value);  // Function prototype
bool searchFromTree(BSTnode *root,int value);  //Function prototype

int main()
{
    BSTnode *root;  //declare root pointer
    root=NULL;     // assign root = NULL
    int n, nodeData;  // Variable Declaration
    cout << "Enter the total number of node:" << endl;
    cin>>n;
    cout<<"Enter "<<n<<" data one by one: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>nodeData;
        root=insertNode(root, nodeData);
    }

    int sData;
    cout<<"Enter a data for searching"<<endl;
    cin>>sData;
    if(searchFromTree(root, sData) == true)
    {
        cout<<"Found the data"<<endl;
    }
    else
    {
        cout<<"Data not found !!!!!"<<endl;
    }
    return 0;
}

//function for creating new nod
BSTnode* createNewNode(int value)
{
    BSTnode *newNode= new BSTnode();
    newNode->data=value;
    newNode->leftptr=NULL;
    newNode->rightptr=NULL;
    return newNode;
}


//function for insert new node
BSTnode* insertNode(BSTnode *root, int value)
{
    if(root==NULL)
    {
        root=createNewNode(value);
    }

    else if(value<=root->data)
    {
        root->leftptr=insertNode(root->leftptr, value);
    }
    else
    {
        root->rightptr=insertNode(root->rightptr, value);
    }
    return root;
}

//function for searching node
bool searchFromTree(BSTnode *root, int value)
{
    if(root==NULL)
    {
        return false;
    }
    else if (root->data==value)
    {
        return true;
    }
    else if(value<=root->data)
    {
        return searchFromTree(root->leftptr, value);
    }

    else
    {
        return searchFromTree(root->rightptr, value);
    }

}
