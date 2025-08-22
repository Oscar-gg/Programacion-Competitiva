package SolvedProblems.Easy.Elo1200;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

// Problem from: https://codeforces.com/problemset/problem/1594/C

public class MakeThemEqual {
    // FastReader template from:
    // https://www.geeksforgeeks.org/java-competitive-programming-setup-in-vs-code-with-fast-i-o-and-snippets/

    static String[] primeNumbers;
    static boolean primeCalled = false;

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
        char c = reader.next().charAt(0);

        String line = reader.nextLine();

        int targetCount = 0;

        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) == c) {
                targetCount++;
            }
        }

        if (targetCount == n) {
            System.out.println(0);
        } else if (line.charAt(n - 1) == c) {
            System.out.println(1);
            System.out.println(n);
        } else if (line.charAt(n - 2) == c) {
            System.out.println(1);
            System.out.println(n - 1);
        } else {

            int[] remaining = new int[n - targetCount];
            int index = 0;

            for (int i = 0; i < n; i++) {
                if (line.charAt(i) != c) {
                    remaining[index++] = i + 1;
                }
            }

            for (int l = 2; l < n; l++) {
                if (line.charAt(l - 1) != c)
                    continue;

                boolean found = true;

                for (int i = 0; i < remaining.length; i++) {
                    if (remaining[i] % l == 0) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    System.out.println(1);
                    System.out.println(l);
                    return;
                }
            }

            System.out.println(2);
            System.out.println(n - 1 + " " + n);
        }
    }

}

/*
 * Discarded code (thought that only positions i that didn't
 * divide x evenly were replaced. But instead x divides i)
 * 
 * 
 * public static String getPrimeNumbers() {
 * 
 * StringBuilder sb = new StringBuilder();
 * 
 * 
 * For debugging if function is correct.
 * try {
 * PrintStream pw = new PrintStream(new FileOutputStream("output.txt"));
 * System.setOut(pw);
 * } catch (Exception e) {
 * }
 * 
 * int[] memoPrimes = new int[25998];
 * memoPrimes[0] = 2;
 * 
 * sb.append("2 ");
 * 
 * int n = (int) Math.pow(10, 5) * 5;
 * 
 * int checkPrimality = 2;
 * int primeCount = 1;
 * 
 * while (checkPrimality <= n && primeCount != 25998) {
 * int index = 0;
 * boolean isPrime = true;
 * do {
 * if (checkPrimality % memoPrimes[index] == 0) {
 * isPrime = false;
 * break;
 * }
 * index++;
 * } while (memoPrimes[index] != 0);
 * 
 * if (isPrime) {
 * memoPrimes[primeCount++] = checkPrimality;
 * sb.append(checkPrimality + " ");
 * }
 * checkPrimality++;
 * }
 * 
 * return sb.toString();
 * 
 * }
 * 
 */

/*
 * public static void main(String[] args) {
 * 
 * primeNumbers = getPrimeNumbers().split(" ");
 * FastReader reader = new FastReader();
 * int t = reader.nextInt();
 * 
 * for (int i = 0; i < t; i++) {
 * solve(reader);
 * }
 * 
 * }
 * 
 */

/*
 * public static void solve(FastReader reader) {
 * int n = reader.nextInt();
 * char c = reader.next().charAt(0);
 * 
 * String line = reader.nextLine();
 * 
 * int targetCount = 0;
 * 
 * int last = -1;
 * 
 * for (int i = 0; i < line.length(); i++) {
 * if (line.charAt(i) == c) {
 * targetCount++;
 * } else {
 * last = i;
 * }
 * }
 * 
 * if (targetCount == n) {
 * System.out.println(0);
 * return;
 * }
 * 
 * if (n - targetCount == 1) {
 * System.out.println(1);
 * if (last == n) {
 * System.out.println(n - 1);
 * } else {
 * System.out.println(n);
 * 
 * }
 * return;
 * }
 * 
 * int prime = searchNearestPrime(n);
 * 
 * if (prime > last) {
 * System.out.println(1);
 * System.out.println(prime);
 * } else if (prime == last) {
 * System.out.println(2);
 * System.out.println(prime - 1 + " " + prime);
 * } else if (prime < last) {
 * System.out.println(3);
 * System.out.println(prime + " " + (last - 1) + " " + last);
 * }
 * 
 * }
 * 
 * public static int searchNearestPrime(int max) {
 * 
 * if (max < 2) {
 * return -1;
 * }
 * int upperbound = primeNumbers.length, lowerBound = 0;
 * 
 * while (true) {
 * int index = (upperbound + lowerBound) / 2;
 * int current = Integer.parseInt(primeNumbers[index]);
 * // System.out.println(index);
 * // System.out.println(current);
 * if (current <= max && Integer.parseInt(primeNumbers[index + 1]) > max) {
 * return current;
 * }
 * 
 * if (current > max) {
 * upperbound = index - 1;
 * } else if (current < max) {
 * lowerBound = index + 1;
 * }
 * }
 * }
 * 
 * 
 */