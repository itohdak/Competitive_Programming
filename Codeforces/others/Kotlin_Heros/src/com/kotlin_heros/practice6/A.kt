package com.kotlin_heros.practice6

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val A: List<Int> = readLine()!!.split(" ").map { it.toInt() }
    val Arev = A.reversed()
    var ans: MutableList<Int> = ArrayList<Int>()
    var st: MutableSet<Int> = HashSet<Int>()
    for ( a: Int in Arev ) {
        if ( ! st.contains(a) ) {
            ans.add(a)
            st.add(a)
        }
    }
    ans.reverse()
    println(ans.size)
    println(ans.joinToString(" "))
}