import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    case@ for(_i in 0 until t) {
        val n = nextInt()
        val k = nextInt()
        val s = nextLine()
        var next = Array(n) { (it+1)%n }
        var prev = Array(n) { (it-1+n)%n }
        var cnt = s.count{ it == '1' }
        var pos = 0
        var ans = 0
        while(cnt > 0) {
            ans++
            if(s[pos] == '1') cnt--
            next[prev[pos]] = next[pos]
            prev[next[pos]] = prev[pos]
            for(i in 0 until k) {
                pos = next[pos]
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