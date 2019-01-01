import java.util.Scanner;
public class swexpert_2805 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T;
		
		T = input.nextInt();
		for(int tc = 1; tc<=T; tc++){
			int N, arr[][], sum=0;
			
			N = input.nextInt();
			
			arr = new int[N][N];
			
			for(int i=0; i<N; i++){
				StringBuffer sb = new StringBuffer(input.next());
				for(int j=0; j<N; j++){
					arr[i][j] = Integer.parseInt(sb.substring(j, j+1));
				}
			}
			
			//	������ ������ for�� ��ȸ
			int half = N/2;
			
			//	���� ��
			for(int i=0; i<half; i++){
				for(int j=half-i; j<=half+i; j++){
					sum +=arr[i][j];
				}			
			}
			//	�ؿ� �� 
			for(int i=half; i<N; i++){
				for(int j=i-half; j<N-(i-half); j++){
					sum +=arr[i][j];
				}			
			}
			
			System.out.println("#"+tc+" "+sum);
		}
		
		

	}

}
