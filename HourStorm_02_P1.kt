// code_report Solution
// https://youtu.be/LV6DTbLBL8M
    
fun main(args: Array<String>) {
    val (x, y, s, t) = readLine()!!.split(' ').map(String::toInt)
    var j = t
    var c = 0
    
    for (i in 0..t + 1) {
        if (j >= y && j <= y + s)
            c += minOf (maxOf (0, i - x + 1), s + 1)
        j--
    }
    
    println (c)
}

    
