package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1553/C

public class Penalty {
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
        String line = reader.nextLine();
        String[] bestCases = new String[2];

        StringBuilder t1 = new StringBuilder(), t2 = new StringBuilder();

        for (int i = 0; i < 10; i++) {
            char curr = line.charAt(i);
            if (curr == '1' || curr == '0') {
                t1.append(curr);
                t2.append(curr);
                continue;
            }

            if (i % 2 == 0) {
                t1.append(1);
                t2.append(0);
            } else {
                t1.append(0);
                t2.append(1);
            }
        }

        bestCases[0] = t1.toString();
        bestCases[1] = t2.toString();

        int[] c1 = new int[2];
        int[] c2 = new int[2];

        int i;

        for (i = 0; i < 10; i++) {
            char currt1 = bestCases[0].charAt(i);
            char currt2 = bestCases[1].charAt(i);

            if (i % 2 == 0) {
                c1[0] += (currt1 == '1') ? 1 : 0;
                c2[0] += (currt2 == '1') ? 1 : 0;
            } else {
                c1[1] += (currt1 == '1') ? 1 : 0;
                c2[1] += (currt2 == '1') ? 1 : 0;
            }

            if (c1[0] > (c1[1] + (5 - Math.ceil(i / 2.0)))) {
                i++;
                break;
            }

            if (c2[1] > (c2[0] + (5 - Math.ceil((i + 1) / 2.0)))) {
                i++;
                break;
            }

        }

        System.out.println(i);
    }
}