package SolvedProblems.Easy.Elo1300;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1733/C?mobile=false

public class ParityShuffleSorting {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("input.txt"));
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

        for (int i = 0; i < t; i++) {
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();
        int[] a = new int[n];
        Pair[] p = new Pair[n];
        int index = 0;
        int m = 0;

        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
        }

        if (n == 1) {
            System.out.println(m);
            return;
        }

        if ((a[0] + a[n - 1]) % 2 == 0) {
            a[0] = a[n - 1];
        } else {
            a[n - 1] = a[0];
        }

        p[index++] = new Pair(0, n-1);

        m++;

        for (int i = 1; i < n - 1; i++) {
            if ((a[0] + a[i]) % 2 == 0) {
                p[index++] = new Pair(i, n - 1);
            } else {
                p[index++] = new Pair(0, i);
            }
            m++;
        }

        System.out.println(m);

        for (int i = 0; i < index; i++) {
            p[i].printPair();
        }

    }

    public static class Pair {
        int l;
        int r;

        public Pair(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public void printPair() {
            System.out.println((l + 1) + " " + (r + 1));
        }
    }
}
