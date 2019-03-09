package main

// Hanoi towers, no optim
// https://en.wikipedia.org/wiki/Tower_of_Hanoi

import (
	"fmt"
)

// Position indicates the position of tower
type Position string

// Disk identifier
type Disk int

// Hanoi simple algorithm
func Hanoi(disk Disk, source Position, destination Position, spare Position) {
	if disk != 0 {
		Hanoi(disk-1, source, spare, destination)
		fmt.Printf("Moving disk %d from %s to %s\n", disk, source, destination)
		Hanoi(disk-1, spare, destination, source)
	}
}

func main() {
	Hanoi(3, "A", "B", "C")
}
