package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1702/C

public class TrainAndQueries {
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

        char nextChar(){
            return next().charAt(0);
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

        for (int i = 0; i < cases; i++) {
            solve(reader);
        }

    }

    public static void solve(FastReader reader) {
        int n = reader.nextInt();
        int k = reader.nextInt();
        HashMap<Integer, Pair> h = new HashMap<Integer, Pair>(n);

        for(int i = 0; i < n; i++){
            int next = reader.nextInt();
            if (!h.containsKey(next)){
                h.put(next, new Pair(i, i));
            } else {
                h.get(next).last = i;
            }
        }

        for (int i = 0; i < k; i++) {
            int a = reader.nextInt();
            int b = reader.nextInt();

            if (h.containsKey(a) && h.containsKey(b) &&
                h.get(a).first < h.get(b).last){
                System.out.println("YES");

            } else {
                System.out.println("NO");
            }
        }
    }

    static class Pair{
        int first;
        int last;

        Pair(int f, int l){
            first = f;
            last = l;
        }
    }

}
