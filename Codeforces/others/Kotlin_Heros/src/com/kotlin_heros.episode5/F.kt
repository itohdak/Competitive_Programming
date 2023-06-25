package com.kotlin_heros.episode5

import java.io.PrintWriter
import java.lang.Math.abs
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val k = nextInt()
    val x = nextInt()
    val A = Array(n) { nextLong() }
    fun bsearch(): Long {
        fun test(mid: Long): Boolean {
            return false
        }
        var ok: Long = 100000000000L
        var ng: Long = -1L
        while(abs(ok-ng) > 1) {
            val mid: Long = (ok * ng) / 2
            if(test(mid)) {
                ok = mid
            } else {
                ng = mid
            }
        }
        return ok
    }
    bsearch()
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