import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Shutdown {

	public static void main(String[] args) throws IOException{
		Runtime run = Runtime.getRuntime();
		BufferedReader buffreader = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Enter the time in seconds: ");
		long a = Long.parseLong(buffreader.readLine());
		Process pro = run.exec("shutdown -s -t " + a);
		System.exit(0);
	}

}
