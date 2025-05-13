/*5. Dados dois strings (um contendo uma frase e outro contendo uma palavra), 
determine
o número de vezes que a palavra ocorre na frase.
Exemplo:
Para a palavra ANA e a frase :
ANA E MARIANA GOSTAM DE BANANA
Resp: Temos que a palavra ANA ocorre 4 vezes na frase.. */
package main
import "fmt"

func main() {
    var nome string = "ANA"
    var frase string = "ANA E MARIANA GOSTAM DE BANANA"
    
    var nro int = 0
    for i := 0; i <= len(frase)-len(nome); i++ {
        if frase[i:i+len(nome)] == nome {
            nro++
        }
    }
    
    fmt.Printf("%d",nro)
}