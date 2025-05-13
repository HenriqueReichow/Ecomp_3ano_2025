/*2. Dado um inteiro positivo n, verificar se n é primo. */
package main
import "fmt"

func main() {
    var n,totalMult int
    
    fmt.Println("Digite um inteiro N: ")
    fmt.Scanln(&n)
    totalMult = 0
    
    for i := 1; i <= n; i++ {
        if n%i==0{
            totalMult++
        }
        
    }
    if totalMult == 2{
        fmt.Printf("Eh primo")
        
    } else {
        fmt.Printf("Não eh primo")
    }

}