//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    struct Job{
        int id;
        int dl;
        int profit;
        Job(int id,int dl,int profit){
            this->id = id;
            this->dl = dl;
            this->profit = profit;
        }
    };
    bool static comp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        int n = profit.size();
        int countJobs=0;
        int jobProfit=0;
        
        vector<Job> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back(Job(id[i],deadline[i],profit[i]));
        }
        
        sort(jobs.begin(),jobs.end(),comp);
        int maxdl = *max_element(deadline.begin(),deadline.end());
        
        vector<int> slotMap(maxdl+1,-1);
        for(int i =0;i<n;i++){
            for(int day = jobs[i].dl;day > 0;day --){
                if(slotMap[day]==-1){
                    slotMap[day] = jobs[i].id;
                    countJobs++;
                    jobProfit +=jobs[i].profit;
                    break;
                }
            }
        }
        
        return {countJobs,jobProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends