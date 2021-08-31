package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func lengthOfLongestSubstring(s string) int {
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
	if mx > j-i {
		mx = mx
	} else {
		mx = j - i
	}
	fmt.Println(time.Since(start).Seconds() * 1000)
	return mx
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
	fmt.Println((len(vars[0]) - 2))
	for i := 0; i < 10; i++ {
		lengthOfLongestSubstring(v1[1 : len(v1)-1])
	}

}
