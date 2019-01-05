import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
class node_1249 implements Comparable<node_1249>{
	int x, y, value;
	
	public node_1249(int x, int y, int value){
		this.x = x;
		this.y = y;
		this.value = value;
	}

	@Override
	public int compareTo(node_1249 node) {
		if(value < node.value)
			return -1;
		else
			return 1;
	}

}

public class swexpert_1249_2 {
	static int dx[] = new int[]{0, 1, 0, -1};
	static int dy[] = new int[]{-1, 0, 1, 0};
	static int N, arr[][];
	static boolean visited[][];
	
	public static int bfs(){
		PriorityQueue<node_1249> pq = new PriorityQueue<node_1249>();
		int result =0;
		// 시작 좌표 설정
		pq.add(new node_1249(0, 0, 0));
		visited[0][0] = true;
		while(!pq.isEmpty()){
			node_1249 temp = pq.poll();
			if(temp.x == N-1 && temp.y == N-1){
				result = temp.value;
			}
			
			for(int i=0; i<4; i++){
				int nx = temp.x + dx[i];
				int ny = temp.y + dy[i];
				if(nx>=0 && ny>=0 && nx<N && ny<N && visited[nx][ny]==false){
					visited[nx][ny] = true;
					pq.add(new node_1249(nx, ny, temp.value+arr[nx][ny]));
				}
			}
		}
			
		return result;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());		
		for(int tc=1; tc<=T; tc++){
			int result=0;
			N = Integer.parseInt(br.readLine());
			arr = new int[N][N];
			visited = new boolean[N][N];
			for(int i=0; i<N; i++){
				StringBuffer sb = new StringBuffer(br.readLine());
				for(int j=0; j<N; j++){
					arr[i][j] = Integer.parseInt(sb.substring(j, j+1));
				}
			}			
			result = bfs();
			System.out.println("#"+tc+" "+result);
		}
	}

}
