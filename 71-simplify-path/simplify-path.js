/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const stack = [];
    const parts = path.split('/');
    for(const dir of parts){
        if(dir == "" || dir == ".") continue;
        else if(dir === '..'){
            if(stack.length > 0) stack.pop();
        }else{
            stack.push(dir);
        }
    }

    return '/'+stack.join('/');
}; 