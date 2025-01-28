//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string res="";
        int min_len=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i].length()<min_len){
                min_len = arr[i].length();
            }
        }
        for(int i=0;i<min_len;i++){
            char ch = arr[0][i];
            // cout<<ch<<"checking";
            for(int j=0;j<arr.size();j++){
                if(arr[j][i]!=ch)return res;
            }
            res+=ch;
        }
        
        return res;
        
    }
};
// ij0123456789
// 0 geeksforgeeks
// 1 geeks
// 2 geek
// 3 geekzer

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends