import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        if (n1 > n2) {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }
        long sum1 = 0;
        long sum2 = 0;
        for (int i = n - 1; i >= n - n1; --i) {
            sum1 += arr[i];
        }
        for (int i = n - n1 - 1; i >= n - n1 - n2; --i) {
            sum2 += arr[i];
        }
        double rs = (double) sum1 / n1 + (double) sum2 / n2;

        System.out.printf("%.9f%n", rs);
    }
}
