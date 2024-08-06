import java.util.Scanner  ;
public class Class1 {
    public static void main( String[] args){
        Scanner sc = new Scanner(System.in) ;
        int t = sc.nextInt() ;
        for(int p=0 ; p<t ; p++){
            int n = sc.nextInt() ;
            int rs = n/10 + n%10 ;
            System.out.println(rs) ;
        }
    }
}
