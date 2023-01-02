package MetaHackerCup.QualificationRound;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
public class ProblemB {

    // FastReader template from: https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("second_friend_input.txt"));
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

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int cases = reader.nextInt();

        for(int i = 1; i <= cases; i++){
            System.out.print(String.format("Case #%d: ", i));
            solution(reader);
        }
    }   

    public static void solution(FastReader reader){
        int r = reader.nextInt();
        int c = reader.nextInt();
        boolean tree = false;

        for(int i = 0; i < r; i++){
            String l = reader.nextLine();
            for(int x = 0; x < c; x++){
                if (tree)
                    break;
                if (l.charAt(x) == '^'){
                    tree = true;
                }
            }
        }

        if (!tree){
            System.out.println("Possible");
            printMatrix(r,c,'.');
            return;
        } else if (r == 1 || c == 1) {
            System.out.println("Impossible");
            return;
        }

        System.out.println("Possible");
        printMatrix(r,c,'^');
    }

    public static void printMatrix(int r, int c, char p){
        for(int i = 0; i < r; i++){
            for(int x = 0; x < c; x++){
                System.out.print(p);
            }
            System.out.println("");
        }
    }
}