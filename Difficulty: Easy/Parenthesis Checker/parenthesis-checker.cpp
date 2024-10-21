//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool ispar(string x) {
        // code here
        if(x.length()<1)return false;
        
        stack<char> stk;
        for(int i=0;i<x.length();i++){
            if(x[i]=='(' || x[i] =='[' || x[i]=='{'){
            stk.push(x[i]);
            }
            else if(stk.empty()){
                return false;
            }
            else{
                
                if(x[i]==')' && stk.top()!='('){
                        return false;
                }
                if(x[i]=='}' && stk.top()!='{'){
                        return false;
                }
                if(x[i]==']' && stk.top()!='['){
            
                        return false;
                }
                stk.pop();
            }
            }
            return stk.empty();
            
        }
        
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
// } Driver Code Ends