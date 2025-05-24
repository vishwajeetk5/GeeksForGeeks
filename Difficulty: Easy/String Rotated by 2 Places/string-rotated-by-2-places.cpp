class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    string rotateClock(string s){
        if(s.length()<=2)return s;
        
        string res = "";
        for(int i=2;i<s.length();i++){
            res+=s[i];
        }
        for(int i=0;i<2;i++){
            res+=s[i];
        }
        
        return res;
    }
    
    string rotateAntiClock(string s){
        if(s.length()<=2)return s;
        int n = s.length();
        string res = "";
        for(int i=n-2;i<n;i++){
            res+=s[i];
        }
        for(int i=0;i<n-2;i++){
            res+=s[i];
        }
        return res;
    }
    
    
    bool isRotated(string& s1, string& s2) {
        // Your code here
        // cout<<rotateClock(s1)<<endl;
        // cout<<rotateAntiClock(s1);
        return (rotateClock(s1)==s2 || rotateAntiClock(s1)==s2);
    }
};
