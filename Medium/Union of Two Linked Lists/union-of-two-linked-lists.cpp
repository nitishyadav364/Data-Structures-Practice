//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
     Node* getMid(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* merge(Node* head1, Node* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        
        Node* head=NULL, *tail=NULL;
        if(head1->data < head2->data){
            head=tail=head1;
            head1 = head1->next;
        }else if(head1->data > head2->data){
            head=tail=head2;
            head2 = head2->next;
        }else{
            head=tail=head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                tail->next=head1;
                tail = head1;
                head1 = head1->next;
            }else if(head1->data > head2->data){
                tail->next=head2;
                tail = head2;
                head2 = head2->next;
            }else{
                tail->next=head1;
                tail = head1;
                head1 = head1->next;
                head2 = head2->next;
            }   
        }
        
        if(head1!=NULL){
            tail->next = head1;
        }else{
            tail->next = head2;
        }
        
        return head;
    }
    
    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* mid = getMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* res = merge(left,right);
        return res;
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return merge(head1,head2);
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends