import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.util.ArrayList;

public class readInt {
	public static void main(String [] args) throws IOException
	{
		File file = new File(args[0]);
		Scanner read = new Scanner(file);
		int current, max=0, size=100;
		ArrayList<Integer> temp = new ArrayList(size);
		while(read.hasNextInt()){						//if file has another integer
			current = read.nextInt();					//save current int
			if(current < 0){
				System.out.println("Only positive integers, try again.");
				return;
			}
			if(current > max){							//if current int is a greater value then save it as max
				max = current;
			}
			if(max>=size){								//if max is greater than or equal to the declared size, then declare new size to max+1
				size = ++max;
				temp = new ArrayList(size); 
			}
			temp.add(current);							//add each int in the input file to the list
		}
		
		int array[] = new int[++max]; 
		int index;
		for(int i=0; i<temp.size(); i++){
			index = temp.get(i);
			++array[index]; 
		}
		
		for(int x=0; x<array.length; x++){
			System.out.println(x + "\t" + array[x]);
		}
		
	}
}

