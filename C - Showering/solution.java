import java.util.Scanner  ;
import java.util.Arrays ;
public class Class1 {
//    public static int  conv( boolean a ){
//        if(a) return 1 ;
//        return 0 ;
//    }
    public static void main( String[] args){
        Scanner sc = new Scanner(System.in) ;
        int t = sc.nextInt() ;
        ok:for(int p=0 ; p<t ; p++){
           int n = sc.nextInt() ;
           int s = sc.nextInt() ;
           int m = sc.nextInt() ;
           int[][] arr = new int[n][2] ;
           for(int i=0 ; i<n; i++){
               arr[i] = new int[2] ;
           }
           for(int i=0; i<n; i++){
               arr[i][0] = sc.nextInt() ;
               arr[i][1] = sc.nextInt() ;
           }
           if( arr[0][0] >= s  || (m-arr[n-1][1]) >= s ){
               System.out.println("YES") ;
           }else {
               for(int i=1 ; i<n ; i++){
                   if( (arr[i][0] - arr[i-1][1] ) >=s ){
                       System.out.println("YES") ;
                       continue ok ;
                   }
               }
               System.out.println("NO") ;
           }

        }
    }
}
