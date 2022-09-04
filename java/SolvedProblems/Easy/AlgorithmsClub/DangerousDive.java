package SolvedProblems.Easy.AlgorithmsClub;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4379
 */

public class DangerousDive {
    
    public static void main(String[] args) throws FileNotFoundException {

        Scanner scan;

        try {
            scan = new Scanner (new File("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e){
            scan = new Scanner(System.in);
        }
        
        while (scan.hasNextLine()){
            recognize(scan.nextLine(), scan.nextLine());
        }

    }


    public static void recognize(String l1, String l2){
        String[] sep = l1.split(" ");

        int g = Integer.parseInt(sep[0]);
        int r = Integer.parseInt(sep[1]);

        if (g-r == 0 || g-r < 0){
            System.out.println("*");
            return;
        }

        String[] returned = l2.split(" ");

        HashSet<Integer> hash = new HashSet<Integer>();
        for (int x = 0; x < returned.length; x++){
            hash.add(Integer.parseInt(returned[x]));
        }   

        int counter = 1;
        for (int i = 0; i < g-r;){
            if (!hash.contains(counter)){
                System.out.print(counter + " ");
                i++;
            }
            counter++;
        }
        System.out.println("");

    }
}