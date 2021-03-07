package com.kotlin_heros.practice6

class UnionFind(size: Int) {
    var par: Array<Int> = Array(size) { it }
    var depth: Array<Int> = Array(size) { 0 }
    var nGroup: Array<Int> = Array(size) { 1 }

    fun root(x: Int): Int {
        return if(par[x] == x) {
            x
        } else {
            par[x] = root(par[x])
            par[x]
        }
    }

    fun same(x: Int, y: Int): Boolean {
        return root(x) == root(y)
    }

    fun unite(x: Int, y: Int) {
        val x = root(x)
        val y = root(y)
        if(x == y) return
        if(depth[x] < depth[y]) {
            par[x] = y
            nGroup[y] += nGroup[x]
            nGroup[x] = 0
        } else {
            par[y] = x
            nGroup[x] += nGroup[y]
            nGroup[y] = 0
            if(depth[x] == depth[y]) {
                depth[x]++
            }
        }
    }
}
fun main(args: Array<String>) {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val n = input[0]
    val m = input[1]
    val A = readLine()!!.split(" ").map { it.toLong() }
    var costs: MutableList<Pair<Long, Pair<Int, Int>>> = ArrayList()
    val mn = A.min()
    val mni = A.indexOf(mn)
    for(i in 0 until n) {
        if(i != mni) {
            costs.add(Pair(A[i]+A[mni], Pair(i, mni)))
        }
    }
    for(i in 0 until m) {
        val input2 = readLine()!!.split(" ").map { it.toLong() }
        val x = input2[0].toInt()-1
        val y = input2[1].toInt()-1
        val w = input2[2]
        costs.add(Pair(w, Pair(x, y)))
    }
    costs.sortBy { it.first }
    var uf = UnionFind(n)
    var ans: Long = 0
    for(ele in costs) {
        val c = ele.first
        val x = ele.second.first
        val y = ele.second.second
        if(uf.same(x, y)) continue
        uf.unite(x, y)
        ans += c
    }
    println(ans)
}