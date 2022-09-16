package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1547/C

public class PairProgramming {
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
        int k = reader.nextInt();
        int n = reader.nextInt();
        int m = reader.nextInt();

        int[] monoc = new int[n];
        int[] polyc = new int[m];
        int[] ans = new int[n + m];

        for (int i = 0; i < n; i++) {
            monoc[i] = reader.nextInt();
        }

        for (int i = 0; i < m; i++) {
            polyc[i] = reader.nextInt();
        }

        int im = 0, ip = 0;
        boolean print = true;

        while (im + ip < n + m) {
            if (im < monoc.length){
                if (monoc[im] == 0) {
                    ans[im + ip] = monoc[im];
                    k++;
                    im++;
                    continue;
                }
                if (monoc[im] <= k) {
                    ans[im + ip] = monoc[im];
                    im++;
                    continue;
                }
            }
            
            if (ip < polyc.length){
                if (polyc[ip] == 0) {
                    ans[im + ip] = polyc[ip];
                    k++;
                    ip++;
                    continue;
                }

                if (polyc[ip] <= k) {
                    ans[im + ip] = polyc[ip];
                    ip++;
                    continue;
                }
            }
             
            print = false;
            break;
        }

        if (print) {
            for (int i = 0; i < im + ip; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        } else {
            System.out.println("-1");
        }

    }
}