// User function Template for javascript

/**
 * @param {number[]} arr
 * @return {number}
 */

class Solution {
    maxValue(arr) {
        // code here
        let ans =0;
        arr.sort((a, b) => a - b)
        for(let i=0;i<arr.length;i++){
            ans=(ans+(arr[i]*i))%1000000007
        }
        
        return ans
    }
}
