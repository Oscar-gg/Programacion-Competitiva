package SolvedProblems.Easy.Elo1000;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1230/B
 
public class AniaAndMinimizing {
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
        int k = reader.nextInt();
        String s = reader.next();

        if (k == 0){
            System.out.println(s);
            return;
        } else if (n == 1){
            System.out.println(0);
            return;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(1);

        k -= (s.charAt(0) == '1') ? 0 : 1;
        int i = 1;

        for(; i <= k; i++){
            if (i >= n){
                break;
            }

            if (s.charAt(i) == '0')
                k += 1;
            
                
            sb.append(0);
        }

        if (k + 1 < n){
            sb.append(s.substring(k + 1));
        }

        System.out.println(sb.toString());

    }
}