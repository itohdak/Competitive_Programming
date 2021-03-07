package com.kotlin_heros.episode3

import java.io.PrintWriter
import java.util.*
import kotlin.math.roundToInt

private fun PrintWriter.solve() {
    val t = nextInt()
    for(i in 0 until t) {
        val n = nextDouble()
        when {
            n < 1000 -> {
                println(n.toInt())
            }
            n < 1000000 -> {
                if((n / 1000).roundToInt() == 1000) {
                    println("1M")
                } else {
                    println((n / 1000).roundToInt().toString() + "K")
                }
            }
            else -> {
                println((n / 1000000).roundToInt().toString() + "M")
            }
        }
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