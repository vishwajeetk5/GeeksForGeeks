class Solution {
  public:
    int lessThanEqual(int x, int m, int n) {
        int count=0;
        for(int i=1; i<= m;i++){
            count += min(x/i,n);
        }
        return count;
    }
    int kthSmallest(int m, int n, int k) {
        // code here
        // vector<int> vec;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         vec.push_back(i*j);
        //     }
        // }
        
        // sort(vec.begin(),vec.end());
        // // for(int i:vec){
        // //     cout<<i<<" ";
        // // }
        // return vec[k-1];
        
         int low = 1, high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (lessThanEqual(mid, m, n) < k) {
                low = mid +1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
};
