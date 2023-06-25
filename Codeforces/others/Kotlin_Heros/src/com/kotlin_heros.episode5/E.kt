package com.kotlin_heros.episode5

import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        val A = Array(n) { nextInt() }
        val B = Array(n) { nextInt() }
        var ans = -1
        var ansInd = -1
        for(i in 0 until n) {
            var tmp = 1000005
            for(j in 0 until n) {
                tmp = Math.min(tmp, Math.abs(B[(i + j) % n] - A[j]))
            }
            if(tmp > ans) {
                ans = tmp
                ansInd = i
            }
        }
        val ansArray = Array(n) { (it + ansInd) % n + 1 }
        println(ansArray.joinToString(" "))
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