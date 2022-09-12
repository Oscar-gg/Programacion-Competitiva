import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: Meta Hacker Cup round 1

public class A1 {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("consecutive_cuts_chapter_1_input.txt"));
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

        for (int i = 1; i <= cases; i++) {
            String s = String.format("Case #%d: ", i);
            System.out.println(s + solve(reader));
        }
    }

    private static String solve(FastReader reader) {
        int n = reader.nextInt();
        int k = reader.nextInt();

        int[] ai = new int[n];
        int[] bi = new int[n];

        for (int i = 0; i < n; i++) {
            ai[i] = reader.nextInt();
        }

        for (int i = 0; i < n; i++) {
            bi[i] = reader.nextInt();
        }

        int begin = -1;

        for (int i = 0; i < n; i++) {
            if (bi[i] == ai[0]) {
                begin = i;
                break;
            }
        }

        if (begin == -1)
            return "NO";

        int index = begin;

        for (int i = 0; i < n; i++) {
            if (ai[i] != bi[index]) {
                return "NO";
            } else {
                index++;
                index -= (index >= n) ? n : 0;
            }
        }

        if (begin == 0 && k == 0) {
            return "YES";
        } else if (k == 0) {
            return "NO";
        }

        if (begin == 0 && k == 1)
            return "NO";

        if (n == 2){
            if (k % 2 == 1 && begin == 0){
                return "NO";
            }
            if (k % 2 == 0 && begin == 1){
                return "NO";
            }
        }

        return "YES";
    }
}