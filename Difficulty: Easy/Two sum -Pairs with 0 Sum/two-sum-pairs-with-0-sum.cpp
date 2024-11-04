//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        
        int count =0;
        
        set<vector<int>> st;
        unordered_map<int,int> mp;
        
        for(int i =0;i< arr.size();i++){
            // for (int j=i+1 ;j<arr.size();j++){
            //     if(arr[i]+arr[j] == 0){
            //         count++;
            //         vector<int> temp(2);
                    
            //         temp[0]=arr[i];
            //         temp[1]=arr[j];
                    
            //         st.insert(temp);
            //     }
            // }
            
            mp[arr[i]]++;
            
        }
        vector<vector<int>> res;
        
        // for(auto x:st){
        //     res.push_back(x);
        // }
        
        for(auto it:mp){
            if(it.first>0 && mp.count((it.first)*(-1)) == true){
                res.push_back({-1*(it.first),it.first});
            }
            if(it.first == 0 && it.second>1){
                res.push_back({0,0});
            }
        }
        
        sort(res.begin(),res.end(),[](vector<int> a,vector<int> b){return a[0]< b[0];});
        
        // cout<<count;
        
        
        return res;
    }
};

//{ Driver Code Starts.
//Back-end complete function Template for C++

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        // char c;cin>>c;
        Solution obj;
        vector<vector<int>> res = obj.getPairs(arr);
        if (res.size() == 0) {
            cout << endl;
        } else
            Matrix::print(res);
        cout << "~" << endl;
    }
}

// } Driver Code Ends