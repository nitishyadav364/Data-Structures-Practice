//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
   Node* sortedMerge(Node* &head1, Node* &head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node dummy(0); // Use a dummy node to simplify merging process
    Node* temp = &dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // Attach the remaining nodes, if any
    if (head1) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    return dummy.next;
}

// Function to find the middle of the linked list.
Node* findmid(Node* &head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list.
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = findmid(head);
    Node* second = mid->next;
    mid->next = NULL;

    Node* firsthalf = mergeSort(head);
    Node* secondhalf = mergeSort(second);

    return sortedMerge(firsthalf, secondhalf);
}

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends