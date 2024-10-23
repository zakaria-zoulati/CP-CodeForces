import java.util.Scanner ; 

public class F {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int n = sc.nextInt() ; 
            int[] arr = new int[3] ; 
            for(int i=0 ; i<n ; ++i){
                int a = sc.nextInt() ; 
                arr[ a%3 ]++ ; 
            }
            int rs = 0 ; 
            
            if( arr[0] < n/3 ){
                int diff = n/3 - arr[0] ; 
                if( arr[2] > n/3 ){
                    int m = Math.min( arr[2] - n/3 , diff ) ; 
                    arr[2] -= m ; 
                    rs += m ; 
                    diff -= m ; 
                }
                if( arr[1] > n/3 ){
                    int m = Math.min( arr[1] - n/3 , diff ) ; 
                    arr[1] -= m ; 
                    rs += 2*m ; 
                    diff -= m ;  
                }
            }
            
            if( arr[1] < n/3 ){
                int diff = n/3 - arr[1] ; 
                if( arr[0] > n/3 ){
                    int m = Math.min( arr[0] - n/3 , diff ) ; 
                    arr[0] -= m ; 
                    rs += m ; 
                    diff -= m ; 
                }
                if( arr[2] > n/3 ){
                    int m = Math.min( arr[2] - n/3 , diff ) ; 
                    arr[2] -= m ; 
                    rs += 2*m ; 
                    diff -= m ;  
                }
            }
            
            if( arr[2] < n/3 ){
                int diff = n/3 - arr[2] ; 
                if( arr[1] > n/3 ){
                    int m = Math.min( arr[1] - n/3 , diff ) ; 
                    arr[1] -= m ; 
                    rs += m ; 
                    diff -= m ; 
                }
                if( arr[0] > n/3 ){
                    int m = Math.min( arr[0] - n/3 , diff ) ; 
                    arr[0] -= m ; 
                    rs += 2*m ; 
                    diff -= m ;  
                }
            }
            
            System.out.println(rs) ; 
        }
    }
}
