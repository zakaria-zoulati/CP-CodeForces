import java.util.* ; 
public class B {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        int n = sc.nextInt() ; 
        int[] nums = new int[n] ; 
        for( int i=0 ; i<n ; ++i ){
            nums[i] = sc.nextInt() ; 
        }
        long rs = 1  ; 
        int i=0 ; 
        while( i<n && nums[i] == 0 ){
            i++ ; 
        }
        if( i == n ){
            System.out.println(0) ; 
            return  ; 
        }
        for( ; i<n ; ++i ){
            int count = 1 ; 
            while( i+1<n && nums[i+1] == 0 ){
                ++i ; 
                count++  ;
            }
            if( i+1<n && nums[i+1] == 1 ){
                rs *= count ; 
            }
        }
        
        System.out.println(rs) ;
    }   
}