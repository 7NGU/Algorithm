import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double threshold[];
    private final int trials;
    private final double shu = 1.96;
    private double meanVal;
    private double stddevVal;

    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) throw new IllegalArgumentException();
        this.trials = trials;
        threshold = new double[trials];
        for (int i = 1; i <= trials; i++) {          //试验次数循环
            Percolation per = new Percolation(n);
            while (per.percolates() == false) {      //循环直到渗透
                int r = StdRandom.uniform(n) + 1;    //生成随机坐标
                int c = StdRandom.uniform(n) + 1;
                per.open(r, c);                      //open选定的格子
            }
            threshold[i - 1] = (double) per.numberOfOpenSites() / (n * n);    //循环完毕后保存阈值
        }
        meanVal = StdStats.mean(threshold);
        stddevVal = StdStats.stddev(threshold);
    }

    public double mean() {                           //计算各次试验阈值的均值
        return meanVal;
    }

    public double stddev() {                         //计算标准差
        return stddevVal;
    }

    public double confidenceLo() {
        return meanVal - shu * stddevVal / Math.sqrt(trials);
    }

    public double confidenceHi() {
        return meanVal + shu * stddevVal / Math.sqrt(trials);
    }

    public static void main(String[] args) {   //主程序
        int n = StdIn.readInt();       //输入一个n和试验次数T
        int T = StdIn.readInt();
        PercolationStats m = new PercolationStats(n, T);
        System.out.println(m.mean());
        System.out.println(m.stddev());
        System.out.println(m.confidenceLo());
        System.out.println(m.confidenceHi());
    }
}
