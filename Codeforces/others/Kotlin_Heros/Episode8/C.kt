import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        var min = 0
        var max = 200000
        for(i in 0 until n) {
            val s = next()
            val t = next()
            val r = nextInt()
            if(r == 1) {
                var tmp = 0
                for(j in 0 until minOf(s.length, t.length)) {
                    if(s[s.length-1-j] != t[t.length-1-j]) break
                    tmp++
                }
                max = minOf(max, tmp)
            } else {
                var tmp = 1
                for(j in 0 until minOf(s.length, t.length)) {
                    if(s[s.length-1-j] != t[t.length-1-j]) break
                    tmp++
                }
                min = maxOf(min, tmp)
            }
        }
        val cnt = maxOf(0, max-min+1)
        println(cnt)
        if(cnt > 0) {
            val ans = Array(cnt){0}
            for(i in 0 until cnt) ans[i] = min+i
            println(ans.joinToString(" "))
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