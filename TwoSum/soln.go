package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func twoSum(nums []int, target int) []int {
	start := time.Now()

	m := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		diff := target - nums[i]
		if val, ok := m[diff]; ok {
			fmt.Println(time.Since(start).Seconds() * 1000)
			return []int{val, i}
		}
		m[nums[i]] = i
	}
	return []int{0, 0} // need return for golang
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

	for i := 0; i < 10; i++ {
		fmt.Println(twoSum(ints, target))
	}

}
