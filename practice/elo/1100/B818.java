package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1717/B

public class B818 {
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
        int r = reader.nextInt();
        int c = reader.nextInt();

        int rep = n / k;

        char[][] pattern = new char[k][k];

        for (int i = 0; i < pattern.length; i++) {
            for (int x = 0; x < pattern[i].length; x++) {
                pattern[i][x] = '.';
            }
        }

        while (r > k) {
            r -= k;
        }
        r -= 1;

        while (c > k) {
            c -= k;
        }

        c -= 1;

        pattern[r][c] = 'X';

        BitSet columns = new BitSet(k);

        columns.set(c);

        for (int i = 0; i < pattern.length; i++) {
            if (i == r)
                continue;
            for (int x = 0; x < pattern[i].length; x++) {
                if (columns.get(x)) {
                    continue;
                }
                columns.set(x);
                pattern[i][x] = 'X';
                break;
            }
        }

        printRepeat(pattern, rep);

    }

    public static void printRepeat(char[][] pattern, int rep) {

        for (int o = 0; o < rep; o++) {
            for (int i = 0; i < pattern.length; i++) {
                for (int x = 0; x < rep; x++) {
                    for (int y = 0; y < pattern[i].length; y++) {
                        System.out.print(pattern[i][y]);
                    }
                }
                System.out.println();
            }
        }
    }

}

/*
 * To check:
 * r = (r >= k) ? k - r % k - 1 : r - 1;
 * 
 * c = (c >= k) ? k - c % k - 1 : c - 1;
 * 
 * 
 * char[][] pattern = new char[3][3];
 * int rep = 3;
 * int l = 0;
 * 
 * for (int i = 0; i < pattern.length; i++) {
 * for (int x = 0; x < pattern[i].length; x++) {
 * pattern[i][x] = 'E';
 * }
 * }
 * 
 * printRepeat(pattern, rep);
 * 
 * 
 * 
 * 
 */