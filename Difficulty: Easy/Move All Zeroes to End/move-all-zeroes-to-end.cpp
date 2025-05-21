// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int zeros=0;
        for(int i :arr)zeros+=(i==0);
        int nonzero=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0){
                arr[nonzero]=arr[i];
                nonzero++;
            }
        }
        for(int i=arr.size()-zeros;i<arr.size();i++){
            arr[i]=0;
        }
    }
};