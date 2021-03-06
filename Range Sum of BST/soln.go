package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"sort"
	"strconv"
	"strings"
	"time"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rangeSumBST(root *TreeNode, low int, high int) float64 {
	var v int = 0
	start := time.Now()

	if root == nil {
		return 0
	}

	v = rec(root, low, high, v)
	return float64(time.Since(start).Milliseconds())
	// fmt.Println(time.Since(start).Seconds() * 1000)
	// return v
}

func rec(node *TreeNode, L int, R int, v int) int {
	if L <= node.Val && node.Val <= R {
		v += node.Val
	}
	if node.Left != nil {
		v = rec(node.Left, L, R, v)
	}
	if node.Right != nil {
		v = rec(node.Right, L, R, v)
	}
	return v
}

func toBST(arr []int) *TreeNode {
	if len(arr) == 0 {
		return nil
	}
	root := &TreeNode{}
	root.Val = arr[len(arr)/2]
	root.Left = toBST(arr[:len(arr)/2])
	root.Right = toBST(arr[len(arr)/2+1:])

	return root
}

func main() {
	f, err := ioutil.ReadFile("testcase.txt")
	if err != nil {
		fmt.Print(err)
	}

	fstr := string(f)
	vars := strings.Split(fstr, "\n")
	low, _ := strconv.Atoi(string([]rune(vars[1])[:len(vars[1])-1]))
	high, _ := strconv.Atoi(vars[2])

	trimmed := strings.Trim(vars[0], "[]")
	strs_split := strings.Split(trimmed, ",")
	ints := make([]int, len(strs_split))
	for i, s := range strs_split {
		if s == "null" {
			ints[i] = 0
		} else {
			ints[i], _ = strconv.Atoi(s)
		}
	}

	sort.Slice(ints[:], func(i, j int) bool {
		return ints[i] < ints[j]
	})

	var times []float64
	iters := 100
	sample_size := 1000
	for i := 0; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(ints))))
		md := 0.0
		for j := 0; j < sample_size; j++ {
			tree := toBST(ints[:ind])
			md += float64(rangeSumBST(tree, low, high))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)

}
