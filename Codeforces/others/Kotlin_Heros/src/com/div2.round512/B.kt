package com.div2.round512

import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val d = nextInt()
    val m = nextInt()
    for(i in 0 until m) {
        val x = nextInt()
        val y = nextInt()
        // y = -x + d
        // y =  x + d
        // y = -x + 2*n-d
        // y =  x - d
        if(y >= -x + d && y <= x + d && y <= -x + 2*n-d && y >= x - d) {
            println("YES")
        } else {
            println("NO")
        }
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