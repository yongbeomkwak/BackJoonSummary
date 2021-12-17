import java.util.* //큐를 위한 import

const val MAX:Int=1001 //상수 

data class W (val dest:Int,val cost:Int):Comparable<W>{
  override fun compareTo(other:W):Int = cost-other.cost
    //cost에 오름차순
}

//인접 행렬 vector -> ArrayList
//[ArrayList,ArrayList,....]
var adj=Array<ArrayList<W>>(MAX,{ArrayList<W>(1)})
    


fun main(args: Array<String>) {
    

  val N=(readLine())!!.toInt()
  val M=(readLine())!!.toInt()

  for (i in 1..M)
  {
    val (a,b,c)=readLine()!!.split(" ").map{it.toInt()}

    adj[a].add(W(b,c)) //양방향 이기 때문에 두번 
    adj[b].add(W(a,c))
  }
  val pq=PriorityQueue<W>() //우선순위큐
  pq.add(W(1,0))

  var ret:Long =0
  var visit=IntArray(MAX,{0})

  while(pq.peek()!=null)
  {
    val u=pq.element().dest
    val u_dist=pq.element().cost
    pq.poll() //.pop

    if(visit[u]==1) continue

    visit[u]=1
    ret+=u_dist

    for( w in adj[u]) // w(dset,cost)
    {
      val v:Int=w.dest

      if(visit[v]==0) pq.add(w)
    }
    
  }
    
  print(ret)
    
   
    
  
}