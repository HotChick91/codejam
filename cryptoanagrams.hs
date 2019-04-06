{-# LANGUAGE ScopedTypeVariables #-}

import Control.Monad
import Data.List
import Data.Maybe

import Data.Map.Strict (Map)
import qualified Data.Map.Strict as M

infixl 4 <$$>
(<$$>) :: (Functor f, Functor g) => (a -> b) -> f (g a) -> f (g b)
(<$$>) = fmap . fmap

calcSuffix :: Integer -> [Integer] -> [Integer]
calcSuffix _ [] = []
calcSuffix leGcd (prod:prods) = q : calcSuffix q prods
    where
    q = prod `quot` leGcd

solve :: Int -> IO ()
solve t = do
    [_n, _l] :: [Int] <- read <$$> words <$> getLine
    prods :: [Integer] <- read <$$> words <$> getLine
    let firstNeq :: Int = fromJust $ findIndex (\ (a, b) -> a /= b) $ zip prods (tail prods)
    let secondNeq :: Int = firstNeq + 1
    let firstProd :: Integer = prods !! firstNeq
    let leGcd :: Integer = gcd firstProd (prods !! secondNeq)
    let prefix :: [Integer] = take (firstNeq + 2) $ drop (firstNeq `mod` 2) $ concat $ repeat [firstProd `div` leGcd, leGcd]
    let suffix :: [Integer] = calcSuffix leGcd (drop secondNeq prods)
    let full :: [Integer] = prefix ++ suffix
    let mapping :: Map Integer Char = M.fromList $ zip (nub $ sort full) ['A'..]
    let plaintext :: String = map (mapping M.!) full
    putStrLn $ "Case #" ++ show t ++ ": " ++ plaintext

main :: IO ()
main = do
    t :: Int <- readLn
    forM_ [1..t] solve
