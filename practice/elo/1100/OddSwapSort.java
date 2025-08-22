package SolvedProblems.Easy.Elo1100;

import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1638/B

public class OddSwapSort {
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
        int cases = reader.nextInt();
        for (int i = 0; i < cases; i++) {
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();

        if (n == 1) {
            reader.nextInt();
            System.out.println("Yes");
            return;
        }

        int lasteven = -1;
        int lastodd = -1;

        for (int i = 0; i < n; i++) {
            int next = reader.nextInt();

            if (next % 2 == 0) {
                if (next >= lasteven) {
                    lasteven = next;
                } else {
                    System.out.println("No");
                    finishR(reader, i, n);
                    return;
                }
            } else {
                if (next >= lastodd) {
                    lastodd = next;
                } else {
                    System.out.println("No");
                    finishR(reader, i, n);
                    return;
                }
            }
        }

        System.out.println("Yes");

        /*
         * int[] ni = new int[n];
         * 
         * for(int i = 0; i < n; i++){
         * ni[i] = reader.nextInt();
         * }
         * 
         * for (int i = 1; i < n; i++) {
         * if (ni[i - 1] > ni[i]) {
         * if (!swapper(ni, i)) {
         * return;
         * }
         * }
         * }
         * 
         * System.out.println("Yes");
         */
    }

    public static void finishR(FastReader r, int l, int h) {
        for (; l < h - 1; l++) {
            r.nextInt();
        }
    }

}

/*
 * 
 * Brute force approach (failed due to memory limit exceeded):
 * 
 * int[] ni = new int[n];
 * 
 * for(int i = 0; i < n; i++){
 * ni[i] = reader.nextInt();
 * }
 * 
 * for (int i = 1; i < n; i++) {
 * if (ni[i - 1] > ni[i]) {
 * if (!swapper(ni, i)) {
 * return;
 * }
 * }
 * }
 * 
 * System.out.println("Yes");
 * 
 * public static boolean swapper(int[] ni, int i) {
 * 
 * while (i > 0 && ni[i - 1] > ni[i]) {
 * if (((ni[i - 1] + ni[i]) % 2) == 0) {
 * System.out.println("No");
 * return false;
 * } else {
 * int temp = ni[i - 1];
 * ni[i - 1] = ni[i];
 * ni[i] = temp;
 * i--;
 * }
 * }
 * return true;
 * }
 * 
 * 
 * public static boolean swapper(int[] ni, int i) {
 * 
 * while (i > 0 && ni[i - 1] > ni[i]) {
 * if (((ni[i - 1] + ni[i]) % 2) == 0) {
 * System.out.println("No");
 * return false;
 * } else {
 * int temp = ni[i - 1];
 * ni[i - 1] = ni[i];
 * ni[i] = temp;
 * i--;
 * }
 * }
 * return true;
 * }
 */