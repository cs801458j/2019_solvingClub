import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class swexpert_4751 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());

		for(int tc=1; tc<=T; tc++){
			String word = br.readLine();
			int wordLength = word.length();
			for(int i=0; i<5; i++){
				StringBuffer sb = new StringBuffer();
				if(i==0 || i==4){
					sb.append("..#");
					for(int j=0; j<word.length()-1; j++){
						sb.append("...#");
					}
					sb.append("..");
				}
				else if(i==1 || i==3){
					for(int j=0; j<word.length()*2; j++){
						sb.append(".#");
					}
					sb.append(".");
				}
				else{
					for(int j=0; j<word.length(); j++){
						sb.append("#."+word.charAt(j)+".");
					}
					sb.append("#");
				}
				System.out.println(sb);
			}
		}
		

	}

}
