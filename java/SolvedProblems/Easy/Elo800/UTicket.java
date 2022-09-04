package SolvedProblems.Easy.Elo800;
import java.util.*;
import java.io.*;
import java.math.BigInteger;

/*https://codeforces.com/contest/160/problem/B*/

// Code by: @Oscar-gg
public class UTicket {
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

        BigInteger d = new BigInteger(reader.next());

        int[] fh = new int[n];
        int[] sh = new int[n];

        for(int i = 0; i < n; i++){
            sh[i] = (d.mod(BigInteger.TEN)).intValue();
            d = d.divide(BigInteger.TEN);
        }

        for(int i = 0; i < n; i++){
            fh[i] = d.mod(BigInteger.TEN).intValue();
            d = d.divide(BigInteger.TEN);
        }

        Arrays.sort(fh);
        Arrays.sort(sh);

        int c = 0;

        for(int i = 0; i < n; i++){
            if((fh[i] < sh[i])){
                c++;
            }
        }

        if (c == n){
            System.out.println("YES");
            return;
        }

        c = 0;

        for(int i = 0; i < n; i++){
            if((fh[i] > sh[i])){
                c++;
            }
        }

        if (c == n){
            System.out.println("YES");
            return;
        }
        
        System.out.println("NO");
    }
}