package SolvedProblems.Easy;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
class Main {
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

        int people = reader.nextInt();

        String nameY = "", nameO = "";

        int oldest = Integer.MAX_VALUE;
        int youngest = -1;

        for(int i = 0; i < people; i++){
            String[] s = reader.nextLine().split(" ");
            int daysAlive = Integer.parseInt(s[1]) +
                            Integer.parseInt(s[2]) * 31 +
                            Integer.parseInt(s[3]) * 31 * 12;
            if (daysAlive < oldest ){
                oldest = daysAlive;
                nameO = s[0];
            } else if (daysAlive > youngest){
                youngest = daysAlive;
                nameY = s[0];
            }
        }

        System.out.println(nameY);
        System.out.println(nameO);

    }
}