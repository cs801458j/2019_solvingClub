import java.util.Scanner;
public class swexpert_1859 {
	
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int T, N, arr[];
		T = input.nextInt();
		
		for(int i=1; i<=T; i++){	
			long sum =0;
			N = input.nextInt();
			arr = new int[N];

			for(int j=0; j<N; j++){
				arr[j] = input.nextInt();
			}

			// max값 설정  -> 처음에 잘못 생각한 부분: 앞에서 부터 탐색하며 max에서 값이 변할때마다 sum을 구한점.. 그래서 맨 뒤에서부터 max를 설정하는 것으로 변경
			int max = arr[N-1];
			for(int j = N-2; j>=0; j--){
				if(max >arr[j])
					sum += (max - arr[j]);
				else
					max = arr[j];
					
			}
	
			System.out.println("#"+i+" "+sum);

		}
	}

}
