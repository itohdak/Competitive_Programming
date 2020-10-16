import java.io.PrintWriter

val pw = PrintWriter(System.out)

fun main(args : Array<String>) {
    func()
    pw.flush()
}

fun func() {
    // solution
    val t = nextInt()
    for(i in 1..t) {
        val n = nextInt()
        var A: Array<Pair<Long, Long>?> = arrayOfNulls(n*2)
        for(j in 1..n) {
            val input = listOfLong()
            val a = input[0]
            val b = input[1]
        }
        A.sort()
        println(A)
    }
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }
