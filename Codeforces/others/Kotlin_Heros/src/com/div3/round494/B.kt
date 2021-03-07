package com.div3.round494

fun main(args: Array<String>) {
    val input = readLine()!!.split(" ").map { it.toInt() }
    var a = input[0]
    var b = input[1]
    var x = input[2]
    val n = a + b
    if(a > b) {
        var s: String = ""
        for(i in 0 until x+1) {
            if(i % 2 == 0) {
                if(x-i <= 1) {
                    for(j in 0 until a) s += "0"
                    a = 0
                } else {
                    s += "0"
                    a--
                }
            } else {
                if(x-i <= 1) {
                    for(j in 0 until b) s += "1"
                    b = 0
                } else {
                    s += "1"
                    b--
                }
            }
        }
        println(s)
    } else {
        var s: String = ""
        for(i in 0 until x+1) {
            if(i % 2 == 1) {
                if(x-i <= 1) {
                    for(j in 0 until a) s += "0"
                    a = 0
                } else {
                    s += "0"
                    a--
                }
            } else {
                if(x-i <= 1) {
                    for(j in 0 until b) s += "1"
                    b = 0
                } else {
                    s += "1"
                    b--
                }
            }
        }
        println(s)
    }
}