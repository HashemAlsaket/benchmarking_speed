package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"time"
)

func lengthOfLongestSubstring(s string) float64 {
	start := time.Now()

	n := len(s)
	i := 0
	j := 0
	mx := 0
	m := make(map[string]int)

	for j < n {
		if mx < j-i {
			mx = j - i
		}
		if _, ok := m[string(s[j])]; ok {
			if m[string(s[j])] > 0 {
				for m[string(s[j])] > 0 {
					m[string(s[i])] = m[string(s[i])] - 1
					i = i + 1
				}
			}
		}
		m[string(s[j])] = m[string(s[j])] + 1
		j = j + 1
	}
	if mx < j-i {
		mx = j - i
	}
	// fmt.Println(time.Since(start).Seconds() * 1000)
	// return mx
	return float64(time.Since(start).Milliseconds())
}
func main() {
	vars := []string{}
	file, err := os.Open("testcase.txt")
	if err != nil {
		defer file.Close()
	}
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		vars = append(vars, scanner.Text())
	}
	v1 := vars[0]
	var times []float64
	iters := 101
	sample_size := 101
	for i := 1; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(v1))))
		md := 0.0
		for j := 0; j < sample_size; j++ {
			md += lengthOfLongestSubstring(string(v1[:ind]))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)

}
