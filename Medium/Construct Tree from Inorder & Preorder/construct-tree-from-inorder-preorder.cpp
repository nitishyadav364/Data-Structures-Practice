//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int ind ;
    int search(int in[], int l ,int r, int val )
    {
        
        for(int i =l ;i<=r; i++ )
        {
            if(in[i]==val)
            return i ;
        }
        return -1 ;
    }
    Node* cal(int in[], int pre[], int l ,int r ) 
    {
        
        if(l>r)
        return NULL ;
        
        
        
        Node* ptr = new Node(pre[ind++]) ;
        
        if(l==r)
        {
            ptr->left =NULL ;
            ptr->right =NULL ;
            return ptr;} 
        
        int inindex = search(in , l ,r , ptr->data) ;
        ptr->left = cal(in , pre, l , inindex-1 ) ;
        ptr->right = cal(in , pre ,inindex+1, r ) ;
        
        return ptr;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        ind= 0 ;
     return  cal(in , pre ,0 , n-1 );
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends