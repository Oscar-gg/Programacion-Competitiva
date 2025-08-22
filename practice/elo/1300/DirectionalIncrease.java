package SolvedProblems.Easy.Elo1300;

import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1693/A

public class DirectionalIncrease {
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

        long[] a = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
        }

        long negatives = 0;
        long positives = 0;
        int index = 0;

        for (int i = n - 1; i >= 0; i--) {
            negatives += a[i];
            if (negatives > 0) {
                System.out.println("No");
                return;
            }
            positives += a[index++];
            if (positives < 0) {
                System.out.println("No");
                return;
            } else if (positives == 0) {
                for (int y = index; y < n; y++) {
                    if (a[y] != 0) {
                        System.out.println("No");
                        return;
                    }
                }
                System.out.println("Yes");
                return;

            }
        }

        System.out.println("Yes");
    }
}