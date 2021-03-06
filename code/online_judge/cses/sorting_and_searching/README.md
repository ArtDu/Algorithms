### Sorting and searching


1. [Distinct Numbers](./distinct_numbers.cpp)  
https://cses.fi/problemset/task/1621   
//simple sort

2. [Apartments](./apartments.cpp)  
https://cses.fi/problemset/task/1084  
//two pointers -- from begin

3. [Ferris Wheel](./ferris_wheel.cpp)  
https://cses.fi/problemset/task/1090  
//two pointers -- from begin and end

4. *[Concert Tickets](./concert_tickets.cpp)  
https://cses.fi/problemset/task/1091  
//multiset<greater<>> + lower_bound

5. [Restaurant Customers](./restaurant_customers.cpp)  
https://cses.fi/problemset/task/1619  
//Sweep line(In\Out points)

6. [Movie Festival](./movie_festival.cpp)  
https://cses.fi/problemset/task/1629  
//standart greedy from CLRS

7. *[Sum of Two Values](./sum_of_two_values.cpp)  
https://cses.fi/problemset/task/1640   
//two pointers -- from begin and end
    ![](img/sum_of_two.png)

8. [Maximum Subarray Sum](./maximum_subarray_sum.cpp)  
https://cses.fi/problemset/task/1643  
//Kadane algo or prefix sum

9. *[Stick Lengths](./stick_lengths.cpp)  
https://cses.fi/problemset/task/1074  
//take mid

10. [Playlist](./playlist.cpp)  
https://cses.fi/problemset/task/1141  
//take unique subarray by queue + set(online bin search)

11. [Towers](./towers.cpp)  
https://cses.fi/problemset/task/1073 
//multiset + upper_bound + erase

12. *[Traffic Lights](./traffic_lights.cpp)  
https://cses.fi/problemset/task/1163   
//multiset<classcomparator<>>(by length) + increasing and decreasing sets + erase + rbegin(get max)

12. *[Room Allocation](./room_allocation.cpp)  
https://cses.fi/problemset/task/1164   
//in/out+1 algo + occupied map of rooms + free rooms(was used) 

12. *[Factory Machines](./factory_machines.cpp)  
https://cses.fi/problemset/task/1620  
//binary search(implicit) -- try to hack answer

12. [Tasks and Deadlines](./tasks_and_deadlines.cpp)  
https://cses.fi/problemset/task/1360  
//sort by first + greedy choice(from book)

12. [Reading Books](./reading_books.cpp)  
https://cses.fi/problemset/task/1631  
//two pointers

12. [Sum of Three Values](./sum_of_three_values.cpp)  
https://cses.fi/problemset/task/1641  
//fixed one val. Get two val by two pointers algo from left.

12. [Sum of Four Values](./sum_of_four_values.cpp)  
https://cses.fi/problemset/task/1642  
//fixed two val. Get other two between first two.

12. *[Nearest Smaller Values](./nearest_smaller_values.cpp)  
[simple approach](./nearest_smaller_values_stack.cpp)  
https://cses.fi/problemset/task/1645  
//sort by val and run from left to right and push idx to set
    ```
    or approach from book
    use stack 
    
    At each array position, while the top element is bigger than
    the current element we remove elements from the stack,
    or the stack is empty. 
    
    Then, we report that the top
    element is the nearest smaller element of the current element,
    or if the stack is empty, there is no such element.
    
    Finally, we add the current element to the stack.
    ```
    ![](img/nse.png)

12. [Subarray Sums I](./subarray_sums_1.cpp)  
https://cses.fi/problemset/task/1660  
//two pointers + get plus(from right) or get minus val(from left)
    ![](img/subarray_sum.png)

12. [Subarray Sums II](./subarray_sums_2.cpp)  
https://cses.fi/problemset/task/1661  
    [simple solution:](./subarray_sums_2_simple.cpp)
    ```
    map[prefsum] = count of segments[0, r] with prefsum
    map[0] = 1
    for i in n:
        prefsum += a[i]
        ans += map[prefsum - sum]
        map[prefsum]++
    
    ```
    //(prefix sum) map[sum] = vector of end's ids + hint with lower_bound

12. [Subarray Divisibility](./subarray_divisibility.cpp)  
https://cses.fi/problemset/task/1662  
//like upper task + mod hint
