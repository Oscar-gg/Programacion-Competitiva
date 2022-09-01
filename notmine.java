import java.io.*;
import java.util.*;

// Code from: Azat_Yusupov https://codeforces.com/contest/96/standings
// with small changes for code comprehension.

public class notmine {  

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
    
    public static void main(String[] args) throws IOException {
        FastReader reader = new FastReader();
        int n = reader.nextInt();
        long ans = Long.MAX_VALUE;
        // i is the number of digits in the number to be computer.
        for (int i = 2; i <= 12; i+=2) {
            System.out.println("i: " + i);
            for (int j = 0; j < (1 << i); j++) {
                System.out.println("    j: " + j + ", (1 << i): " + (Integer.toBinaryString(1 << i)));
                long s = 0;
                int cnt1 = 0, cnt2 = 0;
                for (int k = 0; k < i; k++) {
                    System.out.println("\t\tj: " + Integer.toBinaryString(j) + ", 1 << k: " + Integer.toBinaryString(1 << k));
                    System.out.println("\t\tj & (1 << k) = " + Integer.toBinaryString(j & k));
                    if ((j & (1 << k)) != 0) {
                        cnt1++;
                        s = s*10+4;
                        System.out.println("\t\ts: " + s);
                    }
                    else {
                        cnt2++;
                        s = s*10+7;
                        System.out.println("\t\ts: " + s);
                    }
                }
                if (cnt1==cnt2 && s >= n){
                    ans = Math.min(ans, s);
                    System.out.println(ans);
                    return;
                }   
            }
        }        
    }
    
}