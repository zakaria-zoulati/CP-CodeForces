import java.util.*; 
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = s.length() ; 
        
        int[] arr = new int[n/2] ; 
        int m = sc.nextInt() ; 
        while( m-- > 0 ){
            int ai = sc.nextInt() ; 
            arr[ Math.min( ai-1 , n-ai ) ]++ ; 
        }
        
        char[] chars = s.toCharArray() ; 
        boolean swap = false ; 
        for( int i=0 ; i<n/2 ; ++i ){
            if( arr[i] % 2 == 1 ){
                swap = !swap ;  
            }
            if( swap ){
                char temp = chars[i] ; 
                chars[i] = chars[ n-1 -i] ; 
                chars[n-1-i] = temp ; 
            }
        }
        System.out.println( new String( chars ) ) ; 
    }
}
