/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length != t.length) return false;
    // calculate frequencies
    let map = new Map();
    for(let x of s){
        map.set(x, ((map.get(x)) || 0 )+1);
    }
    for(let s of t){
        if(!map.has(s) || map.get(s) == 0) return false;
        map.set(s, map.get(s)-1);
    }

    return true;
    // return s.split("").sort().join("") == t.split("").sort().join("");
}