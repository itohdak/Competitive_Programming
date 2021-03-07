package com.kotlin_heros.practice6

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var S: MutableList<String> = ArrayList<String>()
    for(i in 0 until n) {
        S.add(readLine()!!.toString())
    }
    S.sortBy { it.length }
    for(i in 0 until n-1) {
        if ( !S[i+1].contains(S[i]) ) {
            println("NO")
            return
        }
    }
    println("YES")
    println(S.joinToString("\n"))
}