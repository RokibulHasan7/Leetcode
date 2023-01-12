func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func maxPoints(points [][]int) int {
    sz := len(points)
    ans := 1
    for i := 0; i < sz; i++ {
        x1 := points[i][0]
        y1 := points[i][1]
        mp := make(map[float64]int)
        for j := 0; j < sz; j++ {
            if i == j {
                continue
            }

            x2 := points[j][0]
            y2 := points[j][1]
            // If denominator is 0 we will get runtime error
            if x2 - x1 == 0 {
                mp[math.MaxFloat64]++
                continue
            }

            slope := (float64(y2) - float64(y1)) / (float64(x2) - float64(x1))
            mp[slope]++
        }

        for _, val := range mp {
            ans = max(ans, val + 1)
        }
    }

    return ans
}

// Find the slope and count it
// Return the max point in a single slope
