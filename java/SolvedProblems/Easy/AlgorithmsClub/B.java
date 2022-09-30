package SolvedProblems.Easy.AlgorithmsClub;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from:

public class B {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/


    static int rows = 0;
    static int columns = 0;
    static boolean[][] matrix;
    static boolean[][] visited;

    // For fast input output
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            try {
                br = new BufferedReader(
                        new FileReader("maximal_mexican_mates_input.txt"));
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
            System.out.print("Case #" + (i+1) + ": ");
            solve(reader);
        }
    }

    public static void solve(FastReader reader) {
        int r = reader.nextInt();

        int c = reader.nextInt();

        boolean matrixL[][] = new boolean[r][c];

        for(int i = 0; i < r; i++){
            for(int x = 0; x < c; x++){
                matrixL[i][x] = (reader.nextInt() == 1) ? true : false;
            }
        }

        matrix = matrixL;

        int count = 0;
        int maxCount = 0;

        boolean visitedL[][] = new boolean[r][c];
        visited = visitedL;

        for(int i = 0; i < r; i++){
            for(int x = 0; x < c; x++){
                if (matrix[i][x] == true && visited[i][x] == false){
                    visited[i][x] = true;
                    count = maximalRegion(i, x) + 1;
                    if (count > maxCount)
                        maxCount = count;
                }
            }
       
            count = 0;
        }

        System.out.println(maxCount);

    }

    public static int maximalRegion(int r, int c){
        int[] adjacentR = {-1, 0, 1, -1, 1, -1, 0, 1};
        int[] adjacentC = {-1, -1, -1, 0, 0,  1, 1, 1};

        int count = 0;

        for(int i = 0; i < adjacentR.length; i++){
            if (validSpot(adjacentR[i] + r, adjacentC[i] + c)){
                visited[r + adjacentR[i]][c + adjacentC[i]] = true;
                count++;
                count += maximalRegion(r + adjacentR[i], c + adjacentC[i]);
            }
        }
        
        return count;
    }

    public static boolean validSpot(int r, int c){

        boolean valid = c >= 0 && (c < matrix[0].length) &&
                        r >= 0 && (r < matrix.length);

        if (valid){
            valid = visited[r][c] == false && matrix[r][c] == true;
        }

        return valid;
    }
}