//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node* MergeSortedLL(Node* &node1,Node* &node2){
        Node* head=NULL;
        Node* curr=NULL;
        if(!node1) return node2;
        if(!node2) return node1;
        if(node1->data<=node2->data){
                     head=node1;
                     node1=node1->bottom;
            }
            else{
                 head=node2;
                 node2=node2->bottom;
            }
        curr=head;
        while(node1&&node2){
            if(node1->data<=node2->data){
                    curr->bottom=node1;
                    node1=node1->bottom;
            }
            else{
                curr->bottom=node2;
                node2=node2->bottom;
            }
            curr=curr->bottom;
        }
        if(node1){
            curr->bottom=node1;
        }
        else{
            curr->bottom=node2;
        }
        return head;
    }
Node *flatten(Node *root)
{
   if(!root ) return NULL;
   Node*nextNode= flatten(root->next);
   Node*sortedLL=MergeSortedLL(root,nextNode);
   return sortedLL;
}

