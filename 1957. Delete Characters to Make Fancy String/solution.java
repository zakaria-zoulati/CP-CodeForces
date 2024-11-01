class Solution {
    public String makeFancyString(String s) {
        int n = s.length() ;
        StringBuilder rs = new StringBuilder() ; 
        for( int i=0 ; i<n; ++i ){
            char curr = s.charAt(i) ; 
            rs.append( curr ) ; 
            if( i+1 < n && s.charAt(i+1)==curr){
                rs.append( curr ) ; 
                while( i+1<n && s.charAt(i+1) == curr ) ++i ; 
            }
        }
        return rs.toString() ; 
    }
}