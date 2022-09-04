package SolvedProblems.Easy.AlgorithmsClub;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
public class RegistrationSystem {
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

        solution(reader);

    }

    public static void solution(FastReader reader){
        int cases = reader.nextInt();

        HashMap<String, Integer> data = new HashMap<String, Integer>();

        for(int i = 0; i < cases; i++){
            String input = reader.nextLine();
            if (!data.containsKey(input)){
                System.out.println("OK");
                data.put(input, 1);
            } else {
                int c = data.get(input);
                System.out.println(input + c);
                data.replace(input, c+1);
            }
        }


    }
}