import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class MirrorGrid {
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
        boolean[][] start = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            char[] row = reader.next().toCharArray();
            for (int x = 0; x < n; x++) {
                if (row[x] == '1') {
                    start[i][x] = true;
                }
            }
        }

        int totalChanges = 0;
        int pair = (n % 2 == 0) ? 0 : 1;

        for (int i = 0; i < n / 2; i++) {
            for (int x = 0; x < n / 2; x++) {
                int count1 = 0;

                if (start[i][x])
                    count1++;

                if (start[i][n / 2 + x + pair])
                    count1++;

                if (start[n / 2 + i + pair][x])
                    count1++;

                if (start[n / 2 + i + pair][n / 2 + x + pair])
                    count1++;

                if (count1 <= 2) {
                    totalChanges += count1;
                } else {
                    totalChanges += 4 - count1;
                }
                System.out.println(totalChanges);

            }
        }

        if (pair == 1) {
            for (int i = 0; i < n / 2; i++) {
                int count1 = 0;
                if (start[n / 2 + pair][i])
                    count1++;
                if (start[n / 2 + pair][n - i - 1])
                    count1++;
                if (start[i][n / 2 + pair])
                    count1++;
                if (start[n - i - 1 ][n / 2 + pair])
                    count1++;

                if (count1 <= 2) {
                    totalChanges += count1;
                } else {
                    totalChanges += 4 - count1;
                }

            }
        }

        System.out.println(totalChanges);
    }
}