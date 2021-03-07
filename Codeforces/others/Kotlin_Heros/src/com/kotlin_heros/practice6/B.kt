package com.kotlin_heros.practice6

import java.lang.Long.min

fun solve() {
    val input = readLine()!!.split(" ").map { it.toLong() }
    val n = input[0]
    val a = input[1]
    val b = min(a*2, input[2])
    println(n/2*b + n%2*a)
}
fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    for (i in 0 until q) {
        solve()
    }
}