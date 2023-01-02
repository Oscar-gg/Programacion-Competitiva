package MetaHackerCup.QualificationRound;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
public class ProblemAMHC {
    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("second_hands_input.txt"));
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

        int cases = reader.nextInt();

        for (int i = 1; i <= cases; i++) {
            String s = String.format("Case #%d: ", i);
            System.out.print(s);
            problem(reader.nextInt(),reader.nextInt(), reader.nextLine());
            System.out.print('\n');
        }

    }

    public static void problem(int n, int k, String val) {
        String[] s = val.split(" ");

        if (n > k*2){
            System.out.print("NO");
            return;
        }

        HashSet<Integer> first = new HashSet<Integer>();
        HashSet<Integer> second = new HashSet<Integer>();
        
        for(int i = 0; i < s.length; i++){
            int cur = Integer.parseInt(s[i]);

            if (!first.contains(cur)){
                first.add(cur);
            } else if (!second.contains(cur)){
                second.add(cur);
            } else {
                System.out.print("NO");
                return;
            }
        }

        System.out.print("YES");
    }
}