package SolvedProblems.Easy.Elo1100;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class J {
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

        int[] cards = new int[13];

        for (int i = 0; i < cards.length; i++) {
            cards[i] = 4;
        }

        FastReader reader = new FastReader();
        int n = reader.nextInt();

        int john = 0, mary = 0;

        for (int i = 0; i < 2; i++) {
            int next = reader.nextInt();
            cards[next - 1]--;
            if (next < 11) {
                john += next;
            } else {
                john += 10;
            }
        }

        for (int i = 0; i < 2; i++) {
            int next = reader.nextInt();
            cards[next - 1]--;
            if (next < 11) {
                mary += next;
            } else {
                mary += 10;
            }
        }

        for (int i = 0; i < n; i++) {
            int next = reader.nextInt();
            cards[next - 1]--;
            if (next < 11) {
                john += next;
                mary += next;
            } else {
                john += 10;
                mary += 10;
            }
        }

        int tMary = 23 - mary;

        if (tMary < 11 && tMary >= 0) {
            if (cards[tMary - 1] == 0) {
                tMary = 11;
            }
        }

        int tJohn = 24 - john;

        if (tJohn < 11){
            while (cards[tJohn - 1] == 0) {
                tJohn++;
                if (tJohn == 13) {
                    break;
                }
            }
        }
        
        if (tJohn < 11 && tJohn >= 0){
            if (tJohn + mary > 23) {
                tJohn = 11;
            }
        }

        int ans = Math.min(tMary, tJohn);

        if (ans < 11 && ans > 0) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }

}