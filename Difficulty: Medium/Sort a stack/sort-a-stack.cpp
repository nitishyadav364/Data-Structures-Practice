//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertInSortedWay(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    vector<int>vec;
    while(!s.empty()&&s.top()>x){
        int temp=s.top();
        s.pop();
        vec.push_back(temp);
    }
   s.push(x);
   for(int i=vec.size()-1;i>=0;i--){
       s.push(vec[i]);
   }
    
}
void solve(stack<int>&s){
    if(s.empty()){
       return;
   }
   int x=s.top();
   s.pop();
   solve(s);
   insertInSortedWay(s,x);
}
void SortedStack :: sort()
{
   solve(s);
}