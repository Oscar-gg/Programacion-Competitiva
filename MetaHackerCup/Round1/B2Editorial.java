import java.util.*;
import java.io.*;
import java.math.BigInteger;

// Code by: @Oscar-gg

//https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/solutions

// Incorrect Code; doesn't pass tests. Pending changes.

public class B2Editorial {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output

    static final BigInteger mod = BigInteger.valueOf(1000000007);

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

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int c = reader.nextInt();
        for (int i = 1; i <= c; i++) {
            System.out.print(String.format("Case #%d: ", i));
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();

        int[] tx = new int[n];
        int[] ty = new int[n];

        long txsum2 = 0;
        long tysum2 = 0;

        long px = 0;
        long py = 0;

        for (int i = 0; i < n; i++) {
            tx[i] = reader.nextInt();
            ty[i] = reader.nextInt();

            txsum2 += (long) Math.pow(tx[i], 2);
            tysum2 += (long) Math.pow(ty[i], 2);

            px += tx[i];

            py += ty[i];

            if (i % 5 == 0) {
                txsum2 %= txsum2;
                tysum2 %= tysum2;
                px %= px;
                py %= py;
            }

        }

        int q = reader.nextInt();

        long sumtix = 0;
        long sumtiy = 0;

        long sumtix2 = 0;
        long sumtiy2 = 0;

        for (int i = 0; i < q; i++) {
            int currx = reader.nextInt();
            int curry = reader.nextInt();

            sumtix += currx;
            sumtiy += curry;

            sumtix2 += (long) Math.pow(currx, 2);
            sumtiy2 += (long) Math.pow(curry, 2);

            if (i % 5 == 0) {
                sumtix %= mod.longValue();
                sumtiy %= mod.longValue();
                sumtix2 %= mod.longValue();
                sumtiy2 %= mod.longValue();
            }
        }

        long sum = (txsum2 + sumtix2 + tysum2 + sumtiy2);

        long subtract = (2 * px * sumtix) % mod.longValue() + (2 * py * sumtiy) % mod.longValue();

        if (sum < subtract)
            sum *= 10;

        subtract %= mod.longValue();

        sum -= subtract;

        sum %= mod.longValue();

        System.out.println(sum);
    }
}