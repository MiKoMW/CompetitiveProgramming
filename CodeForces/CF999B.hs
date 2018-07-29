k :: Int -> Int -> String -> String
k a n st | (a == n) = reverse(st)
         | ((mod a n) == 0) = k a (n+1) (l n "" st)
         | otherwise = k a (n+1) st



solve :: String -> String
solve text = let (h:la:ls) = lines text
             in   k (read h) 1 la
             
l :: Int -> String -> String -> String
l 0 st str = (st) ++ str
l a st str = l (a-1) ((head str): st) (tail str)

main :: IO ()
main = interact solve