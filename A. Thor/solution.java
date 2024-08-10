import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Queue;
import java.util.LinkedList;

public class B {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out); 
        String[] initialInput = br.readLine().split(" ");
        int n = Integer.parseInt(initialInput[0]);
        int q = Integer.parseInt(initialInput[1]);
        
        Queue<Integer>[] helper = new LinkedList[n + 1];
        boolean[] isRead = new boolean[q + 1];
        int[] match = new int[q + 1];
        int globalRead = 0;
        int unread = 0;
        int current = 1;
        for (int i = 1; i <= n; ++i) {
            helper[i] = new LinkedList<>();
        }
        for (int i = 1; i <= q; ++i) {
            String[] eventInput = br.readLine().split(" ");
            int type = Integer.parseInt(eventInput[0]);
            int appOrt = Integer.parseInt(eventInput[1]);
            
            if (type == 1) {
                helper[appOrt].add(current);
                match[current++] = appOrt;
                unread++;
            } else if (type == 2) {
                while (!helper[appOrt].isEmpty()) {
                    if (!isRead[helper[appOrt].peek()]) {
                        unread--;
                        isRead[helper[appOrt].peek()] = true;
                    }
                    helper[appOrt].poll();
                }
            } else {
                while (globalRead < appOrt  ) {
                    globalRead++;
                    if (!isRead[globalRead]) {
                        isRead[globalRead] = true;
                        unread--;
                    }
                }
            }
            out.println(unread); 
        }
        
        out.flush(); 
        br.close();
        out.close(); 
    }
}
