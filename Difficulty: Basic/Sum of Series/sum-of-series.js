//{ Driver Code Starts

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', _ => {
    inputString =
        inputString.trim().split("\n").map(string => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {

        let n = parseInt(readLine());

        let obj = new Solution();
        let res = obj.seriesSum(n);
        console.log(res);
    }
}

// } Driver Code Ends



class Solution {
    /**
    * @param number n

    * @returns number
    */
    seriesSum(n) {
        // code here
  
        const sum = (BigInt(n)*(BigInt(n)+BigInt(1)))/BigInt(2);
        return sum.toString();
    }
}
