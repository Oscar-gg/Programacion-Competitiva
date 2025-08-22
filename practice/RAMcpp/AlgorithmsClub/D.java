package SolvedProblems.Easy.AlgorithmsClub;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class D {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("glass_greenhouse_input.txt"));
                PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
                System.setOut(out);
            } catch (Exception e) {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    // end of fast i/o code

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int t = reader.nextInt();

        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {

        Point t = new Point();
        t.x = reader.nextInt();
        t.y = reader.nextInt();

        Point[] c = new Point[3];

        for (int i = 0; i < 3; i++) {
            c[i] = new Point();
            c[i].x = reader.nextInt();
            c[i].y = reader.nextInt();
        }

        if (isInside(c[0], c[1], c[2], t)) {
            System.out.println("IN");
        } else {
            System.out.println("OUT");
        }

    }

    public static boolean isInside(Point a, Point b, Point c, Point t) {
        double area = getArea(a, b, c);

        double a1, a2, a3;
        a1 = getArea(a, b, t);
        a2 = getArea(a, t, c);
        a3 = getArea(t, b, c);

        return area == (a1 + a2 + a3);
    }

    public static double getArea(Point a, Point b, Point c) {
        return (Math.abs(a.x * (b.y - c.y) + b.x * (c.y - a.y)
                + c.x * (a.y - b.y)) / 2.0);
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        Point() {

        }
    }
}