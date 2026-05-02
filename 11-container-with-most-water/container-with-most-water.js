/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    //  find the max number and then try to find the second maximum and so on and compare the difference we can get our results its O(n logn) solution.
    // 2nd solution, two pointer why because of the search space we need to search something
    // move to smaller one untill L < R
    // let indexed = height.map((h, i) => [h, i]);

    // // sort descending by height
    // indexed.sort((a, b) => b[0] - a[0]);

    // let max = 0;
    // let minIndex = indexed[0][1];
    // let maxIndex = indexed[0][1];

    // for (let i = 1; i < indexed.length; i++) {
    //     let [h, idx] = indexed[i];

    //     let width = Math.max(Math.abs(idx - minIndex), Math.abs(idx - maxIndex));
    //     max = Math.max(max, width * h);

    //     minIndex = Math.min(minIndex, idx);
    //     maxIndex = Math.max(maxIndex, idx);
    // }

    // return max;
    let left = 0;
    let right = height.length - 1;
    let maxArea = 0;
    while (left < right) {
        let w = right - left;
        maxArea = Math.max(maxArea, w * (Math.min(height[left], height[right])));
        if (height[left] <= height[right]) left++
        else right--
    }
    return maxArea;
};