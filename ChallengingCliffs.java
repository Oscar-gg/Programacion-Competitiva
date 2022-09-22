import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

// Code by: @Oscar-gg

// Problem from:

public class ChallengingCliffs {
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
        int hi[] = new int[n];

        int index = -1, minDistance = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            hi[i] = reader.nextInt();
        }

        Arrays.sort(hi);

        for (int i = 0; i < n - 1; i++) {
            if (hi[i + 1] - hi[i] < minDistance) {
                minDistance = hi[i + 1] - hi[i];
                index = i;
            }
        }

        int temp = hi[index];

        hi[index] = hi[0];
        hi[0] = temp;

        temp = hi[index + 1];

        hi[index + 1] = hi[n - 1];
        hi[n - 1] = temp;

        int[] temp2 = Arrays.copyOfRange(hi, 1, n-1);
        Arrays.sort(temp2);

        for(int i = 1; i < n-1 ; i++){
            hi[i] = temp2[i-1];
        }

        temp2 = null;

        index = n - 1;

        for (int i = 1; i < n; i++) {
            if (hi[i] > hi[0]) {
                index = i;
                break;
            }
        }

        if (index == n - 1) {
            for (int i = 0; i < hi.length; i++) {
                System.out.print(hi[i] + " ");
            }
            System.out.println();
            return;
        }

        System.out.print(hi[0] + " ");

        for (int i = index; i < n - 1; i++) {
            System.out.print(hi[i] + " ");
        }

        for (int i = 1; i < index; i++) {
            System.out.print(hi[i] + " ");
        }

        System.out.print(hi[n - 1]);

        System.out.println();

    }
}