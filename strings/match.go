package main

import "fmt"
import "github.com/golang-collections/collections/stack"

// Validate nested  opening and closing sequences of brackets and parenthesis.
// The point of the algorithm is in the introduction of a stack to avoid any form of exponential reccursion.

func check(s string) bool {
	closings := map[rune]rune{
		'(': ')',
		'[': ']'}
	stack := stack.New()

	for _, c := range s {
		if _, ok := closings[c]; ok {
			stack.Push(c)
		} else if stack.Len() > 0 {
			if value, found := closings[stack.Pop().(rune)]; !found || value != c {
				return false
			}
		} else {
			return false
		}
	}
	return stack.Len() == 0
}

func main() {

	strs := []string{
		"33",
		"[[[[[",
		"[)(]",
		"[()]",
		"()[]",
		"(()[])",
		"([)]",
		"((",
		"([])([][])",
		"(])()",
		"([[]()[]])([[]()[]])([[]()[]])([[]()[]])([[]()[]])"}

	for _, s := range strs {
		if check(s) {
			fmt.Println(s, ": OK")
		} else {
			fmt.Println(s, ": KO")
		}
	}
}
