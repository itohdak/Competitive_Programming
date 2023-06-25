import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(i in 0..t-1) {
        val n = nextInt()
        val k = nextInt()
        var ans = 0
        for(j in 0..n-1) {
            val l = nextInt()
            val r = nextInt()
            if(l <= k && k<=r) {
                ans = Math.max(ans, r-k+1)
            }
        }
        println(ans)
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