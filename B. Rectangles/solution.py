n , m = list( map( int , input().split() ) )  

rows = [0]*n  
cols = [0]*m 

rs = -n*m 

for i in range(n) : 
    arr = list( map( int , input().split() ) )
    for j in range(m) : 
        rows[i] += arr[j] 
        cols[j] += arr[j]
        
        

for i in range(n):
    rs += ( ( 1 << rows[i] ) - 1 ) 
    rs += ( (  1 << ( m - rows[i] ) ) - 1 )

for j in range(m):
    rs += ( ( 1 << cols[j] ) - 1 ) 
    rs += ( (  1 << ( n - cols[j] ) ) - 1 )


print( rs )  