package SolvedProblems.Easy;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Exercise from: https://codeforces.com/problemset/problem/118/A

public class StringTask {
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

        String input = reader.next();

        char[] arr = "aoyeui".toCharArray();

        HashSet<Character> vowels = new HashSet<Character>();

        for (char a: arr){
            vowels.add(a);
        }

        for(int i = 0; i < input.length(); i++){
            char curr = Character.toLowerCase(input.charAt(i));
            if (!vowels.contains(curr)){
                System.out.print("." + curr);
            }
        }

    }
}