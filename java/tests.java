import java.util.*;
import java.io.*;

public class tests {
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
            // problem();
        }
    }

    public static void problem() {
        
    }
}