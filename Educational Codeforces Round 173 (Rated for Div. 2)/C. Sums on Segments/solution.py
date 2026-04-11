for _ in range( int(input()) ) : 
    n = int( input() ) 
    a = list( map( int , input().split() ) ) 
    
    l1,r1 = 0,0 
    l2,r2 = 2*10**9 , -2*10**9 
    
    pr = 0  
    mnl,mxl = 0,0 
    mnr,mxr = 2*10**9 , -2*10**9
    
    for i in range(n):
        pr += a[i] 
        if a[i] != -1 and a[i] != 1 : 
            mnr,mxr=mnl,mxl
            mnl,mxl=pr,pr
            
        l1 = min( l1 , pr - mxl )
        r1 = max( r1 , pr - mnl )
        l2 = min( l2 , pr - mxr ) 
        r2 = max( r2 , pr - mnr ) 
        
        mnl = min( mnl , pr ) 
        mxl = max( mxl , pr ) 
        
    res = [] 
    if l2 > r1 : 
        res = list( range( l1 , r1+1) ) + list( range( l2 , r2+1) )
    elif r2 < l1 : 
        res = list( range(l2,r2+1) ) + list( range( l1 , r1+1) ) 
    else :
        res = list( range( min(l1,l2) , max(r1,r2)+1) )   
        
    print( len(res) ) 
    print( *res )  
        