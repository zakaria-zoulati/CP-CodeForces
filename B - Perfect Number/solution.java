import java.util.Scanner;

public class B {
    public static int cal(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        while (n > 0) {
            ans++;
            if (cal(ans) == 10) {
                n--;
            }
        }
        System.out.println(ans);
    }
}
