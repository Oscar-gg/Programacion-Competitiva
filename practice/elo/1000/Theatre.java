package SolvedProblems.Easy.Elo1000;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
public class Theatre {
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

        int n = reader.nextInt();
        int m = reader.nextInt();
        int a = reader.nextInt();

        if (a > (long)n*m){
           System.out.println(1);
           return;
        }

        if (n % a != 0){
            if (a > n){
               n = a; 
            } else {
                n += a - (n % a);
            } 
        }

        if (m % a != 0){
            if (a > m){
                m = a;
            } else {
                m += a - (m % a);
            }
        }
        
        System.out.println((long)n/a * m/a);
    }
}