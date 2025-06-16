main :: IO ()
main = do
    putStrLn "Digite um número inteiro positivo:"
    n <- readLn
    print (take n [1,3..])