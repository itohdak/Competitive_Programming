import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0..t-1) {
        val n = nextInt()
        val x = Array(n) { nextInt() }
        var done = false
        for(i in 0..n-2) {
            if(x[i]%2 == x[i+1]%2) {
                println("YES")
                done = true
                break
            }
        }
        if(!done) println("NO")
    }
}

fun main() {
    val writer = PrintWriter(System.out, false)
    writer.solve()
    writer.flush()
}

// region Scanner
private var st = StringTokenizer("")
private val br = System.`in`.bufferedReader()

private fun next(): String {
    while (!st.hasMoreTokens()) st = StringTokenizer(br.readLine())
    return st.nextToken()
}

private fun nextInt() = next().toInt()
private fun nextLong() = next().toLong()
private fun nextLine() = br.readLine()!!
private fun nextDouble() = next().toDouble()
// endregion