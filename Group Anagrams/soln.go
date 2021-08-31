package main

import (
	"fmt"
	"io/ioutil"
	"sort"
	"strings"
	"time"
)

func groupAnagrams(strs []string) [][]string {
	start := time.Now()

	m := make(map[string][]string)
	var res [][]string

	for i := 0; i < len(strs); i++ {
		s := sorted(strs[i])
		if _, ok := m[s]; ok {
			m[s] = append(m[s], string(strs[i]))
		} else {
			m[s] = []string{strs[i]}
		}
	}

	for key, _ := range m {
		res = append(res, m[key])
	}

	fmt.Println(time.Since(start).Seconds() * 1000)
	return res
}

func sorted(str string) string {
	s := strings.Split(str, "")
	sort.Strings(s)
	return strings.Join(s, "")
}

func main() {
	f, err := ioutil.ReadFile("testcase.txt")
	if err != nil {
		fmt.Print(err)
	}
	fstr := string(f[1 : len(f)-1])
	fstr_split := strings.Split(fstr, ",")
	strs := make([]string, len(fstr_split))
	vsum := 0
	for i, s := range fstr_split {
		strs[i] = s[1 : len(s)-1]
		vsum += 1
	}
	for i := 0; i < 10; i++ {
		groupAnagrams(strs)
		fmt.Println(vsum)
	}

}
