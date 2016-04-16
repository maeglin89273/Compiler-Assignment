let a = 10 - (5 + 4) * 3
let b = 10 - 5 + 4 * 3
var result

func test(a:Int, b:Int) -> Int {
	var c = 0
	if (a > b) {
		println "a is bigger than b"
		while(a > b) {
			a--
			c++
		}
	} else {
		println "a is smaller than b"
		while(a < b) {
			b--
			c++
		}
	}

	return c
}
result = test(a, b)
print "interation count that makes a equals b = "
println result