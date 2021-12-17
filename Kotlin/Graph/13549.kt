import java.util.* //큐를 위한 import
fun main(args: Array<String>) {
    val INF=987654321
    val MAX= 100001
    val (N,K)=readLine()!!.split(" ").map{it.toInt()}
    //입력 N과 K를 받음(String->Int)

    var visit:IntArray=IntArray(MAX,{0}) //길이 MAX로 0
    var dist:IntArray=IntArray(MAX,{INF}) //길이 MAX로 INF
    var q: Queue<Int> = LinkedList<Int>() //큐생성
    
    
    q.add(N) //큐 삽입
    dist[N]=0
    
    while(q.peek()!=null) //비어있으면 null
    {
    	val now:Int=q.poll() // .top 과 .pop을 동시에 
      if(now==K) break
      if(visit[now]==1) continue
      visit[now]=1

      var next:Int=2*now
      if(next<=MAX-1&&dist[next]>dist[now])
      {
        q.add(next)
        dist[next]=dist[now]
      }
      next=now+1
      if(next<=MAX-1&&dist[next]>dist[now]+1)
      {
        q.add(next)
        dist[next]=dist[now]+1
      }
      next=now-1
      if(0<=next&&dist[next]>dist[now]+1)
      {
        q.add(next)
        dist[next]=dist[now]+1
      }
    
    }
  	print(dist[K])
}