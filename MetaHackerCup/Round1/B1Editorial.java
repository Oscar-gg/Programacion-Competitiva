import java.util.*;
import java.io.*;
import java.math.BigInteger;

// Code by: @Oscar-gg

// Code made after reading editorial from Meta Hacker Cup.

// Veredict: Accepted
// Execution time: 400484 ms...
// Complexity: 3,000 * Q

public class B1Editorial {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("inB1Ed.txt"));
                PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
                System.setOut(out);
            } catch (Exception e) {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public FastReader(String file) {
            try {
                br = new BufferedReader(
                        new FileReader(file + ".txt"));
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

    static BigInteger mod = BigInteger.valueOf(1000000007);
    static int[] memo = new int[3001];

    public static void main(String[] args) {

        // memoPrepare();
        readMemo(memo);

        long start = System.currentTimeMillis();

        FastReader reader = new FastReader();

        int t = reader.nextInt();

        for (int i = 1; i <= t; i++) {
            String s = String.format("Case #%d:", i);
            System.out.print(s + " ");
            solve(reader);
        }

        long end = System.currentTimeMillis();

        System.out.println("Execution time: " + (end - start));

    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();
        int[] ai = new int[3001];
        int[] bi = new int[3001];

        for (int i = 0; i < n; i++) {
            int nextai = reader.nextInt();
            int nextbi = reader.nextInt();
            ai[nextai] = ai[nextai] + 1;
            bi[nextbi] = bi[nextbi] + 1;
        }

        int q = reader.nextInt();

        BigInteger sum = BigInteger.ZERO;

        for (int i = 0; i < q; i++) {
            int xi = reader.nextInt();
            int yi = reader.nextInt();

            for (int x = 0; x < ai.length; x++) {
                int diff = Math.abs(x - xi);
                if (ai[x] != 0)
                    sum = sum.add(BigInteger.valueOf(memo[diff])
                            .multiply(BigInteger.valueOf(ai[x])));

                diff = Math.abs(x - yi);

                if (bi[x] != 0)
                    sum = sum.add(BigInteger.valueOf(memo[diff])
                            .multiply(BigInteger.valueOf(bi[x])));
                sum = sum.mod(mod);
            }
        }

        System.out.println(sum);

    }

    // Makes a txt file with all precomputed values of all possible differences
    // between ai, xi, bi, and yi.

    // Format: file with squares of numbers from 0 to 3000, separated by white
    // spaces.
    public static void memoPrepare() {
        try {
            PrintStream out = new PrintStream(new FileOutputStream("memo.txt"));
            System.setOut(out);
        } catch (Exception e) {
        }

        for (int i = 0; i < 3001; i++) {
            System.out.print((i * i) + " ");
        }
    }

    public static void readMemo(int[] squares) {
        FastReader reader = new FastReader("memo");
        for (int i = 0; i < squares.length; i++) {
            squares[i] = reader.nextInt();
        }
    }

}