import java.io.PrintWriter
import java.util.*

private fun bsearch(c: List<Int>, lb: Int): Int {
    fun test(m: Int): Boolean {
        return c[m] >= lb
    }
    var ok = c.size
    var ng = -1
    while(Math.abs(ok-ng)>1) {
        val mid = (ok+ng)/2
        if(test(mid)) ok = mid
        else ng = mid
    }
    return ok
}
private fun PrintWriter.solve() {
    val s = nextLine()
    val n = s.length
    val zero = mutableListOf<Int>()
    val one = mutableListOf<Int>()
    for(i in 0 until n) {
        if(s[i] == '0') zero.add(i)
        else one.add(i)
    }
    val ans = mutableListOf<Int>()
    for(k in 1..n) {
        var pos = 0
        var cnt = 0
        while(pos < n) {
            cnt++
            val it0 = bsearch(zero, pos)
            val next0 = if(it0+k >= zero.size) n else zero[it0+k]
            val it1 = bsearch(one, pos)
            val next1 = if(it1+k >= one.size) n else one[it1+k]
            pos = maxOf(next0, next1)
        }
        ans.add(cnt)
    }
    println(ans.joinToString(" "))
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