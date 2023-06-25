import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val m = nextInt()
    val f = Array(m){0}
    val l = Array(m){0}
    val cnt = Array(n){Array(n){0}}
    for(i in 0 until m) {
        f[i] = nextInt()-1
        l[i] = nextInt()-1
        cnt[f[i]][l[i]]++
    }
    val sumr = Array(n){0}
    val sumc = Array(n){0}
    for(i in 0 until n) {
        for(j in 0 until n) {
            sumr[i] += cnt[i][j]
        }
    }
    for(j in 0 until n) {
        for(i in 0 until n) {
            sumc[j] += cnt[i][j]
        }
    }
    var ans = 0
    for(i in 0 until n) {
        for(j in 0 until n) {
            if(i == j) continue
            if(f[0] == i && l[0] == j) {
                ans = maxOf(ans, 1)
            } else if(f[0] == i || l[0] == j) {
                ans = maxOf(ans, cnt[i][j]+1)
            } else {
                ans = maxOf(ans, sumr[i]+sumc[j]-cnt[i][j]+1)
            }
        }
    }
    println(ans)
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