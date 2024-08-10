import java.util.Scanner ; 
public class B {
    public static void main(String[] args)  {
      Scanner sc = new Scanner(System.in) ; 
      int t = sc.nextInt() ; 
      sc.nextLine() ; 
      for(int p=0 ; p<t ; ++p ){
          String all = sc.nextLine().trim() ; 
          String[] arr = all.split(" ") ; 
          String L = arr[0] ; 
          String R = arr[1] ;
          int n = L.length() ; 
          int m = R.length() ; 
          while( n<m ){
              L = "0"+L ; 
              n++ ;
          }
          while( m<n ){
              R = "0"+R ; 
              m++ ; 
          }
          int rs = 0 ; 
          boolean flag = false ; 
          for( int i= 0; i<m ; ++i ){
              if( flag  ){
                  rs += 9 ; 
                  continue ; 
              }
             if( L.charAt(i) < R.charAt(i)  ){
                flag = true ; 
             }
             rs += Math.abs( L.charAt(i) - R.charAt(i) ) ; 
          }
          System.out.println(rs)  ;
      }
    }
}
