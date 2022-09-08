//import java.util.*;
import java.io.*;
import java.util.BitSet;

public class tests {
    public static void main(String[] args) throws FileNotFoundException {
        //Scanner sc;
        /* 
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
        */

        //int a = 4; // 0100
        //int b = 5;// 1010
/* 
        int a = 100;

        System.out.println("a: " + Integer.toBinaryString(a) + ", #: " + a);

        System.out.println("~a: " + Integer.toBinaryString(~a) + ", #: " + ~a);
        System.out.println("~a + 1: " + Integer.toBinaryString(~a+1) + ", #: " + (~a + 1));
    */

    // n % x == n & x-1 only if x = power of two.
    /*
    System.out.println(21 % 8);  // 1
    System.out.println(21 & 7);  // 10101
                                 // 00111 
                                 // 00101
    */
    test();
}

    public static void test() {
        BitSet s = new BitSet(10);
        s.set(0);
        s.set(1);
        s.set(4);
        s.flip(5);
        s.flip(5);
        s.set(6);
        System.out.println(s);
    }
}