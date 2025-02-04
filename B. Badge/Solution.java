import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ;
        int n = sc.nextInt() ; 
        int[] comp = new int[n+1] ; 
        for( int i= 1 ; i<=n ; ++i ){
            comp[i] = sc.nextInt() ; 
        }
        for( int i=1 ; i<=n ; ++i ){
            boolean[] punished = new boolean[n+1] ; 
            int in = i ; 
            while( !punished[in] ){
                punished[in] = true ; 
                in = comp[in] ; 
            }
            System.out.print(in + " ") ; 
        }
    }
}