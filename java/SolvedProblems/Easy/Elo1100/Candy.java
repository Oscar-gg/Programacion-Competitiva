package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class Candy {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("candy_collection_input.txt"));
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
            System.out.print("Case #" + (i+1) + ": ");
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();
        int[] ni = new int[n];

        int max = Integer.MAX_VALUE + 1;
        int currentCount = 0;

        for(int i = 0; i < n; i++){
            ni[i] = reader.nextInt();
        }

        for(int i = 0; i < n; i++){
            currentCount += ni[i];
            max = (currentCount > max) ? currentCount : max;
            if (currentCount < 0)
                currentCount = 0;
        }

        System.out.println(max);
    }
}