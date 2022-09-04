package SolvedProblems.Easy;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Exercise from: https://open.kattis.com/problems/bubbletea

public class DeliciousBubbleTea {
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

        int np[] = new int[n];

        for(int i = 0; i < n; i++){
            np[i] = reader.nextInt();
        }

        int m = reader.nextInt();
        int mp[] = new int[m];

        for(int i = 0; i < m; i++){
            mp[i] = reader.nextInt();
        }

        int minCost = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++){
            int k = reader.nextInt();
            for(int x = 0; x < k; x++){
                int tempc = np[i];
                tempc += mp[reader.nextInt()-1];
                if (tempc < minCost){
                    minCost = tempc;
                }
            }
        }

        int money = reader.nextInt();
    
        money -= minCost;

        System.out.println(money/minCost);
    }
}