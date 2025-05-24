class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        for(int i=0;i<arr.size();i++){
            swap(*min_element(arr.begin()+i,arr.end()),arr[i]);
        }
    }
};