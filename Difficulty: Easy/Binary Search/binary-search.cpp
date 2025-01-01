//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(vector<int> &arr,int k) {
        // code here
        int n = arr.size();
        int i=0,j= n-1,res=-1;
        int mid;
        
        while(i<=j)
        {  mid=(i+j)/2;
            
            if(arr[mid]==k){ 
                res=mid;
            }
            if(arr[mid]<k){
                i=mid+1;
            }
            if(arr[mid]>= k){
                j=mid-1;    
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends