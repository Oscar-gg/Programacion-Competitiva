package SolvedProblems.Easy.Elo800;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg
public class Twin {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc;
        try {
            sc = new Scanner(new File("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e) {
            sc = new Scanner(System.in);
        }

        int n = sc.nextInt();
        int[] a = new int[n];
        int total = 0, c = 0, sum = 0;

        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
            total += a[i];
        }

        Arrays.sort(a);

        while (sum <= total/2){
            sum += a[n-1];
            n--;
            c++;
        }

        System.out.println(c);
    }

}
