//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int n){
        if(n==1)return true;
        
        for(int i =2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }
        
        return true;
        
    }
    
    int leftPrime(int val){
        while(!isPrime(val)){
            val--;
        }
        return val;
    }
    int rightPrime(int val){
        while(!isPrime(val)){
            val++;
        }
        return val;
    }
    Node *primeList(Node *head) {
        // code here
        Node *temp;
        
        temp = head;
        while(temp){
            int val = temp->val;
            int left = leftPrime(val);
            int right = rightPrime(val);
            
            if(val==1)temp->val = 2;
            else if(isPrime(val))temp->val= val;
            else if(abs(left-val) == abs(right-val))temp->val = left;
            else if(abs(left-val) > abs(right-val)) temp->val =right;
            else temp->val = left;
            
            temp = temp->next;
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends