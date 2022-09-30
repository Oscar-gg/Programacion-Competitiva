package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1734/C

// Solved with editorial*

public class RemovingSmallestMultiple {

    int[] primes;

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
        // getPrimes();

        for (int i = 0; i < t; i++) {
            solve(reader);
        }

    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();

        char[] in = reader.next().toCharArray();

        long count = 0;

        for (int i = 0; i < in.length; i++) {
            if (in[i] == '1') {
                continue;
            }
            for (int x = i; x < in.length; x += (i + 1)) {
                if (in[x] == '0') {
                    count += i + 1;
                    in[x] = '\u0000';
                } else if (in[x] == '1') {
                    break;
                }
            }
        }

        System.out.println(count);

    }
}
