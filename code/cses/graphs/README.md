### Graphs


1. [Counting Rooms](./counting_rooms.cpp)  
https://cses.fi/problemset/task/1192     
    ```
    dfs -- in grid
    ```  

2. [Labyrinth](./labyrinth.cpp)  
https://cses.fi/problemset/task/1193   
    ```
    0-1 bfs -- shortest path in grid by 
    ```

3. [Building Roads](./building_roads.cpp)  
https://cses.fi/problemset/task/1666  
    ```  
    dfs -- check all components 
    and build connection between them
    ```

4. [Message Route](./message_route.cpp)  
https://cses.fi/problemset/task/1667    
    ```  
    bfs -- in graph and retrieve path
    ``` 

5. [Building Teams](./building_teams.cpp)  
https://cses.fi/problemset/task/1668  
    ```
    dfs 2 colors -- check if graph is bipartite 
    ```

6. [Round Trip](./round_trip.cpp)  
https://cses.fi/problemset/task/1669  
    ```
    dfs -- check cycle with 3 and more nodes  
    ```
   
7. [Monsters](./monsters.cpp)  
https://cses.fi/problemset/task/1194     
    ```
    bfs -- start bfs from borders and check
    if path to hero is shorter then path to monster 
    ```
 
8. [Shortest Routes I](./shortest_routes_1.cpp)  
https://cses.fi/problemset/task/1671  
    ```
    dijkstra 
    ```

9. [Shortest Routes II](./shortest_routes_2.cpp)  
https://cses.fi/problemset/task/1672  
    ```
    floyd-warshall
    ```  

10. [High Score](./high_score.cpp)  
https://cses.fi/problemset/task/1673  
    ```
    bellman-ford -- get max path 
    ```

11. *[Flight Discount](./flight_discount.cpp)  
https://cses.fi/problemset/task/1195  
    ```
    dijkstra -- start from begin and from end.
    Loop in edges and get
    min(frontDijkstra[u] + w/2 + revDijkstra[v]);
    ```

12. [Cycle Finding](./cycle_finding.cpp)  
https://cses.fi/problemset/task/1197   
    ```
    bellman-ford -- check negative cycle
    ```

12. *[Flight Routes](./flight_routes.cpp)  
https://cses.fi/problemset/task/1196   
    ```
    dijkstra -- k shortest path
    Each vertex is visited atmax k times in k routes.
    ``` 

12. *[Round Trip II](./round_trip_2.cpp)  
https://cses.fi/problemset/task/1678  
    ```
    dfs -- check cycle in directed graph.
    Use path vec instead visited
    ```
   
12. [Course Schedule](./course_schedule.cpp)  
https://cses.fi/problemset/task/1679  
    ```
    topo sort
    ``` 
       
12. [Longest Flight Route](./longest_flight_route.cpp)  
https://cses.fi/problemset/task/1680  
    ```
    topo sort + dp
    ``` 
    
12. [Game Routes](./game_routes.cpp)  
https://cses.fi/problemset/task/1681  
    ```
    topo sort + dp
    ``` 
    
12. *[Investigation](./investigation.cpp)  
https://cses.fi/problemset/task/1202  
    ```
    dijkstra + dp
    ``` 
    
12. *[Planets Queries I](./planets_queries_1.cpp)  
https://cses.fi/problemset/task/1750  
    ```
    successor/functional graph -- get node after k steps
    ``` 
    
12. **[Planets Queries II](./planets_queries_2.cpp)  
https://cses.fi/problemset/task/1160  
    ```
    successor/functional graph + scc
    ```
    
12. *[Planets Cycles](./planets_cycles.cpp)  
https://cses.fi/problemset/task/1751  
    ```
    scc + dp
    ```
    
12. [Road Reparation](./road_reparation.cpp)  
https://cses.fi/problemset/task/1675  
    ```
    kruskal algo -- min spanning tree  
    ```
    
12. [Road Construction](./road_construction.cpp)  
https://cses.fi/problemset/task/1676  
    ```
    kruskal algo -- online check components size and max comp
    ```  
  
12. [Flight Routes Check](./flight_routes_check.cpp)  
https://cses.fi/problemset/task/1682  
    ```
    scc -- check is one scc in graph
    if no, print any new edge from one scc to another  
    ```


