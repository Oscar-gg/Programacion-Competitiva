package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1496/B

public class MaxAndMex {
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
        int k = reader.nextInt();
        HashSet<Integer> ni = new HashSet<Integer>();

        int mex = Integer.MAX_VALUE, max = -1;

        for (int i = 0; i < n; i++) {
            int curr = reader.nextInt();
            if (!ni.contains(curr)) {
                ni.add(curr);
                if (curr > max) {
                    max = curr;
                }
            }
        }

        mex = newMex(ni, 0);

        if (mex > max) {
            System.out.println(ni.size() + k);
            return;
        }

        for (int i = 0; i < k; i++) {
            int add = (int) Math.ceil((max + mex) / 2.0);
            if (!ni.contains(add)) {
                ni.add(add);
                if (max < add) {
                    max = add;
                } else if (mex == add) {
                    mex = newMex(ni, add + 1);
                    if (mex > max) {
                        System.out.println(ni.size() + k - i);
                        return;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        System.out.println(ni.size());
    }

    public static int newMex(HashSet<Integer> h, int lmex) {
        for (int i = lmex; i <= h.size(); i++) {
            if (!h.contains(i)) {
                return i;
            }
        }

        return -1;
    }
}