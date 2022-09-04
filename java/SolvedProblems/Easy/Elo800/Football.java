package SolvedProblems.Easy.Elo800;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

public class Football {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc;
        try {
            sc = new Scanner(new File("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e) {
            sc = new Scanner(System.in);
        }
        while (sc.hasNextLine()) {
            problem(sc.nextLine());
        }
    }

    public static void problem(String input) {
        int counter = 0;
        int tempChar = input.charAt(0);

        if (input.length() < 7){
            System.out.print("NO");
            return;
        }

        for(int i = 0; i < input.length(); i++){
            if (input.charAt(i) == tempChar){
                counter++;
            } else {
                counter = 1;
                tempChar = input.charAt(i);
            }

            if (counter > 6){
                System.out.print("YES");
                return;
            }
        }

        System.out.print("NO");

    }
}