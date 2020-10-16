import java.util.*
import java.io.PrintWriter
import kotlin.math.roundToInt

val pw = PrintWriter(System.out)

fun main(args: Array<String>) {
    func()
    pw.flush()
}
fun func() {
    val t = nextInt()
    for(i in 1..t) {
        val n = nextDouble()
        when {
            n < 1000 -> {
                pw.println(n.toInt())
            }
            n < 1000000 -> {
                if((n / 1000).roundToInt() == 1000) {
                    pw.println("1M")
                } else {
                    pw.println((n / 1000).roundToInt().toString() + "K")
                }
            }
            else -> {
                pw.println((n / 1000000).roundToInt().toString() + "M")
            }
        }
        // pw.flush()
    }
}
fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map{ it.toInt() }
fun listOfLong() = listOfString().map{ it.toLong() }
fun listOfDouble() = listOfString().map{ it.toDouble() }
