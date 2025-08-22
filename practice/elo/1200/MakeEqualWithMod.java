package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1656/C

public class MakeEqualWithMod {
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
        int[] an = new int[n];

        boolean one = false;

        for (int i = 0; i < n; i++) {
            int next = reader.nextInt();
            an[i] = next;
            if (next == 1) {
                one = true;
            }
        }

        if (!one) {
            System.out.println("YES");
            return;
        }

        Arrays.sort(an);

        for (int i = 0; i < n - 1; i++) {
            if (an[i + 1] - an[i] == 1) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");

    }
}