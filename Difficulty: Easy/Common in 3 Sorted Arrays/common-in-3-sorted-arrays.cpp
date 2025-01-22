//{ Driver Code Starts
// here

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        
        vector<int> res;
        
        unordered_map<int,int> mp;
        
        for(int i =0;i< arr1.size();i++){
            mp[arr1[i]]++;
        }
        
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        // cout<<endl;
        for(int i =0;i< arr2.size();i++){
            if(mp.find(arr2[i]) != mp.end() && mp[arr2[i]]>0){
                mp[arr2[i]]=-1*mp[arr2[i]];
            }
        }
        
        for(int i =0;i< arr3.size();i++){
            if(mp.find(arr3[i])!= mp.end()){
                if(mp[arr3[i]]<0){
                    res.push_back(arr3[i]);
                    mp.erase(arr3[i]);
                }
                
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << "~\n";
    }
}
// } Driver Code Ends