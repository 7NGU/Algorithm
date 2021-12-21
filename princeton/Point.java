import java.util.Comparator;
import edu.princeton.cs.algs4.StdDraw;
public class Point implements Comparable<Point> {
    // x-coordinate of this point
    private final int x;
    // y-coordinate of this point
    private final int y;
    // constructs the point (x, y)
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    // draws this point
    public   void draw() {
        StdDraw.point(x,y);
    }
    // draws the line segment from this point to that point
    public   void drawTo(Point that) {
        StdDraw.line(this.x, this.y, that.x, that.y);
    }
    // string representation
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    // compare two points by y-coordinates, breaking ties by x-coordinates  
    public  int compareTo(Point that) {
        if(y<that.y || (y==that.y && x<that.x)) return -1;
        else if(y==that.y && x==that.x) return 0;
        else return +1;
    }
    // the slope between this point and that point
    public  double slopeTo(Point that) {//求斜率
        if(x==that.x && y==that.y) return Double.NEGATIVE_INFINITY;
        if(x==that.x && y!=that.y) return Double.POSITIVE_INFINITY;
        if(y==that.y) return +0.0;
        return (double)(y-that.y)/(x-that.x);
    }
    // compare two points by slopes they make with this point
    public Comparator<Point> slopeOrder(){
        return new SlopeOrder();
    }
    //nested class
    //sort rule
    private class SlopeOrder implements Comparator<Point>{
        public int compare(Point p,Point q) {//比较斜率大小
            //p点斜率大
            if(slopeTo(p)<slopeTo(q)) return -1;
                //p点斜率小
            else if(slopeTo(p)>slopeTo(q)) return 1;
                //p,q斜率相等
            else return 0;
        }
    }

    public static void main(String[] args) {
        Point p1 = new Point(0,0);
        Point p2 = new Point(1,1);
        Point p3 = new Point(2,2);
        Point p4 = new Point(2,1);
        Point p5 = new Point(4,1);
        System.out.println("p1.compareTo(p1) is "+p1.compareTo(p2));
        System.out.println("p2.compareTo(p1) is "+p2.compareTo(p1));
        System.out.println("p1.compareTo(p1) is "+p1.compareTo(p1)+"\n");

        System.out.println("p1.slopeTo(p2) is " +p1.slopeTo(p2));
        System.out.println("p1.slopeTo(p4) is "+p1.slopeTo(p4));
        System.out.println("p1.slopeTo(p1) is "+p1.slopeTo(p1));
        System.out.println("p3.slopeTo(p4) is "+p3.slopeTo(p4));
        System.out.println("p2.slopeTo(p5) is "+p2.slopeTo(p5));
    }
}

