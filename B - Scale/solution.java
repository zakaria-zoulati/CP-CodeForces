import java.util.Scanner ; 

public class A {
    public static void main(String[] args ){
        Scanner sc = new Scanner(System.in) ; 
        int t = sc.nextInt()  ;
        for(int c=0 ; c<t ; c++){
            int n = sc.nextInt() ; 
            int k = sc.nextInt() ; 
            sc.nextLine() ; 
            String[] arr = new String[n] ; 
            for(int i=0 ; i<n ; i++){
                arr[i] = sc.nextLine() ; 
            }
            for(int i=0 ; i<n ; i= i+k ){
                StringBuilder inter = new StringBuilder() ; 
                for(int j=0 ; j<n ; j=j+k){
                    inter.append( arr[i].charAt(j) ) ; 
                }
                System.out.println(inter) ; 
            }
                
        }
    }
}