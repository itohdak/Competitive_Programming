package com.div3.round494

import kotlin.math.max

fun main(args: Array<String>) {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val n = input[0]
    val k = input[1]
    val A = readLine()!!.split(" ").map { it.toInt() }
    var cum: MutableList<Int> = MutableList(n+1) { 0 }
    for(i in 0 until n) cum[i+1] = cum[i] + A[i]
    var ans: Double = 0.0
    for(i in k until n+1) {
        var mx: Int = 0
        for(j in 0 until n) {
            if(j + i > n) break
            mx = Integer.max(mx, cum[j+i]-cum[j])
        }
        ans = max(ans, mx.toDouble()/i)
    }
    println(ans)
}