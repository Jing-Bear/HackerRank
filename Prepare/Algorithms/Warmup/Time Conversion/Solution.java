import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String s) {
        String[] times = s.substring(0, s.length() - 2).split(":");
        if(s.charAt(8) == 'P' && !times[0].equals("12"))
        {
            times[0] = String.valueOf(Integer.parseInt(times[0]) + 12);  
        }
        else if(s.charAt(8) == 'A' && times[0].equals("12"))
        {
            times[0] = "00";
        }
        String out = "";
        for(int i = 0; i < times.length; i++)
        {
            if(!out.equals(""))
            {
                out += ":";
            }
            out += times[i];
        }
        return out;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
