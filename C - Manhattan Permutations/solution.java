import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();  
        while (T-- > 0) {
            int n = scanner.nextInt();  
            long k = scanner.nextLong(); 
            long max_s = 0;
            for (int i = 0; i < n; i++) {
                max_s += Math.abs(n - 1 - i - i);
            }
            if (k % 2 != 0 || k > max_s) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
                List<Integer> p = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    p.add(i);
                }
                k /= 2;
                for (int i = 0; k > 0; i++) {
                    if (k >= n - 1 - 2 * i) {
                        Collections.swap(p, i, n - 1 - i);
                        k -= n - 1 - 2 * i;
                    } else {
                        Collections.swap(p, i, i + (int) k);
                        k = 0;
                    }
                }
                for (int i = 0; i < n; i++) {
                    System.out.print((p.get(i) + 1) + " ");
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
