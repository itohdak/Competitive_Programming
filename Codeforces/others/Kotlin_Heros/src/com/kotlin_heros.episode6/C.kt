package com.kotlin_heros.episode6

import java.io.PrintWriter
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    fun patorol(x: Int, l: Int, r: Int): Int {
        if(r <= x) {
            return x-l
        } else if(l <= x) {
            return min(x-l+r-l-1, r-x-1+r-l-1)
        } else {
            return r-x-1
        }
    }
    for(_i in 0 until t) {
        val n = nextInt()
        var x = nextInt()-1
        var y = nextInt()-1
        if(y < x) {
           var tmp = x
            x = y
            y = tmp
        }
        var mn = 10000000
        for(i in 1 until n) {
            mn = min(mn, max(patorol(x, 0, i), patorol(y, i, n)))
        }
        println(mn)
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