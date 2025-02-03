//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends
class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {

        // Your code here
        if(s1.size()!=s2.size())return false;
        
        unordered_map<char,char> mp;
        unordered_map<char,int> used;
        
        for(int i=0;i<s1.size();i++){
            if(mp.find(s1[i])== mp.end()  && used.find(s2[i])==used.end() ){
                //if not found
                mp[s1[i]]=s2[i];
                used[s2[i]]++;
            }
            else if(mp[s1[i]]!= s2[i]){
                
                return false;
            }
            // else return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends