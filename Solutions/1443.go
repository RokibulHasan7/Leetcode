func dfs(currNode int, parentNode int, hasApple []bool, adj [][]int) int {
    totalTime, childTime := 0, 0 
    for i := 0; i < len(adj[currNode]); i++ {
        child := adj[currNode][i]
        if child == parentNode {
            continue
        }
        childTime = dfs(child, currNode, hasApple, adj)
        if childTime > 0 || hasApple[child] == true {
            totalTime += childTime + 2
        }
    }

    return totalTime
}
func minTime(n int, edges [][]int, hasApple []bool) int {
    adj := make([][]int, n)
    sz := len(edges)

    for i := 0; i < sz; i++ {
        u := edges[i][0]
        v := edges[i][1]
        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }

    return dfs(0, - 1, hasApple, adj) 
}

/*
func dfs(currNode int, hasApple []bool, adj [][]int, visited []bool) int {
    cnt := 0
    visited[currNode] = true
    for i := 0; i < len(adj[currNode]); i++ {
        v := adj[currNode][i]
        if !visited[v] {
            cnt += dfs(v, hasApple, adj, visited)
        }
    }
    if currNode != 0 && (hasApple[currNode] == true || cnt > 0) {
        cnt += 1
    }
    return cnt
}
func minTime(n int, edges [][]int, hasApple []bool) int {
    adj := make([][]int, n)
    sz := len(edges)
    
    for i := 0; i < sz; i++ {
        u := edges[i][0]
        v := edges[i][1]
        adj[u] = append(adj[u], v)
        adj[v] = append(adj[v], u)
    }
    visited := make([]bool, n)
    return dfs(0, hasApple, adj, visited) * 2
}
*/
