class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans = INT_MAX;
        for(int i=0;i<=a.size()-m;i++){
            // cout<<arr[i]<<"-"<<arr[i+m-1];
            ans = min(a[i+m-1]-a[i],ans);
        }
        return ans;
    }
};