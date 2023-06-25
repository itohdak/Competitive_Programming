package com.kotlin_heros.episode6

import java.io.PrintWriter
import java.lang.Integer.min
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        val k = nextInt()
        val s = nextLine()
        var cnt = 0
        var zero = 0
        for(i in 0 until n) {
            if(s[i] == '(') cnt++
            else cnt--
            assert(cnt >= 0)
            if(cnt == 0) zero++
        }
        println(min(zero+k, n/2))
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