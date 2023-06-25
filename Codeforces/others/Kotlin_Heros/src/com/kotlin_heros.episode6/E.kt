package com.kotlin_heros.episode6

import java.io.PrintWriter
import java.lang.Integer.max
import java.lang.Math.abs
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        val A = Array(n) { nextInt()-1 }
        var P = MutableList(0) { Pair(0, 0) }
        var prev = Array(n) { -1 }
        for(i in 0 until n) {
            if(prev[A[i]] != -1) {
                P.add(Pair(prev[A[i]], i))
            } else {
                prev[A[i]] = i
            }
        }
        P.sortBy { -it.second }
        println(P.joinToString(" "))
        val m = P.size
        var next = Array(m) { 0 }
        var mp: SortedMap<Int, Int> = sortedMapOf()
        fun bsearch(v: Int): Int {
            val keys = mp.keys.toList()
            fun test(mid: Int): Boolean {
                if(mid == mp.size) return false
                return keys[mid] >= v
            }
            var ok = 0
            var ng = mp.size+1
            while(abs(ok-ng) > 1) {
                val mid = (ok+ng)/2
                if(test(mid)) ok = mid
                else ng = mid
            }
            return ok
        }
        for(i in m-1 downTo 0) {
            val tmp = bsearch(P[i].first)
            next[i] = if(tmp == mp.size) m else mp.toList()[tmp].second
            mp[P[i].first] = i
        }
        println(next.joinToString(" "))
        var dp = Array(m+1) { 0 }
        for(i in 0 until m) {
            if(next[i] == m && P[i].first+1 < P[i].second) dp[next[i]] = max(dp[next[i]], dp[i]+3)
            else dp[next[i]] = max(dp[next[i]], dp[i]+2)
        }
        println(dp[m])
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