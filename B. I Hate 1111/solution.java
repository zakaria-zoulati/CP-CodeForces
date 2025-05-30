import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for (int c = 0; c < t; ++c) {
            int x = sc.nextInt();
            
            if (x < 11) {
                System.out.println("NO");
            } else if (x > 1099) {
                System.out.println("YES");
            } else {
                boolean possible = false;
                while (true) {
                    if (x % 11 == 0) {
                        possible = true; // Changed '==' to '='
                        break;
                    } else {
                        x -= 111;
                    }
                    if (x < 0) break; // Added a semicolon at the end
                }
                System.out.println(possible ? "YES" : "NO");
            }
        }
        sc.close();
    }
}
