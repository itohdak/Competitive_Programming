import java.io.PrintWriter

val pw = PrintWriter(System.out)

fun main(args : Array<String>) {
    func()
    pw.flush()
}

fun func() {
    // solution
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }
