import java.util.*;
import java.io.*;
import java.math.BigInteger;

// Code by: @Oscar-gg

// Solved some cases correctly. 
// Time complexity: O(n^2); couldn't solve case with N and Q = 500,000. 

public class B1Backup {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("valB1.txt"));
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

    static long[] memo;

    public static void main(String[] args) {

        // final long startTime = System.currentTimeMillis();
        FastReader reader = new FastReader();

        int cases = reader.nextInt();

        for (int i = 1; i <= cases; i++) {
            String s = String.format("Case #%d ", i);
            System.out.print(s);
            solve(reader);
        }

        /*
         * final long endTime = System.currentTimeMillis();
         * System.out.println("Total execution time: " + (endTime-startTime));
         */
    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();

        System.out.print("(N: " + n);
        int[][] trees = new int[n][2];

        for (int i = 0; i < n; i++) {
            trees[i][0] = reader.nextInt();
            trees[i][1] = reader.nextInt();
        }
        memo = new long[3001];

        int q = reader.nextInt();
        System.out.print(", Q: " + q + "): ");
        
        BigInteger sum = BigInteger.ZERO;

        for (int i = 0; i < q; i++) {
            int xi = reader.nextInt();
            int yi = reader.nextInt();

            for (int x = 0; x < trees.length; x++) {

                int difference = Math.abs(trees[x][0] - xi);
                if (memo[difference] != 0) {
                    sum = sum.add(BigInteger.valueOf(memo[difference]));
                } else {
                    memo[difference] = (long) BigInteger.valueOf(difference).pow(2).longValue();
                    sum = sum.add(BigInteger.valueOf(memo[difference]));
                }

                difference = Math.abs(trees[x][1] - yi);

                if (memo[difference] != 0) {
                    sum = sum.add(BigInteger.valueOf(memo[difference]));
                } else {
                    memo[difference] = (long) BigInteger.valueOf(difference).pow(2).longValue();
                    sum = sum.add(BigInteger.valueOf(memo[difference]));
                }
            }
            sum = sum.mod(BigInteger.valueOf(1000000007));
        }

        System.out.println(sum);
    }
}