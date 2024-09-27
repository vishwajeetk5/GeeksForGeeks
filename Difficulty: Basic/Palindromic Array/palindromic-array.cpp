//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
bool isPal(int n){
    int rev=0;
    int xn=n;
    
    while(n){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev==xn;
}

class Solution {
  public:
    bool PalinArray(vector<int> &arr) {
        // code here
        
        for(int i=0;i<arr.size();i++){
            if(!isPal(arr[i]))return false;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
    }

    return 0;
}

// } Driver Code Ends