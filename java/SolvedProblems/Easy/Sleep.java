package SolvedProblems.Easy;
import java.util.*;
import java.io.*;
import java.lang.Math;

// Code by: @Oscar-gg

public class Sleep {
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
        int cases = reader.nextInt();

        for (int x = 0; x < cases; x++){
            sleepingTime(reader);
        }
    }

    public static void sleepingTime(FastReader reader){
        int n = reader.nextInt();
        int time = reader.nextInt() * 60 + reader.nextInt();
        int oH, oM;
        int minDif = 1500, temp, difference;
        boolean notNull = false; 
        int nextDay = 1500;

        for (int i = 0; i < n; i++){
            temp = reader.nextInt() * 60 + reader.nextInt();
            difference = temp-time;
            if (difference < minDif){
                if (difference < 0){
                    if (Math.abs(difference) < nextDay){
                        nextDay = temp;
                    }
                } else {
                    minDif = temp-time;
                    notNull = true;
                }
            }
            
        }

        if (!notNull){
            minDif = 1440 - time + nextDay;
        }
        
        oH = minDif / 60;
        oM = minDif % 60;

        System.out.println(Integer.toString(oH) + " " + Integer.toString(oM));
    }

}