//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
   
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
 queue<int> q1;
 queue<int> q2;
void QueueStack :: push(int x)
{
        if(q1.empty()&&q2.empty()) {
            q1.push(x);
        }
        else if(!q1.empty()&&q2.empty()){
            q1.push(x);
        }
        else if(q1.empty()&&!q2.empty()){
            q2.push(x);
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
         
        if(q1.empty()&&q2.empty()) {
            return -1;
        }
        else if(!q1.empty()&&q2.empty()){
            int temp;
            while(!q1.empty()&&q1.size()!=1){
                temp=q1.front();
                q1.pop();
                q2.push(temp);
            }
            temp=q1.front();
            q1.pop();
            return temp;
        }
        else if(q1.empty()&&!q2.empty()){
            int temp;
             while(!q2.empty()&&q2.size()!=1){
                 temp=q2.front();
                q2.pop();
                q1.push(temp);
            }
            temp=q2.front();
            q2.pop();
            return temp;
        } 
        return -1;
}
