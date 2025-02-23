import java.util.*;

public class C {
    static final int mod = 32768;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] dp = new int[mod];
        Arrays.fill( dp , -1 ) ; 
        dp[0] = 0 ; 
        
        // Build an Adjancy Matrix 
        ArrayList<Integer>[] list = new ArrayList[mod] ;
        for( int i=0 ; i<mod ; ++i ){
            list[i] = new ArrayList<>() ; 
        }
        for( int i=0 ; i<mod ; ++i ){
            int a = ( i + 1 )%mod ; 
            int b = ( i << 1 )% mod ; 
            list[a].add(i) ; 
            list[b].add(i) ; 
        }
        // Fill The dp array using the top down approach ( One Pace BFS )
        Queue< int[] > q = new LinkedList<>() ; 
        q.add( new int[]{ 0 , 0} ) ; 
        while( !q.isEmpty() ){
            int[] curr = q.poll() ; 
            for( int j : list[ curr[0] ] ) {
                if( dp[j] == -1 ){
                    dp[j] = curr[1] + 1 ; 
                    q.add( new int[]{ j , curr[1] + 1}) ; 
                }
            }
        }
        
        int n = sc.nextInt() ; 
        while (n-- > 0) {
            int ai = sc.nextInt();
            System.out.print(dp[ai] + " ");
        }
    }
}