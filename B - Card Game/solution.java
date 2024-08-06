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
        for(int p=0 ; p<t ; p++){
            int[] a = new int[2] ;
            int[] b = new int[2] ;
            a[0] = sc.nextInt() ;
            a[1] = sc.nextInt() ;
            b[0] = sc.nextInt() ;
            b[1] = sc.nextInt()  ;
            int rs = 0 ;

            for(int i=0 ; i<2 ; i++){
                for(int j=0 ; j<2 ; j++){
                    int r = 0 ; int l = 0 ;
                    if( a[i] > b[j] ) r++ ;
                    else if( a[i] < b[j]  ) l++;
                    if( a[1-i] > b[1-j] ) r++;
                    else if( a[1-i] < b[1-j] ) l++ ;
                    if( r > l ) rs++ ;
                }
            }

            System.out.println(rs) ;
        }
    }
}
