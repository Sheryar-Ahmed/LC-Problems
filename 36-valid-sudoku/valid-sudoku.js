var isValidSudoku = function (board) {
    let row = new Set();
    let col = new Set();
    let box = new Set();

    const rows = board.length;
    const cols = board[0].length;

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] !== ".") {
                const r = `row ${i} value ${board[i][j]}`;
                const c = `col ${j} value ${board[i][j]}`;
                const b = `box ${Math.floor(i / 3)}-${Math.floor(j / 3)} value ${board[i][j]}`;

                if (row.has(r) || col.has(c) || box.has(b)) {
                    return false;
                }

                row.add(r);
                col.add(c);
                box.add(b);
            }
        }
    }
    return true;
};