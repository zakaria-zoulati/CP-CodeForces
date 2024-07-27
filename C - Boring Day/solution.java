import java.util.Scanner;
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt() ; 
        for(int c=1 ; c<=t ; c++){
            int n = sc.nextInt() ; 
            int l = sc.nextInt() ; 
            int r = sc.nextInt() ; 
            int index = 0  ;
            long current = 0 ; 
            long rs = 0  ;
            long[] dp = new long[n] ; 
            for(int i=0 ; i<n ; i++){
                dp[i] = sc.nextLong()  ;
                current += dp[i] ; 
                if( current> r ){
                    int j = index ; 
                    while( current > r && j<i ){
                        current -= dp[j] ; 
                        j++ ;
                    }
                    if( current >= l && current <=r ){
                        rs++ ; 
                        index = i+1 ; 
                        current = 0 ; 
                    }
                    else if( current > r ){
                        current = 0 ; 
                        index = i+1 ; 
                    }
                    else{
                        index = j; 
                    }
                }
                else if( current >=l ){
                    rs++ ; 
                    current =  0 ;
                    index = i+1 ; 
                }
                else {
                    
                }
            }
            System.out.println(rs) ; 
        }
}
}
