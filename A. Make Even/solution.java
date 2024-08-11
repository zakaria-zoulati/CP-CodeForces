import java.util.Scanner ; 
public class B {
    public static void main(String[] args)  {
      Scanner sc = new Scanner(System.in) ; 
      int t = sc.nextInt() ; 
      ok :for(int p=0 ; p<t ; ++p ){
           int n = sc.nextInt() ; 
           if( n % 2 == 0  ){
               System.out.println(0) ; 
               continue ; 
           }
         
           String inter = String.valueOf(n) ; 
          if( ( inter.charAt(0) - '0' ) % 2 == 0  ){
              System.out.println(1) ; 
              continue ; 
          }
           int len = inter.length() ; 
           for(int i=1 ; i<len-1 ; ++i){
               if( ( inter.charAt(i) - '0' ) % 2 == 0  ){
                   System.out.println( 2 ) ; 
                   continue ok ; 
               }
           }
           System.out.println(-1) ; 
       }
    }
}