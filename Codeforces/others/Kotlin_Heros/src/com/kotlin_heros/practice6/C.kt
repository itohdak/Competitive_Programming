package com.kotlin_heros.practice6

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val s = readLine()!!.toString()
    var ans = 0
    var count = 0
    for(i in 0 until n) {
        if(s[i] == 'x') {
            count++
            if(count >= 3) ans++
        } else {
            count = 0
        }
    }
    println(ans)
}