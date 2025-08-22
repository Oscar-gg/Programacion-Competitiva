package SolvedProblems.Easy.Elo800;
import java.util.*;
import java.io.*;
import java.math.BigInteger;

// Code by: @Oscar-gg 

public class LuckyNumbers {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc;
        try {
            sc = new Scanner(new File("input.txt"));
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e) {
            sc = new Scanner(System.in);
        }
        
        problem(sc.nextBigInteger());  
    }

    public static void problem(BigInteger input) {
        BigInteger s = input;
        while (!countDigit47(s)){
            if (calculateDigits(s) % 2 != 0){
                s = construct(s);                
            } else {
                s = s.add(BigInteger.ONE);
                char[] arr = s.toString().toCharArray();
                boolean changed = false;
                for (int i = 0; i < arr.length; i++){
                    // Finally ＼（〇_ｏ）／... but this feels hardcoded. Oops, celebrated too quickly.
                    
                    if (Character.getNumericValue(arr[i]) < 4){
                        arr[i] = '4';
                        changed = true;
                        for (int x = i; x <arr.length;x++){
                            arr[x] = '4';
                        }
                        break;
                    } 
                }

                if (changed){
                    s = new BigInteger(new String(arr));
                }
            }
        }
        System.out.print(s);
    }

    public static BigInteger construct(BigInteger input){
        int digits = calculateDigits(input) + 1;
        BigInteger newVal = BigInteger.valueOf(4);

        for(int i = 1; i < digits; i++){
            if (i < digits/2){
                newVal = newVal.multiply(BigInteger.TEN).add(BigInteger.valueOf(4));
            } else {
                newVal = newVal.multiply(BigInteger.TEN).add(BigInteger.valueOf(7));
            }
        }
        
        return newVal;
    }


    public static int calculateDigits(BigInteger number){
        return String.valueOf(number).length();
    }

    public static boolean countDigit47(BigInteger num){
        int f = 0;
        int s = 0;
        String n = String.valueOf(num);
        int digits = calculateDigits(num);

        for (int x = 0; x < digits; x++){
            if (n.charAt(x) == '7'){
                s++;
            } else if (n.charAt(x)  == '4'){
                f++;
            }
        }

        return (f == digits/2 && digits % 2 == 0) ? f == s: false;
        
    }
}