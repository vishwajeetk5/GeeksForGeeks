//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    public:
    string encryptString(string s){
    // code here
    string res ="";
    long long count =0;
        for(int i =0;i<s.length();i++){
            count++;
            if(s[i]!=s[i+1]){
                res+=s[i]+to_string(count);
                count=0;
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
	    string s;
		cin>>s;
		Solution ob;
		string ans = ob.encryptString(s);
		cout<<ans<<endl;
	
cout << "~" << "\n";
}
}

// } Driver Code Ends