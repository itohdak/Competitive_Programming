import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val m = nextInt()
    val K = Array(n){0}
    val T = Array(n){0}
    var sum1 = 0
    var sum2 = 0
    var ones = Array(0){0}
    var twos = Array(0){0}
    var K2: Array<Pair<Int, Int>> = emptyArray()
    for(i in 0 until n) {
        K[i] = nextInt()
        T[i] = nextInt()
        if(T[i] == 1) {
            sum1 += K[i]
            ones += i
        } else {
            sum2 += K[i]
            twos += i
            K2 += Pair(K[i], i)
        }
    }
    if(sum1 > m) {
        println(-1)
        return
    }
    val ans = Array(n){-1}
    var pos = 0
    for(i in ones) {
        ans[i] = pos
        pos += K[i]
    }
    val offset = pos
    var l1 = 0
    var l2 = 0
    var g1 = Array(0){0}
    var g2 = Array(0){0}
    K2.sortBy{ it -> it.first }
    for(i in K2.size-1 downTo 0) {
        if(l1 < l2) {
            l1 += K2[i].first
            g1 += K2[i].second
        } else {
            l2 += K2[i].first
            g2 += K2[i].second
        }
    }
    if(offset+1+(maxOf(l1, l2)-1)*2 > m) {
        println(-1)
        return
    }
    if(l1 > l2) {
        var tmp = offset
        for(i in g1) {
            ans[i] = tmp
            tmp += K[i]*2
        }
        tmp = offset+1
        for(i in g2) {
            ans[i] = tmp
            tmp += K[i]*2
        }
    } else {
        var tmp = offset
        for(i in g2) {
            ans[i] = tmp
            tmp += K[i]*2
        }
        tmp = offset+1
        for(i in g1) {
            ans[i] = tmp
            tmp += K[i]*2
        }
    }
    for(i in 0 until n) ans[i]++
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