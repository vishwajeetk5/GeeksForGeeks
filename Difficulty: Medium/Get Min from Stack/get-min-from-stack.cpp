//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    stack<int> ms;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           return s.empty()? -1: ms.top();
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty())return -1;
           
           int x = s.top();
            s.pop();
            if (!ms.empty() && x == ms.top()) {
                ms.pop();
            }
            return x;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
        //   if(minEle>x)minEle=x;
           if (ms.empty() || x <= ms.top()) {
            ms.push(x);
        }
           s.push(x);
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends