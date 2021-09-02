package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"time"
)

func isValid(s string) float64 {
	start := time.Now()

	var stack []string

	for i := 0; i < len(s); i++ {
		l := string(s[i])
		if l == "(" || l == "[" || l == "{" {
			stack = append(stack, l)
			continue
		}
		if len(stack) == 0 {
			return 0
		}
		p := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if l == ")" && p != "(" {
			return 0
		}
		if l == "]" && p != "[" {
			return 0
		}
		if l == "}" && p != "{" {
			return 0
		}
	}
	return float64(time.Since(start).Milliseconds())
	// fmt.Println(time.Since(start).Seconds()*1000, " ms")
	// return len(stack) == 0
}

func main() {
	file, err := ioutil.ReadFile("testcase.txt")
	if err != nil {
		fmt.Print(err)
	}

	vars := string(file)

	var times []float64
	iters := 100
	sample_size := 1000
	for i := 0; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(vars))))
		// fmt.Print("ind : ", prop, ind)
		md := 0.0
		for j := 0; j < sample_size; j++ {
			md += isValid(string(vars[:ind]))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)
}
