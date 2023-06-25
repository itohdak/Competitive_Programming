import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        val s = nextLine()
        val t = nextLine()
        val sa = Array(n){ it -> s[it] }
        val ta = Array(n-3){ it -> t[it] }
        var ans = 0
        for(i in 0 until n-3) {
            if(ta[i] == '0') continue
            if(i+1 < n-3 && ta[i+1] == '1') {
                println(-1)
                return
            }
            if(i+3 < n-3 && ta[i+3] == '1') {
                println(-1)
                return
            }
            if(i+2 < n-3 && ta[i+2] == '1') {
                val temp = "()()"
                for(j in 0 until 4) {
                    if(sa[i+j] != temp[j]) {
                        ans++
                        sa[i+j] = temp[j]
                    }
                }
            } else {
                var best = "    "
                var min = 5
                val temp = "()()"
                var tmp = 0
                for(j in 0 until 4) {
                    if(sa[i+j] != temp[j]) {
                        tmp++
                    }
                }
                if(min > tmp) {
                    min = tmp
                    best = temp
                }
                if(i-2 < 0 || ta[i-2] != '1') {
                    val temp = "(())"
                    var tmp = 0
                    for(j in 0 until 4) {
                        if(sa[i+j] != temp[j]) {
                            tmp++
                        }
                    }
                    if(min > tmp) {
                        min = tmp
                        best = temp
                    }
                }
                ans += min
                for(j in 0 until 4) {
                    sa[i+j] = best[j]
                }
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