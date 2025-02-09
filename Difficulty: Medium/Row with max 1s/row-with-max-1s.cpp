//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
int Binary_search(vector<int> &x, int size, int target) {
    int left = 0, right = size - 1;
    int firstOccurrence = size;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (x[mid] == target) {
            firstOccurrence = mid;  
            right = mid - 1;      
        } else if (x[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return firstOccurrence;
}

    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n =arr.size();
        int max1s =INT_MIN;
        int ans=-1;
        
        for(int i =0;i<n;i++){
            
            int n1s = arr[i].size() - Binary_search(arr[i],arr[i].size(),1);
            if(n1s>max1s){
                max1s=n1s;
                ans =i;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends