import java.util.Scanner ; 
public class B {
    public static void main(String[] args)  {
      Scanner sc = new Scanner(System.in) ; 
      int t = sc.nextInt() ; 
      for(int p=0 ; p<t ; ++p ){
           long n = sc.nextLong() ; 
           long a = sc.nextLong() ; 
           long b = sc.nextLong() ; 
           long rs = 0 ; 
           if( b-a > 0 ){
               long boundry = Math.min(b-a ,n) ; 
                rs += ( boundry*b - (boundry)*(boundry-1)/2 ) ; 
               rs += (n-boundry)*a ; 
           }else {
               rs += a*n ; 
           }
           System.out.println(rs) ;
       }
    }
}