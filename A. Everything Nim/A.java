import java.util.* ; 

public class Solution {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
       
        int t = sc.nextInt() ; 
        
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            // 
            for( int i=0 ; i<n ; ++i ){
                arr[i] = sc.nextInt() ; 
            }
            
            Arrays.sort( arr ) ; 
            
            int blocks = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                 blocks++ ; 
                 while( i+1 <n && arr[i+1] == arr[i] ) ++i ; 
            } 
            
            boolean[] rs = new boolean[ blocks ] ;
            
            // Compute The value of each block 
            int[] val = new int[ blocks ] ;
            int idx = 0 ;
            int prev = 0 ; 
            for( int i=0 ; i<n ; ++i ){
                val[ idx++ ] = arr[i] - prev ; 
                prev = arr[i] ; 
                while( i+1 < n && arr[i+1] == arr[i] ) ++i ;
            }
             
            rs[ blocks - 1 ] = true ; 
            
            for( int i=blocks-2 ; i>=0 ; --i ){
                int curr = val[i] ; 
                if( rs[i+1] ){
                    if( val[i] % 2 == 0 ){
                        rs[i] = true ; 
                    }else if( val[i] == 1 ){
                        rs[i] = false ; 
                    }else {
                        rs[i] = true ; 
                    }
                }else {
                    rs[i] = true ; 
                }
            }
            
            System.out.println( rs[0] ? "Alice" : "Bob" ) ; 
        }
    }
}