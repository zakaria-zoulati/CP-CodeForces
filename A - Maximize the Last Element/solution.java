import java.util.Scanner ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in)  ; 
        int t = sc.nextInt() ; 
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            int[] arr = new int[n] ; 
            for(int i=0 ; i<n; i++){
                arr[i] = sc.nextInt() ; 
            }
            int rs = arr[0] ; 
            for(int i=0 ; i<n ; i=i+2){
                rs = Math.max( rs , arr[i] ) ; 
            }
            System.out.println(rs) ; 
        }
    }
}