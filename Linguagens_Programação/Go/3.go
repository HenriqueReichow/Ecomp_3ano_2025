/*3. Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.*/
package main
import "fmt"

func main() {
    var n int
    var cont int = 1
    fmt.Println("Digite um inteiro N: ")
    fmt.Scanln(&n)
    
    for i := 1; i <= n; i ++ {
        fmt.Printf("%d ", cont)
        cont += 2
    }
}