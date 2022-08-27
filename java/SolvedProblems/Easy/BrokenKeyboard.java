package SolvedProblems.Easy;
import java.util.*;
import java.io.*;

// Code by: @Oscar-gg

public class BrokenKeyboard {
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
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scan = new Scanner(new File("input.txt"));

        try {
            PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
            System.setOut(out);
        } catch (Exception e) {

        }

        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            fixText(line);
        }
    }

    static void fixText(String input) {
        if (input == null) {
            System.out.println("Null");
            return;
        }

        LinkedListTemp c = new LinkedListTemp();
        c.head = new Nodo();

        int index = 0;

        for (int x = 0; x < input.length(); x++) {
            if (input.charAt(x) != '[' && input.charAt(x) != ']') {
                index = x;
                break;
            }
        }

        Nodo f = new Nodo(null, input.charAt(index));

        c.head.next = f;
        Nodo curr = f;
        c.tail = f;
        Nodo tempDir = null;
        boolean isStart = false;

        for (int i = index + 1; i < input.length(); i++) {
            if (input.charAt(i) == '[') {
                tempDir = c.head.next;
                curr = c.head;
                isStart = true;
                continue;
            } else if (input.charAt(i) == ']') {
                isStart = false;
                curr = c.tail;
                tempDir = c.tail;
                continue;
            }
            if (isStart) {
                Nodo n = new Nodo(tempDir, input.charAt(i));
                curr.next = n;
                curr = n;
            } else {
                Nodo n = new Nodo(null, input.charAt(i));
                c.tail.next = n;
                c.tail = n;
            }

        }

        printLinkedList(c);
    }

    static void printLinkedList(LinkedListTemp toPrint) {
        Nodo node = toPrint.head.next;
        while (node != null) {
            System.out.print(node.value);
            node = node.next;
        }

        System.out.println("");
    }

    static class LinkedListTemp {
        Nodo head;
        Nodo tail;
    }

    static class Nodo {

        public Nodo() {
        }

        public Nodo(Nodo next, char value) {
            this.next = next;
            this.value = value;
        }

        Nodo next;
        char value;
    }

}