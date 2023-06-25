package com.kotlin_heros.episode6

import java.io.PrintWriter
import java.lang.Math.abs
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextLong()
        val s = nextLong()
        fun bsearch(): Long {
            fun test(mid: Long): Boolean {
                var m = mid
                var sum = 0L
                for(i in 0 until n) {
                    if(m == 1L) {
                        sum += (n-i)
                        break
                    }
                    sum += m
                    m = (m+1)/2
                }
                return sum <= s
            }
            var ok: Long = (s + n - 1) / n
            var ng: Long = 1000000000L * 1000000000L + 1
            while(abs(ok-ng) > 1) {
                val mid: Long = (ok + ng) / 2
                if(test(mid)) ok = mid
                else ng = mid
            }
            return ok
        }
        println(bsearch())
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