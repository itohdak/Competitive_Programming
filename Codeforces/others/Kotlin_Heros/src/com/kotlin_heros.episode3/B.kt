package com.kotlin_heros.episode3

import java.io.PrintWriter
import java.util.*

private fun PrintWriter.solve() {
    val t = nextInt()
    for(_i in 0 until t) {
        val n = nextInt()
        var A = MutableList<Long>(n) { 0 }
        var B = MutableList<Long>(n) { 0 }
        var mp: MutableMap<Long, Int> = sortedMapOf()
        for(i in 0 until n) {
            A[i] = nextLong()
            B[i] = nextLong()
            B[i]++
            if(!mp.containsKey(A[i])) mp[A[i]] = 0
            mp[A[i]] = mp[A[i]]!! + 1
            if(!mp.containsKey(B[i])) mp[B[i]] = 0
            mp[B[i]] = mp[B[i]]!! - 1
        }
//        println(A.joinToString(" "))
//        println(B.joinToString(" "))
//        println(mp.keys.joinToString(" "))
//        println(mp.values.joinToString(" "))
        var sum = 0
        var done = false
        for(ele in mp) {
            sum += ele.value
            if(sum == 1) {
                println(ele.key)
                done = true
                break
            }
        }
        if(!done) println(-1)
    }
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