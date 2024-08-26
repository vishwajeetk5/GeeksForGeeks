//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the length of longest increasing subarray
    int lenOfLongIncSubArr(vector<int> &arr) {
        // Your code goes here.
        int max=1;
        int len=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                len++;
                if(len>max){
                max=len;
                 }
            }
            else{
                len=1;
            }
        }
        return max;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.lenOfLongIncSubArr(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends