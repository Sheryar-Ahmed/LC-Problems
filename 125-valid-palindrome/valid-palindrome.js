/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let matched = s.toLowerCase().replace(/[^a-z0-9]/gi, "");
    return matched.split("").reverse().join("") == matched;
};