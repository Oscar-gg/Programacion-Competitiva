package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1704/C

public class ExerciseVirus {
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
        long n = reader.nextLong();
        int m = reader.nextInt();

        int[] am = new int[m];

        for (int i = 0; i < m; i++) {
            am[i] = reader.nextInt();
        }

        if (m >= n) {
            System.out.println(m);
            return;
        } else if (m == 1) {
            if (n > 2) {
                System.out.println(2);
            } else {
                System.out.println(1);
            }
            return;
        }

        Arrays.sort(am);

        int[] l = new int[m];

        l[0] = (int) n - am[m - 1] + am[0] - 1;

        for (int x = 0; x < m - 1; x++) {
            l[x + 1] = am[x + 1] - am[x] - 1;
        }

        long safe = 0;

        Arrays.sort(l);

        int survivorsLost = 0;

        for (int i = l.length - 1; i >= 0; i--) {
            int temp = l[i] - survivorsLost;

            // In case the segment's length is 1, it doesn't loose any additional length.
            int current = (temp == 1) ? 1 : temp - 1;
            if (current <= 0)
                break;

            safe += current;
            survivorsLost += 4;
        }
        System.out.println(n - safe);
    }

}