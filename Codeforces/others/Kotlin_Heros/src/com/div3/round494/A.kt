package com.div3.round494

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map { it.toInt() }
    var cnt: MutableList<Int> = MutableList(101) { 0 }
    for(i in 0 until n) cnt[A[i]]++
    println(cnt.max())
}