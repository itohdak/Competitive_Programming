package com.kotlin_heros.practice6

import java.lang.Integer.min

fun main(args: Array<String>) {
    val q = readLine()!!.toInt()
    var l = -1
    var r = 0
    var pos: MutableList<Int> = MutableList(200000) { -1 }
    for(i in 0 until q) {
        val input = readLine()!!.split(" ").map { it.toString() }
        val com = input[0]
        val id = input[1].toInt()-1
        if (com == "L") {
            pos[id] = l--
        } else if (com == "R") {
            pos[id] = r++
        } else {
            println(min(pos[id]-l, r-pos[id])-1)
        }
    }
}