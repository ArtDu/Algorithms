### Dynamic Programming


1. [Dice Combinations](./dice_combinations.cpp)  
https://cses.fi/problemset/task/1633  
//one dim dynamic(number of ways to get n sum) with set {1...6}   
    ```
    dp[0] = 1  
    dp[n] = ways
    ```  

2. [Minimizing Coins](./minimizing_coins.cpp)  
https://cses.fi/problemset/task/1634 
//one dim dynamic(min count of items in chain to get n sum) with given set  
    ```
    dp[0] = 0  
    dp[n] = min items in chain  
    ```

3. [Coin Combinations I](./coin_combinations_1.cpp)  
https://cses.fi/problemset/task/1635  
//one dim dynamic(number of ways to get n sum) with given set
    ```  
    for x:  
        for k:   
    dp[0] = 1  
    dp[n] = ways  
    ```

4. *[Coin Combinations II](./coin_combinations_2.cpp)  
https://cses.fi/problemset/task/1636  
//one dim dynamic(number of ways in sorted order to get n sum) with given set  
    ```  
    for k:  
        for x:   
    dp[0] = 1  
    dp[n] = ways  
    ``` 

5. [Removing Digits](./removing_digits.cpp)  
https://cses.fi/problemset/task/1637  
//one dim dynamic(min items in chain to make zero from n)
    ```
    dp[0] = 0  
    dp[n] = min items in chain  
    ```

6. [Grid Paths](./grid_paths.cpp)  
https://cses.fi/problemset/task/1638  
    ```
    dp[y][x] = number of paths  
    ```
   
7. [Book Shop](./book_shop.cpp)  
https://cses.fi/problemset/task/1158   
//0-1 knapsack  
    ```
    dp[i][x] = maximum number of pages we can get for price at most x, only buying among the first i books.
    ```
 
8. *[Array Description](./array_description.cpp)  
https://cses.fi/problemset/task/1746  
//dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.

9. [Edit Distance](./edit_distance.cpp)  
https://cses.fi/problemset/task/1639  
    ```
    dp[0][i] = i
    dp[i][0] = i
    dp[i][j] = dp[i - 1][j - 1], if s1[i] == s2[j]  
    dp[i][j] = min(dp[i - 1][j - 1],  
                   dp[i - 1][j],  
                   dp[i][j - 1])
                    + 1,         if s1[i] != s2[j]
    ```  

10. *[Rectangle Cutting](./rectangle_cutting.cpp)  
https://cses.fi/problemset/task/1744  
//like matrix multiply from CLRS
    ```
    dp[h][w] = minimum number of cuts needed to cut a w x h piece into squares.
    dp[h][w] = min(mn, dp[h][k] + dp[h][w - k] + 1)
    and for height too ---//---
    ```

11. [Money Sums](./money_sums.cpp)  
https://cses.fi/problemset/task/1745  
//0-1 knapsack from book
    ```
    dp[i][x] = true if it is possible to make x using the first i coins, false otherwise.
    ```

12. [Removal Game](./removal_game.cpp)  
https://cses.fi/problemset/task/1097   
    ```
    dp[l][r] = max score for first player in l...r segment 
    remove_left = (sum[l + 1][r] - val[l + 1][r]) + v[l];
    remove_right = (sum[l][r - 1] - val[l][r - 1]) + v[r];
    dp[l][r] = max(remove_left, remove_right);
    * instead sum[l][r] use prefix sum
    ```


12. ?[Two Sets II](./two_sets_2.cpp)  
https://cses.fi/problemset/task/1093   
    ```
    dp[i][x] = number of ways to make sum x using subsets of the numbers 1..i .
    ``` 

12. *[Increasing Subsequence](./increasing_subsequence.cpp)  
https://cses.fi/problemset/task/1145  
//nlogn solution with lower_bound
