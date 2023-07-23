/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func allPossibleFBT(n int) []*TreeNode {
    if n % 2 == 0 {
        return []*TreeNode{}
    }

    if n == 1{
        return []*TreeNode{&TreeNode{0, nil, nil}}
    } 

    Ans := []*TreeNode{}
    
    for i := 1; i < n; i++ {        
        leftTree := allPossibleFBT(i)
        rightTree := allPossibleFBT(n-i-1)
        
        for _, left := range leftTree {
            for _, right := range rightTree {
                Ans = append(Ans, &TreeNode{0, left, right})
            }
        }
    }
    
    return Ans
}
