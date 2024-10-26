import java.util.Scanner ; 

public class B {
    public static long combination(int n, int k) {
        if (k > n || n < 0 || k < 0) {
            return 0;
        }
        if (k == 0 || k == n) {
            return 1;
        }

        if (k > n - k) {
            k = n - k;
        }

        long result = 1;
        for (int i = 0; i < k; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();  
        String s2 = sc.nextLine(); 
        int n = s1.length();
        int f = 0;  
        int d = 0;  
        int p = 0;  
        for (int i = 0; i < n; ++i) {
            if (s1.charAt(i) == '+') ++f;
            else --f;

            if (s2.charAt(i) == '+') ++d;
            else if (s2.charAt(i) == '-') --d;
            else ++p;  
        }

        int diff = f - d;
        double rs;
        if ((diff + p) % 2 == 0 && Math.abs(diff) <= p) {
            int posMoves = (diff + p) / 2;
            long validConfigurations = combination(p, posMoves);
            double totalConfigurations = Math.pow(2, p);
            rs = validConfigurations / totalConfigurations;
        } else {
            rs = 0;
        }
        System.out.println(rs);
    }
}

              
