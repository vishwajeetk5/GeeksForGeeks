//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    void insertUniq(vector<int> &res, int element) {
    if (res.empty() || res.back() != element) 
        res.push_back(element);
    
    }

    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> res;
        
        int n = a.size();
        int m = b.size();
        
        int i =0;
        int j=0;
        
        while(i<n && j<m){
            // cout<<i<<j<<"now\n";
            if(a[i]==b[j]){
                insertUniq(res,a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j]){
                insertUniq(res,b[j]);
                j++;
                
            }
            else if(a[i]<b[j]){
                insertUniq(res,a[i]);
                i++;
            }
        }
        
        while(i<n){
            insertUniq(res,a[i]);
                i++;
        }
        while(j<m){
            insertUniq(res,b[j]);
            j++;
        }
        // cout<<i<<j
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends