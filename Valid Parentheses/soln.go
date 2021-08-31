package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func isValid(s string) bool {
	start := time.Now()

	var stack []string

	for i := 0; i < len(s); i++ {
		l := string(s[i])
		if l == "(" || l == "[" || l == "{" {
			stack = append(stack, l)
			continue
		}
		if len(stack) == 0 {
			return false
		}
		p := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		if l == ")" && p != "(" {
			return false
		}
		if l == "]" && p != "[" {
			return false
		}
		if l == "}" && p != "{" {
			return false
		}
	}
	fmt.Println(time.Since(start).Seconds()*1000, " ms")
	return len(stack) == 0
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
	for i := 0; i < 10; i++ {
		isValid(v1)
	}

}
