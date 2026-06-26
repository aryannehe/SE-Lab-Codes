import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class External_sorting
{
	public static void main(String args[])
	{	
		String ipFile = "input_file.txt";
		String opFile = "output_file.txt";
	
		ArrayList<Integer> numbers = readNumbersFromFile(ipFile);
		
		if (numbers != null)
		{
			Collections.sort(numbers);
			if (writeNumbersIntoFile(opFile, numbers))
			{
				System.out.println("Sorted numbers succesfully written into file.");
			}
			else
			{
				System.out.println("Error writing numbers into file");
			}
		}
		else
		{
			System.out.println("Error reading numbers from file");
		}
	}

	private static ArrayList<Integer> readNumbersFromFile(String ipFile)
	{
		ArrayList<Integer> numbers = new ArrayList<> ();

		try(BufferedReader br = new BufferedReader(new FileReader(ipFile)))
		{
			String line;
			
			while(((line = br.readLine()) != null))
			{
				try
				{
					int number = Integer.parseInt(line);
					numbers.add(number);
				}
				catch (NumberFormatException e)
				{
					System.err.println("Invalid number found: " + line);
				}
			}
		}
		catch (IOException e)
		{
			System.err.println("Error in opening file: " + e.getMessage());
			return null;
		}
		return numbers;
	}

	private static boolean writeNumbersIntoFile(String opFile, ArrayList<Integer> numbers)
	{
		try(BufferedWriter bw = new BufferedWriter(new FileWriter(opFile)))
		{
			for (int number : numbers)
			{
				bw.write(Integer.toString(number));
				bw.newLine();
			}
		}
		catch(IOException e)
		{
			System.err.println("Error in opening output file : " + e.getMessage());
			return false;
		}
		return true;
	}
}

	 
