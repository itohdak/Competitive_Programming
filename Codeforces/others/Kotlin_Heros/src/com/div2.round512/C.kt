package com.div2.round512

import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val n = nextInt()
    val s = nextLine()
    var sum = Array(n+1) { 0 }
    for(i in 0 until n) {
        sum[i+1] = sum[i] + (s[i]-'0').toInt()
    }
    if(sum[n] == 0) {
        println("YES")
        return
    }
    var st = HashSet<Int>()
    for(i in 0 until n+1) st.add(sum[i])
    for(i in 1 until sum[n]) {
        if(sum[n] % i > 0) continue
        var ok = true
        for(j in 0 until sum[n]/i) {
            if(!st.contains(i*j)) ok = false
        }
        if(ok) {
            println("YES")
            return
        }
    }
    println("NO")
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