import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class swexpert_1213 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int tc=1; tc<=10; tc++){
			int num = Integer.parseInt(br.readLine());
			
			//	비교랑 비교할 문자열 입력받기 
			String target = br.readLine();
			int targetLength = target.length();
			
			StringBuffer sentence = new StringBuffer(br.readLine());
			
			
			int start=0, end=targetLength, count =0;
			for(int i=0; i< sentence.length() - targetLength+1; i++){
				//String temp = sentence.substring(start, end);
				if(target.equals(sentence.substring(start, end))){
					count++;
				}
				start++;
				end++;
			}
			
			System.out.println("#"+num+" "+count);
		}

	}

}
