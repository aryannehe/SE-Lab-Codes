import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class New {
    public static void main(String args[])
    {
        String ipFile = "numbers.txt";
        String opFile = "sorted_numbers.txt";

        ArrayList<Integer> numbers = readNumbersFromFile(ipFile);
        if (numbers != null)
        {
            Collections.sort(numbers);
            if (writeNumbersToFile(opFile, numbers))
            {
                System.out.println("Succesfullt sorten numbers and written into file: " + opFile);
            }
            else{
                System.out.println("Error in writing numbers to file.");
            }
        }
        else{
            System.out.println("Error in reading numbers from file");
        }
    }

    private static ArrayList<Integer> readNumbersFromFile(String file)
    {
        ArrayList<Integer> numbers = new ArrayList<>();

        try(BufferedReader br = new BufferedReader(new FileReader(file)))
        {
            String line;
            while((line = br.readLine()) != null)
            {
                try{
                    int number = Integer.parseInt(line);
                    numbers.add(number);
                }
                catch(NumberFormatException e){
                    System.err.println("Wrong format found" + line);
                }

            }
        }
        catch(IOException e)
        {
            System.err.println("Cannot read numbers from file" + e.getMessage());
            return null;
        }
        return numbers;
    }

    private static boolean writeNumbersToFile(String file, ArrayList<Integer> numbers)
    {
        try(BufferedWriter br = new BufferedWriter(new FileWriter(file)))
        {
            for(int number: numbers)
            {
                br.write(Integer.toString(number));
                br.newLine();
            }
        }
        catch(IOException e){
            System.err.println("Cannot write numbers to file" + e.getMessage());
            return false;
        }

        return true;
    }
    
}
