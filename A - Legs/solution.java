import java.util.Scanner ; 

public class A {
    public static void main(String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt()  ;
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            int rs = n/4 + ( n%4==0 ? 0 :1 ) ;
            System.out.println(rs) ; 
        }
    }
}