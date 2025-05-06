//{ Driver Code Starts
// Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => { inputString += inputStdin; });

process.stdin.on("end", (_) => {
    inputString =
        inputString.trim().split("\n").map((string) => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

/* Function to print an array */
function printArray(arr, size) {
    let i;
    let s = "";
    for (i = 0; i < size; i++) {
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let N = parseInt(readLine());
        let obj = new Solution();
        let res = obj.nthRowOfPascalTriangle(N);
        printArray(res, res.length);

        console.log("~");
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 * @param {number} n
 * @return {number[]}
 */

class Solution {
    nthRowOfPascalTriangle(n) {
        // code here
        
        if(n==1)return [1];
        
        let res=[1,1];
        n-=2;
        while(n--){
            let temp=[1];
            for(let i=0;i<res.length-1;i++){
                temp.push(res[i] + res[i+1]);
            }
            res= temp;
            res.push(1);
        }
        
        return res;
    }
}
