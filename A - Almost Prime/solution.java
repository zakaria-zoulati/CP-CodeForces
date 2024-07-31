import java.util.Scanner;
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt() ; 
        if( n<=5  ){
            System.out.println(0) ; 
            return ; 
        }
        int rs = 0 ; 
        int[] arr = new int[n+1] ; 
        for(int i=6 ; i<=n ; i++){
            int inter = i ; 
            for(int j=2; j<i ; j++){
                boolean flag = false ; 
                while( (inter%j) == 0 ){
                    inter = inter/j ; 
                    flag = true ; 
                }
                if(flag) arr[i]++ ; 
                if( arr[i] >2 ) break ; 
            }
            if( arr[i] == 2 ) rs++ ;
        }
        System.out.println(rs) ; 
    }
}