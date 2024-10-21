import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner ; 

public class solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        ArrayList<Long> divisors = new ArrayList<>();
    
        for (long i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.add(i); 
                if (i != n / i) { 
                    divisors.add(n / i);
                }
            }
        }

        Collections.sort( divisors ) ; 

        if (k <= divisors.size()) {
            System.out.println(divisors.get((int) k - 1)); 
        } else {
            System.out.println(-1); 
        }
        sc.close();
    }
}
