package SolvedProblems.Easy.Rounds.Round824;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class B {
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

        int min = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
            if (a[i] < min)
                min = a[i];

        }

        int operations = 0;

        if (min == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] != 1) {
                    operations += a[i] - 1;
                }
            }
            System.out.println(operations);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] >= min * 2) {
                operations += (int) Math.ceil(a[i] / (min * 2 - 1.0)) - 1;
            }
        }

        System.out.println(operations);
    }
}