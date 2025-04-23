//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        vector<int> res;
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            // cout<<arr[i]<<" ";
            if(i==0){
                if(arr[i]!=arr[i+1])res.push_back(arr[i]);
            }
            else if(i==arr.size()-1){
                if(arr[i]!=arr[i-1])res.push_back(arr[i]);
            }
            else{
                if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
                    res.push_back(arr[i]);
                }
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends