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
    val n = nextInt()
    val a = Array(n) { nextInt() }.sorted()
    val b = Array(n+1) { nextInt() }.sorted()
    val m = nextInt()
    val c = Array(m) { nextInt() }
    val d1 = Array(n) { b[it]-a[it] }
    val d2 = Array(n) { b[it+1]-a[it] }
    val sum1 = Array(n+1) { Int.MIN_VALUE }
    val sum2 = Array(n+1) { Int.MIN_VALUE }
    for(i in 0 until n) {
        sum1[i+1] = maxOf(sum1[i], d1[i])
    }
    for(i in n-1 downTo 0) {
        sum2[i] = maxOf(sum2[i+1], d2[i])
    }
    val ans = Array(m) {
        val lb = bsearch(a, c[it])
        maxOf(sum1[lb], b[lb]-c[it], sum2[lb])
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