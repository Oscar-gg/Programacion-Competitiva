import java.util.*;
import java.io.*;
import java.math.BigInteger;

// Code by: @Oscar-gg

// Wrong approach to the problem; yields wrong answers.

public class B1_Fail {
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

    static long[] memo;

    public static void main(String[] args) {

        // final long startTime = System.currentTimeMillis();
        FastReader reader = new FastReader();

        int cases = reader.nextInt();

        for (int i = 1; i <= cases; i++) {
            String s = String.format("Case #%d: ", i);
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

        int[][] trees = new int[n][2];

        long averagex = 0;
        long averagey = 0;

        for (int i = 0; i < n; i++) {
            int currx = reader.nextInt();
            int curry = reader.nextInt();

            averagex += currx;
            averagey += curry;

            trees[i][0] = currx;
            trees[i][1] = curry;
        }

        averagex /= n;
        averagey /= n;

        int q = reader.nextInt();

        BigInteger sum = BigInteger.ZERO;
        int difference = 0;

        for (int i = 0; i < q; i++) {
            int xi = reader.nextInt();
            int yi = reader.nextInt();

            difference = (int) Math.abs(xi - averagex);

            if (difference != 0) {
                sum = sum.add(BigInteger.valueOf(difference).multiply(BigInteger.valueOf(n)).pow(2));
            } else {
                BigInteger temp = BigInteger.ZERO;
                for (int y = 0; y < trees.length; y++) {
                    temp = temp.add(BigInteger.valueOf(Math.abs(trees[y][0] - xi)).pow(2));
                }
                sum = sum.add(temp);
                sum = sum.mod(BigInteger.valueOf(1000000007));
            }

            difference = (int) Math.abs(yi - averagey);

            if (difference != 0) {
                sum = sum.add(BigInteger.valueOf(difference).multiply(BigInteger.valueOf(n)).pow(2));
            } else {
                BigInteger temp = BigInteger.ZERO;
                for (int y = 0; y < trees.length; y++) {
                    temp = temp.add(BigInteger.valueOf(Math.abs(trees[y][1] - yi)).pow(2));
                }
                sum = sum.add(temp);
                sum = sum.mod(BigInteger.valueOf(1000000007));
                continue;
            }

            sum = sum.mod(BigInteger.valueOf(1000000007));
        }

        System.out.println(sum);

    }
}