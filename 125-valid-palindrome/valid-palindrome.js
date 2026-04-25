/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let req = s.toLowerCase().replace(/[^a-z0-9]/gi, "");
    // return matched.split("").reverse().join("") == matched;
    let l = 0;
    let r = req.length-1;
    while(l < r){
        if(req[l] != req[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
};