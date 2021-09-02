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

func merge(intervals [][]int) float64 {
	start := time.Now()

	sort.Slice(intervals[:], func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var res [][]int
	var mn int
	var mx int
	var arr []int

	arr = intervals[0]
	intervals = intervals[1:]

	for i := 0; i < len(intervals); i++ {
		if arr[1] >= intervals[i][0] {
			if arr[0] < intervals[i][0] {
				mn = arr[0]
			} else {
				mn = intervals[i][0]
			}
			if arr[1] > intervals[i][1] {
				mx = arr[1]
			} else {
				mx = intervals[i][1]
			}
			arr = []int{mn, mx}
		} else {
			res = append(res, arr)
			arr = intervals[i]
		}
	}
	res = append(res, arr)

	// fmt.Println(time.Since(start).Seconds() * 1000)
	// return res
	return float64(time.Since(start).Milliseconds())
}

func main() {
	f, err := ioutil.ReadFile("testcase.txt")
	if err != nil {
		fmt.Print(err)
	}
	fstr := string(f[2 : len(f)-2])
	fstr_split := strings.Split(fstr, "],[")
	ints := make([][]int, len(fstr_split))
	vsum := 0
	for i, s := range fstr_split {
		ssp := strings.Split(s, ",")
		a, _ := strconv.Atoi(ssp[0])
		b, _ := strconv.Atoi(ssp[1])
		vsum += (a + b)
		ints[i] = []int{a, b}
	}

	var times []float64
	iters := 101
	sample_size := 101
	for i := 1; i < iters; i++ {
		prop := float64(i) / float64(iters)
		ind := int(math.Round(prop * float64(len(ints))))
		md := 0.0
		for j := 0; j < sample_size; j++ {
			fmt.Println(len(ints[:ind]))
			md += float64(merge(ints[:ind]))
		}
		times = append(times, md/float64(sample_size))
	}
	fmt.Print(times)

}
