import java.util.Scanner ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner(System.in)  ; 
        int t = sc.nextInt() ; 
        sc.nextLine() ; 
        for(int c=0 ; c<t ; c++){
            String in = sc.nextLine().trim() ;  
            int n = in.length() ; 
            StringBuilder rs = new StringBuilder() ; 
            rs.append( in.charAt(0) ) ; 
            boolean flag = true ; 
            for(int i=1 ; i<n ; i++){
                if( flag &&   in.charAt(i) == in.charAt(i-1) ){
                    if( in.charAt(i) == 'a' ){
                        rs.append("ba") ; 
                        flag = false  ; 
                    }
                    else {
                        rs.append("a") ; 
                        rs.append(in.charAt(i) ) ; 
                        flag = false ; 
                    }
                }else {
                    rs.append( in.charAt(i)) ; 
                }
            }
            if( flag ){
                if( in.charAt(n-1) == 'a' ){
                    rs.append('b') ; 
                }else {
                    rs.append('a') ; 
                }
            }
            System.out.println(rs) ; 
        }
    }

}