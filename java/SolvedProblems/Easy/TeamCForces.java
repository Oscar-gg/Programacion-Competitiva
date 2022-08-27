package SolvedProblems.Easy;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

public class TeamCForces {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc;
        try {
            sc = new Scanner(new File("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e) {
            sc = new Scanner(System.in);
        }

        int cases = sc.nextInt();
        
        int count = 0;
        for(int i = 0; i < cases; i++){
            count += problem(sc);
        }
        System.out.print(count);
    }

    public static int problem(Scanner sc) {
        if (sc.nextInt() + sc.nextInt() + sc.nextInt() > 1 )
            return 1;
        return 0;
    }
}