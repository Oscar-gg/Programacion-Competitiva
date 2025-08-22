package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1703/E

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

        int indexTrx = n-1;
        int indexBry = n-1;
        int indexBlx = 0;

        for (int i = 0; i < n / 2; i++) {
            int indexTry = 0;
            int indexBrx = n-1;
            int indexBly = n-1;

            for (int x = 0; x < n / 2; x++) {
                int count1 = 0;

                if (start[i][x]){
                    count1++;
                }

                if (start[indexTry][indexTrx]){
                    count1++;
                }
                    
                if (start[indexBry][indexBrx]){
                    count1++;
                }  

                if (start[indexBly][indexBlx]){
                    count1++;
                }           

                if (count1 <= 2) {
                    totalChanges += count1;
                } else {
                    totalChanges += 4 - count1;
                }

                indexTry++;
                indexBrx--;
                indexBly--;
            }

            indexTrx--;
            indexBry--;
            indexBlx++;
        }

        int pair = (n % 2 == 0) ? 0 : 1;

        
        if (pair == 1) {
            int indexTy = 0;
            int indexBy = n-1;
            int indexLx = 0;
            int indexRx = n-1;
            
            for (int i = 0; i < n / 2; i++) {
                int count1 = 0;
                if (start[n / 2][indexTy++])
                    count1++;
                if (start[indexLx++][n / 2])
                    count1++;
                if (start[indexRx--][n / 2])
                    count1++;
                if (start[n/2][indexBy--])
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