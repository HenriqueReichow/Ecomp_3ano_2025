main :: IO ()
main = do
    putStrLn "Digite um número inteiro positivo:"
    n <- readLn
    if isPrime n
        then putStrLn "É primo!"
        else putStrLn "Não é primo."

isPrime :: Int -> Bool
isPrime n
    | n < 2 = False
    | otherwise = null [x | x <- [2..n-1], n `mod` x == 0]
