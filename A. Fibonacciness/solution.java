import java.util.* ; 

public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
            int[] arr = new int[5] ; 
            int rs = 0 ; 
            for(int i=0 ; i<2 ; ++i){
                arr[i] = sc.nextInt() ; 
            }
            for(int i=3 ; i<5 ; ++i){
                arr[i] = sc.nextInt() ; 
            }
            
            // The first case 
            arr[2] = arr[0] + arr[1] ; 
            rs = Math.max( rs , valid(arr) ) ; 
            
            // The second case 
            arr[2] = arr[3] - arr[1] ; 
            rs = Math.max( rs , valid(arr) ) ; 
            
            // The Third Case 
            arr[2] = arr[4] - arr[3] ; 
            rs = Math.max( rs , valid(arr) ) ; 
            
            System.out.println(rs) ; 
        }
    }
    public static int valid( int[] arr ){
        int rs = 0 ; 
        for(int i=2 ; i<5 ; ++i){
            if( arr[i] == arr[i-1] + arr[i-2] ) ++rs ;
        }
        return rs ; 
    }
}