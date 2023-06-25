import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val m = nextInt()
    val st = Array(n) { nextLine() }.toSet()
    val q = nextInt()
    for(_i in 0 until q) {
        val t = nextLine()
        val st2 = Array(m+1) {
            t.substring(0, it) + t.substring(it+1, m+1)
        }.toSet()
        var ans = 0
        for(s in st2) {
            if(st.contains(s)) ans++
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