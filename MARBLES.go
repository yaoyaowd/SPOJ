package main

import (
    "fmt"
)

func main() {
    var T, n, k int
    var ans int64

    fmt.Scanf("%d", &T)
    for i := 0; i < T; i++ {
        fmt.Scanf("%d%d", &n, &k)
        n = n - 1
        k = k - 1
        ans = 1
        for j := n - k + 1; j <= n; j++ {
            ans = ans * int64(j) / int64(j - n + k)
        }
        fmt.Println(ans)
    }
}
