import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        int m = sc.nextInt() ; 
        // Let's assume That n is bigger than m 
        if( n < m ){
            n = n^m ; 
            m = n^m ; 
            n = n^m; 
        }
        System.out.println( (n-1) + " " + m ) ; 
    }
}
