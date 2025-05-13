/*4. Escreva um programa que converta temperaturas de Fahrenheit para Celsius, 
seguindo a equação 𝐶 = (𝐹−32)×5/9. */
package main
import "fmt"

func main() {
    var F,C int

    fmt.Println("Digite uma temperatura em Fahrenheit: ")
    fmt.Scanln(&F)
    
    C = (F - 32)*5 / 9
    fmt.Printf("O valor de %d graus em Fahrenheit equivale a %d graus em Celsius",F,C)
}

