// code_report Solution
// Video Link: https://youtu.be/9eBNy3wKcKc
// Problem Link: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/toy-box-5044b3ed/

package main
 
import "fmt"

func main() {
    var n, m, p, b int
    fmt.Scan(&n, &m)
    a := make([]int, m+1)
    for i := 0; i < n; i++ {
        fmt.Scan(&p, &b)
        if p > a[b] {
            a[b] = p
        }
    } 
    sum := 0
    for _, e := range a {
        sum += e
    }
    fmt.Println(sum)
}
