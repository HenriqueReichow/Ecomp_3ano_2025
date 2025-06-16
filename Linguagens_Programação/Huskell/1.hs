main :: IO ()
main = do
    putStrLn "Digite o valor de x:"
    x <- readLn
    putStrLn "Digite o valor de n:"
    n <- readLn
    print ( x ^ n)