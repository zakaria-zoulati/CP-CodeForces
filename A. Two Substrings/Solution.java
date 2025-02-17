import java.util.* ; 
public class A {
    public static void main( String[] args ){
        Scanner sc = new Scanner( System.in ) ; 
        String s = sc.nextLine() ; 
        int n = s.length() ; 
        // The First Case The Pattern * AB * BA
        int l = 0 ; 
        int r = n-1 ;
        while( l+2 < r ){
            if( s.charAt(l) == 'A'
                &&  s.charAt(l+1) == 'B'
                && s.charAt(r) == 'A'
                && s.charAt(r-1) == 'B'
            ){
                System.out.println("YES") ; 
                return ; 
            }
            else if( s.charAt(l) != 'A' || s.charAt(l+1) != 'B' ){
                l++ ; 
            }else {
                r-- ; 
            }
        }
        
        
        // The second case The Pattern * BA * AB
        l = 0 ;
        r = n-1 ; 
        while( l+2 < r ){
            if( s.charAt(l) == 'B'
                &&  s.charAt(l+1) == 'A'
                && s.charAt(r) == 'B'
                && s.charAt(r-1) == 'A'
            ){
                System.out.println("YES") ; 
                return ; 
            }
            else if( s.charAt(l) != 'B' || s.charAt(l+1) != 'A' ){
                l++ ; 
            }else {
                r-- ; 
            }
        }
        // No Pattern Found 
        System.out.println("NO") ; 
    }   
}