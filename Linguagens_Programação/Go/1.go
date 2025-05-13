/*1. Dados um inteiro x e um inteiro não-negativo n, calcular 𝑥
𝑛. */
package main
import "fmt"

func main() {
    var x,n,total int
    
    fmt.Println("Digite um inteiro X: ")
    fmt.Scanln(&x)
    fmt.Println("Digite um inteiro N: ")
    fmt.Scanln(&n)
    total = 1
    for i := 1; i <= n; i++ {
        total *= x
    }
    fmt.Printf("Resultado de %d elevado a %d é: %d\n", x, n, total)
}