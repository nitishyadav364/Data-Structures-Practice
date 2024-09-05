//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    int fractional_node(struct Node *head, int k) {
          if(head==NULL){
            return -1;
        }
        Node*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        count--;
        count=ceil(count/k);
        
        temp=head;
        while(count--){
            temp=temp->next;
        }
        return temp->data;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        int res = ob.fractional_node(head, k);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends