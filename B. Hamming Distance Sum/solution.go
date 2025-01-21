package main

import "fmt"

func main() {
    var (
        result = 0
        b string
        a string
    )
    fmt.Scan(&b)
    fmt.Scan(&a)
    n := len(a)
    m := len(b)
    prefix := make([]int, n+1)
    for i := 0; i < n; i++ {
        prefix[i+1] = prefix[i]
        if a[i] == '1' {
            prefix[i+1]++
        }
    }
    interval := n - m + 1
    for i := 0; i < m; i++ {
        ones := prefix[n-m+i+1] - prefix[i]
        if b[i] == '0' {
            result += ones
        } else {
            result += interval - ones
        }
    }
    fmt.Println(result)
}