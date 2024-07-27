import java.util.Scanner;
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        loopy : for(int c=1 ; c<=t ; c++){
            int m = sc.nextInt() ; 
            sc.nextLine();
            String r1 = sc.nextLine().trim() ; 
            String r2 = sc.nextLine().trim() ; 
            int[] dp = new int[m] ; 
            for(int i=0 ; i<m ; i++){
                if( r1.charAt(i) == 'W' && r2.charAt(i) == 'W' ){
                    System.out.println("NO")  ;
                    continue loopy ; 
                }else if( r1.charAt(i)=='B' &&  r2.charAt(i)=='B' ){
                    if(i==0 || dp[i-1] == 0 ) continue  ;
                    else if( dp[i-1]==1 ) dp[i] = 2  ;
                    else dp[i] = 1  ;
                }else if(r1.charAt(i) == 'B' ){
                    if( i==0  || dp[i-1]<=1 ) dp[i] = 1 ; 
                    else {
                         System.out.println("NO")  ;
                         continue loopy ; 
                    }
                }else {
                    if( i==0  || dp[i-1] != 1  ) dp[i] = 2 ; 
                    else {
                         System.out.println("NO")  ;
                         continue loopy ; 
                    }
                }
            } 
            System.out.println("YES") ; 
        }
    }
}
