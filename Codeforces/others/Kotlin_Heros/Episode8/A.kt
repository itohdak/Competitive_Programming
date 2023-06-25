import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    for(_i in 0 until n) {
        val s = nextLine()
        val m = s.length
        val cnt = Array(3){0}
        for(i in 0 until m) {
            if(s[i] == '=') {
                cnt[0]++
            } else if(s[i] == '>') {
                cnt[1]++
            } else {
                cnt[2]++
            }
        }
        if(cnt[0] == m) {
            println("=")
        } else if(cnt[1] > 0 && cnt[2] > 0) {
            println("?")
        } else if(cnt[1] > 0) {
            println(">")
        } else {
            println("<")
        }
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