import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();

        for (int i = 0; i < q; ++i) {
            int n = sc.nextInt();
            Set<Integer> used = new HashSet<>();

            for (int i2 = 2; i2 * i2 <= n; ++i2) {
                if (n % i2 == 0 && !used.contains(i2)) {
                    used.add(i2);
                    n /= i2;
                    break;
                }
            }
            for (int i2 = 2; i2 * i2 <= n; ++i2) {
                if (n % i2 == 0 && !used.contains(i2)) {
                    used.add(i2);
                    n /= i2;
                    break;
                }
            }

            if (used.size() < 2 || used.contains(n) || n == 1 ) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
                used.add(n);
                for (int factor : used) {
                    System.out.print(factor + " ");
                }
                System.out.println();
            }
        }

        sc.close();
    }
}
