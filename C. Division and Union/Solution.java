import java.util.* ; 

public class Solution{
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[][] intervals = new int[n][3] ; 
            for( int i=0 ; i<n ; ++i ){
                intervals[i][0]  = sc.nextInt() ; 
                intervals[i][1] = sc.nextInt(); 
                intervals[i][2] = i ; 
            }
            Arrays.sort( intervals , (a,b) -> {
                if( a[0] != b[0] ){
                    return a[0] - b[0] ; 
                }else {
                    return a[1] - b[1] ; 
                }
            }) ; 
            int idx = 1 ; 
            int e = intervals[0][1] ; 
            while( idx < n && intervals[idx][0] <= e ){
                e = Math.max( e , intervals[idx][1] ) ; 
                idx++ ; 
            }
            if( idx == n ){
                System.out.println(-1) ; 
            }else {
                int[] ans = new int[n] ; 
                for( int i=0 ; i<n ; ++i ){
                    if( i < idx ){
                        ans[ intervals[i][2] ] = 1 ; 
                    }else {
                        ans[ intervals[i][2] ] = 2; 
                    }
                }
                for( int i=0 ; i<n ; ++i ){
                    System.out.print( ans[i] + " " );  
                }  
                System.out.println() ; 
            }
        }
    }
}