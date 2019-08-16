package main

import (
	"fmt"
	"os"
	"strconv"
)

func getip(source string) (ips []string) {

	length := len(source)
	if length > 12 || length < 4 {
		return nil
	}
	if length == 4 {
		ip := string(source[0]) + "." + string(source[1]) + "." + string(source[2]) + "." + string(source[3])
		ips = append(ips, ip)
	} else {
		s := source
		var ips_ [][]string
		//放置三个点
		for i := 0; i < length-1; i++ {
			if i > 2 {
				break
			}
			for j := i + 1; j < length-1; j++ {
				if j-i > 3 {
					break
				}
				for k := j + 1; k < length-1; k++ {
					//fmt.Println(i, j, k)
					if k-j > 3 {
						break
					}
					if len(s[k:]) <= 4 {
						//fmt.Println(i, j, k)
						var ipt []string
						ipt = append(ipt, string(s[0:i+1]))
						ipt = append(ipt, string(s[i+1:j+1]))
						ipt = append(ipt, string(s[j+1:k+1]))
						ipt = append(ipt, string(s[k+1:]))
						ips_ = append(ips_, ipt)
					}

				}
			}
		}
		for _, ip := range ips_ {
			for _, i := range ip {
				if ii, err := strconv.Atoi(i); err != nil || ii > 255 {
					goto over
				}
			}
			ips = append(ips, ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3])
		over:
		}
	}
	return
}

func main() {
	fmt.Println("处理字符串：", os.Args[1])
	fmt.Println(getip(os.Args[1]))

}
