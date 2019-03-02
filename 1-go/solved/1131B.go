package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, a, b, c, pcurr, a1, b1, prev, curr int
	c = 1
	buf := bufio.NewReader(os.Stdin)
	fmt.Fscanf(buf, "%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(buf, "%d %d\n", &a1, &b1)
		prev, curr = max(a, b), min(a1, b1)
		diff := curr - prev
		if diff >= 0 {
			c += diff
			if pcurr != prev {
				c++
			}
		}
		a = a1
		b = b1
		pcurr = curr
	}
	fmt.Printf("%d\n", c)
}
