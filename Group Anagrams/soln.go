package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"sort"
	"strings"
	"time"
)

func groupAnagrams(strs []string) float64 {
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

	// fmt.Println(time.Since(start).Seconds() * 1000)
	// return res
	return float64(time.Since(start).Milliseconds())
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

	var times []float64
	iters := 100
	sample_size := 100
	for i := 0; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(strs))))
		// fmt.Print("ind : ", prop, ind)
		md := 0.0
		for j := 0; j < sample_size; j++ {
			md += float64(groupAnagrams(strs[:ind]))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)

}
