package com.div2.round512

import java.io.PrintWriter
import java.util.*

private fun gcd(x: Long, y: Long) : Long {
    return when {
        x > y -> gcd(y, x)
        x == 0L -> y
        else -> gcd(y%x, x)
    }
}
private fun prime_factorization(n: Long): HashMap<Long, Int> {
    var mp: HashMap<Long, Int> = HashMap<Long, Int>()
    if(n == 1L || n == 0L) {
        return mp
    }
    var m = n
    var i = 2L
    while(m >= i * i) {
        while(m % i == 0L) {
            if(!mp.containsKey(i)) mp[i] = 0
            mp[i] = mp[i]!! + 1
            m /= i
        }
        if(i == 2L) i++
        else i+= 2
    }
    if(m != 1L) mp[m] = 1
    return mp
}
private fun PrintWriter.solve() {
    val n = nextLong()
    val m = nextLong()
    val k = nextLong()
    if(k == 1L) {
        println("NO")
        return
    }
    val g = gcd(n*m, k)
    if(k / g > 2) {
        println("NO")
        return
    }
    if(k / g == 1L) {
        val mp = prime_factorization(g)
        var a = n
        var b = m
        var c = 2L
        mp.forEach {
            for(i in 0 until it.value) {
                when {
                    c % it.key == 0L -> c /= it.key
                    a % it.key == 0L -> a /= it.key
                    b % it.key == 0L -> b /= it.key
                    else -> assert(false)
                }
            }
        }
        when {
            a * c <= n -> {
                println("YES")
                println(listOf(0L, 0L).joinToString(" "))
                println(listOf(a*c, 0L).joinToString(" "))
                println(listOf(0L, b).joinToString(" "))
            }
            b * c <= m -> {
                println("YES")
                println(listOf(0L, 0L).joinToString(" "))
                println(listOf(a, 0L).joinToString(" "))
                println(listOf(0L, b*c).joinToString(" "))
            }
            else -> {
                assert(false)
            }
        }
    } else {
        val mp = prime_factorization(g)
        var a = n
        var b = m
        mp.forEach {
            for (i in 0 until it.value) {
                when {
                    a % it.key == 0L -> a /= it.key
                    b % it.key == 0L -> b /= it.key
                    else -> assert(false)
                }
            }
        }
        println("YES")
        println(listOf(0L, 0L).joinToString(" "))
        println(listOf(a, 0L).joinToString(" "))
        println(listOf(0L, b).joinToString(" "))
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