//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findElement(vector<int> &arr) {
        // Code here
        if(arr.size()<3)return -1;
        if(is_sorted(arr.begin(),arr.end()))return arr[1];
        
        for(int i=0;i<arr.size();i++){
            int isans=arr[i];
            int gotit=1;
            if(i==0 || i==arr.size()-1)continue;
            
            for(int j=i-1;j>=0;j--){
               if(arr[j]>isans){
                   gotit=0;
                   break;
               }
            }
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<isans){
                   gotit=0;
                   break;
               }
            }
            if(gotit==1)return isans;
        }
        
        return -1;
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
        int ans = ob.findElement(arr);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends