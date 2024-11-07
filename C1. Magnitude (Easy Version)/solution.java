import java.util.Scanner ; 

public class C1 {
   
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt() ; 
        while( t-- > 0 ){
           int n = sc.nextInt() ; 
           int[] arr = new int[n] ; 
           for(int i=0;i<n; ++i){
               arr[i] = sc.nextInt() ; 
           }
           long sum = 0L ; 
           long min = 0L ; 
           for( int num : arr ){
               sum += num ; 
               min = Math.min( min , sum ) ; 
           }
           long rs = sum - 2*min ; 
           System.out.println(rs) ; 
        }
    }
}
