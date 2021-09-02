package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"time"
)

func twoSum(nums []int, target int) float64 {
	start := time.Now()

	m := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		diff := target - nums[i]
		if _, ok := m[diff]; ok {
			return float64(time.Since(start).Milliseconds())
			// fmt.Println(time.Since(start).Seconds() * 1000)
			// return []int{val, i}
		}
		m[nums[i]] = i
	}
	return float64(time.Since(start).Milliseconds())
	// return []int{0, 0} // need return for golang
}

func main() {
	file, err := os.Open("testcase.txt")
	if err != nil {
		defer file.Close()
	}
	scanner := bufio.NewScanner(file)

	scanner.Scan()

	strs := scanner.Text()
	trimmed := strings.Trim(strs, "[]")
	strs_split := strings.Split(trimmed, ",")
	ints := make([]int, len(strs_split))
	for i, s := range strs_split {
		ints[i], _ = strconv.Atoi(s)
	}

	scanner.Scan()
	target, _ := strconv.Atoi(scanner.Text())
	var times []float64
	iters := 100
	sample_size := 1000
	for i := 0; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(ints))))
		// fmt.Print("ind : ", prop, ind)
		md := 0.0
		for j := 0; j < sample_size; j++ {
			md += float64(twoSum(ints[:ind], target))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)
}
