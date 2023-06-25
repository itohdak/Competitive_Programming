package com.kotlin_heros.episode6

import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val C = Array(n) { nextLong() }
    var next = Array(n) { 0 }
    var tmp = 0L
    var prev = n-1
    for(i in n-1 downTo 0) {
        next[i] = prev
        if(C[i] > tmp) {
            tmp = C[i]
            prev = i
        }
    }
    var sum = Array(n) { 0L }

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