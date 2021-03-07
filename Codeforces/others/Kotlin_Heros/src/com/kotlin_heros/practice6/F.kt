package com.kotlin_heros.practice6

import java.lang.Math.abs

fun test(mid: Int, A: List<Long>, n: Int, m: Int, k: Long): Boolean {
    var need: Int = 0
    var tmp: Long = 0
    for(i in n-mid until n) {
        if(tmp + A[i] > k) {
            need++
            tmp = A[i]
        } else {
            tmp += A[i]
        }
    }
    if(tmp > 0) need++
    // println("$mid $need")
    return need <= m
}
fun main(args: Array<String>) {
    val input1 = readLine()!!.split(" ").map { it.toLong() }
    val n = input1[0].toInt()
    val m = input1[1].toInt()
    val k = input1[2]
    val A = readLine()!!.split(" ").map { it.toLong() }
    var ok = 0
    var ng = n+1
    while(abs(ok-ng) > 1) {
        var mid = (ok+ng)/2
        if(test(mid, A, n, m, k)) ok = mid
        else                      ng = mid
    }
    println(ok)
}