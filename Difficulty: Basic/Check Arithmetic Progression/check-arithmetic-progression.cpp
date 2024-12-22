//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkIsAP(vector<int> &arr) {
        // Your code goes here
        
        // if(arr.size()<=2)return true;
        
        // int min=INT_MAX,min2=INT_MAX;
        // for(int i=0;i<arr.size();i++){
        //     if(min>arr[i]){
        //         min=arr[i];
        //     }
        // }
        
        // for(int i=0;i<arr.size();i++){
        //     if(min2>arr[i] && min2!=min){
        //         min2=arr[i];
        //     }
        // }
        
        // int diff=abs(min-min2);
        
        //  for(int i=0;i<arr.size()-1;i++){
        //     if(abs(arr[i]-arr[i+1])%diff!=0){
        //         return false;
        //     }
        //  }
         
        //  return true;
        
        sort(arr.begin(),arr.end());
        // int n=arr.size();
        int diff=arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
            
            if(arr[i+1]-arr[i]!=diff){                return false;
            }
        }
        return true;
        
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
        Solution ob;
        bool ans = ob.checkIsAP(arr);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends