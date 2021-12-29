import java.util.ArrayDeque;
import java.util.Deque;

public class Board {

    private int[][] board;
    private final int n;

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {
        if (tiles == null) {
            throw new IllegalArgumentException();
        }
        this.n = tiles.length;
        this.board = new int[n][n];
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                board[row][col] = tiles[row][col];
            }
        }

    }
                                           
    // string representation of this board
    public String toString() {
        StringBuilder tileString = new StringBuilder();
        tileString.append(n);
        for (int[] row : this.board) {
            for (int num : row) {
                if (num < 10) {
                    tileString.append(" ").append(num).append(" ");
                } else {
                    tileString.append(num).append(" ");
                }
                tileString.append("\n");
            }
        }
        return tileString.toString();
    }

    // board dimension n
    public int dimension() {
        return this.n;
    }

    // number of tiles out of place
    // The Hamming distance betweeen a board and the goal board
    // is the number of tiles in the wrong position
    public int hamming() {
        int hammingDistance = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (this.board[row][col] != 0 && this.board[row][col] != n * row + col + 1) {
                    hammingDistance++;
                }
            }
        }
        return hammingDistance;
    }

    // sum of Manhattan distances between tiles and goal
    // sum of the vertical and horizontal distance
    public int manhattan() {
        int manhattanSum = 0;
        int goalRow, goalCol;
        for (int row = 0; row < n; row++)
            for (int col = 0; col < n; col++)
                if (board[row][col] != 0 && board[row][col] != (row * n) + col + 1) {
                    goalRow = board[row][col] % n == 0 ? (board[row][col] / n) - 1 : (board[row][col] / n);
                    goalCol = board[row][col] % n - 1;
                    manhattanSum += Math.abs(goalRow - row);
                    manhattanSum += Math.abs(goalCol - col);
                }
        return manhattanSum;
    }

    // is this board the goal board?
    public boolean isGoal() {
        return hamming() == 0 || manhattan() == 0;
    }

    // does this board equal y?
    public boolean equals(Object y) {
        if (y == null) return false;
        return toString().equals(y.toString());
    }

    // all neighboring boards
    public Iterable<Board> neighbors(){
        Deque<Board> neighbours = new ArrayDeque<>();
        int position = blankPosition();
        int i = position / this.n;
        int j = position % this.n;
        if (i > 0)
            // 与上方交换
            neighbours.push(new Board(swap(i, j, i - 1, j)));
        if (i < this.n - 1)
            // 与下方交换
            neighbours.push(new Board(swap(i, j, i + 1, j)));
        if (j > 0)
            // 与左边交换
            neighbours.push(new Board(swap(i, j, i, j - 1)));
        if (j < this.n - 1)
            // 与右边交换
            neighbours.push(new Board(swap(i, j, i, j + 1)));

        return neighbours;
    }

    // a board that is obtained by exchanging any pair of tiles
    // 如果第一行前两个不为0，交换第一行前两个。否则交换第二行前两个。
    public Board twin() {
        int[][] twinTiles = copy(this.board);

        if (twinTiles[0][0] != 0 && twinTiles[0][1] != 0)
            return new Board(swap(0, 0, 0, 1));
        else
            return new Board(swap(1, 0, 1, 1));
    }

    // unit testing (not graded)
    public static void main(String[] args) {
        Board board = new Board(new int[][]{{1, 2, 3}, {4, 0, 6}, {7, 8, 5}});
        System.out.println(board.toString());
        for (Board board1 : board.neighbors()) {
            System.out.println(board1);
        }
    }

    // 以下为自定义
    private int[][] copy(int[][] blocks) {
        int[][] copy = new int[blocks.length][blocks.length];
        for (int i = 0; i < blocks.length; i++) {
            for (int j = 0; j < blocks.length; j++) {
                copy[i][j] = blocks[i][j];
            }
        }
        return copy;
    }

    private int blankPosition() {
        for (int i = 0; i < this.n; i++)
            for (int j = 0; j < this.n; j++)
                if (this.board[i][j] == 0)
                    return j + i * this.n;
        return -1;
    }

    // 交换两个点位置，返回新数组
    private int[][] swap(int i1, int j1, int i2, int j2) {
        int[][] copy = copy(this.board);
        int temp = copy[i1][j1];
        copy[i1][j1] = copy[i2][j2];
        copy[i2][j2] = temp;
        return copy;
    }
}
