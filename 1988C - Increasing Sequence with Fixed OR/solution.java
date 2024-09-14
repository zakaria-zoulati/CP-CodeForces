import java.util.Scanner  ;
import java.util.ArrayList ; 
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; ++c){
            long n = sc.nextLong() ; 
            ArrayList<Long> arr = new ArrayList<>() ; 
            for(long i=62 ; i>=0 ; --i){
                long x = 1L << i ; 
                if( ( ( x & n ) == x ) && x != n  ){
                    arr.add( n - x ) ; 
                }
            }
            arr.add(n) ; 
            System.out.println( arr.size() ) ; 
            for(int i = 0 ; i< arr.size() ; ++i  ){
                System.out.print( arr.get(i) + " ") ; 
            }
            System.out.println("") ; 
        }
    }
}
