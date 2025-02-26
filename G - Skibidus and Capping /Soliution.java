import java.util.*;

public class G {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int MAX = 200_001;
        
        boolean[] isPrime = new boolean[MAX];
        Arrays.fill(isPrime, true);
        
        Map<Integer, int[]> map = new HashMap<>();

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 2; 2 * i < MAX; ++i) {  
            if (!isPrime[i]) continue;
            for (int j = 2 * i; j < MAX; j += i) {
                int a = (j / i);
                if (isPrime[a]) {
                    map.put(j, new int[]{i, a});
                }
            }
        }
        
        int t = sc.nextInt();
        
        while (t-- > 0) {
            long rs = 0L;
            int n = sc.nextInt();
            int[] f = new int[n+1];
            int primes = 0;
            int[] prime_used = new int[ n+1 ] ; 
            for (int i = 0; i < n; ++i) {
                int a = sc.nextInt();
                if (isPrime[a]) {
                    rs += (primes - f[a]);
                    rs += prime_used[ a ] ; 
                    primes++;
                } else {
                    int[] pair = map.get(a);
                    if (pair != null) {
                        rs++; 
                        rs += f[a];
                        rs += f[pair[0]];
                        prime_used[ pair[0] ]++ ; 
                        if (pair[0] != pair[1]) {
                            prime_used[ pair[1] ]++ ; 
                            rs += f[pair[1]];
                        }
                    }
                }
                f[a]++;
            }
            System.out.println(rs);
        }
    }
}
