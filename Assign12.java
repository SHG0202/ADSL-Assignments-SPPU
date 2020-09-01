package myPackage;

import java.util.Scanner;


abstract class MyStack{
	public final void Push(){
		show();
		push();
		display();
	}
	
	public final void Pop(){
		show();
		pop();
		display();
	}
	
	abstract protected void push();
	
	abstract protected void pop();
	
	abstract protected void display();
	
	protected abstract boolean isEmpty();
	
	abstract protected boolean isFull();
	
	protected void show(){
		System.out.println("Stack implementation");
	}
}

class IntStack extends MyStack{

	private int top;
	private int[] s;
	
	IntStack(int num){
		if(num <= 0){
			throw new IllegalArgumentException(
					"Must be greater then 0 ");
		}
		s = new int[num];
		top = -1;
	}
	
	protected void push() {
		System.out.print("ADD Element : ");
		Scanner sc = new Scanner(System.in);
		int ele = sc.nextInt();
		System.out.println();
		
		try{
			if(top == s.length - 1){
				throw new Exception("OVERFLOW");
			}
			top ++;
			s[top] = ele;
		}
		catch(Exception e){
			System.out.println("Exception: "+e.getMessage());
		}
	}

	protected void display() {
		System.out.print("Stack is : ");
		for(int i = top; i >= 0; i--){
			System.out.print(s[i] + " ");
		}
		System.out.println();
	}

	protected void pop() {
		try
		{
			if(top < 0){
				throw new Exception("UNDERFLOW");  
			}
			int ele = s[top];
			top--;
			System.out.println("Top element is : "+ele);
		}
		catch(Exception e){
			System.out.println("Exception : "+e.getMessage());
		}
	}

	protected boolean isEmpty() {
		if(top == -1)
			return true;
		else
			return false;
	}

	protected boolean isFull() {
		if(top == s.length)
			return true;
		else
			return false;
	}
}

class CharStack extends MyStack{

	private int top;
	private char[] s;
	
	CharStack(int num){
		if(num <= 0){
			throw new IllegalArgumentException(
					"Must be greater then 0 ");
		}
		s = new char[num];
		top = -1;
	}
	
	protected void push() {
		System.out.print("ADD Element : ");
		Scanner sc = new Scanner(System.in);
		char ele = sc.next().charAt(0);
		System.out.println();
		
		try{
			if(top == s.length - 1){
				throw new Exception("OVERFLOW");
			}
			top ++;
			s[top] = ele;
		}
		catch(Exception e){
			System.out.println("Exception: "+e.getMessage());
		}
	}

	protected void display() {
		System.out.print("Stack is : ");
		for(int i = top; i >= 0; i--){
			System.out.print(s[i] + " ");
		}
		System.out.println();
	}

	protected void pop() {
		try
		{
			if(top > -1){
				throw new Exception("UNDERFLOW");  
			}
			char ele = s[top];
			System.out.println("Top element is : "+ele);
		}
		catch(Exception e){
			System.out.println("Exception : "+e.getMessage());
		}
	}

	protected boolean isEmpty() {
		if(top == -1)
			return true;
		else
			return false;
	}

	protected boolean isFull() {
		if(top == s.length)
			return true;
		else
			return false;
	}
}

public class Assign12 {
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
		int cho;
        do{
        	System.out.println("Select INTEGER OR CHARACTER");
    		System.out.println("1. Integer  ");
    		System.out.println("2. Character");
    		System.out.println("3. EXIT     ");
    		cho = sc.nextInt();
    		
    		switch(cho){
    		case 1:
    		{
    			int cho2;
    			
    			System.out.println("MAX SIZE OF STACK ? ");
    			int n = sc.nextInt();
    			IntStack ST = new IntStack(n);
    			do{
    				System.out.println("Select a Task ");
        			System.out.println("1. Push an element ");
        			System.out.println("2. Pop an element");
        			System.out.println("3. Check if Empty ");
        			System.out.println("4. Check if Full ");
        			System.out.println("5. Display ");
        			System.out.println("6. EXIT     ");
        			cho2 = sc.nextInt();
        			
        			switch(cho2){
        			case 1:
        				ST.Push();
        				break;
        				
        			case 2:
        				ST.Pop();
        				break;
        				
        			case 3:
        				if(ST.isEmpty())
        					System.out.println("Stack is Empty ");
        				else
        					System.out.println("Stack is not empty ");
        				break;
        				
        			case 4:
        				if(ST.isFull())
        					System.out.println("Stack is Full ");
        				else
        					System.out.println("Stack is not full ");
        				break;
        				
        			case 5:
        				ST.display();
        				break;
        				
        			case 6:
        				System.out.println("Back to MAIN MENU !! ");
        				break;
        				
    				default:
    					System.out.println("Select a valid option ");
    					break;
        			}
        			
    			}while(cho2 != 6);
    			
    		}
    			break;
    			
    		case 2:
    		{
    			int cho3;
    			
    			System.out.println("MAX SIZE OF STACK ? ");
    			int n = sc.nextInt();
    			CharStack ST = new CharStack(n);
    			do{
    				System.out.println("Select a Task ");
        			System.out.println("1. Push an element ");
        			System.out.println("2. Pop an element");
        			System.out.println("3. Check if Empty ");
        			System.out.println("4. Check if Full ");
        			System.out.println("5. Display ");
        			System.out.println("6. EXIT     ");
        			cho3 = sc.nextInt();
        			
        			switch(cho3){
        			case 1:
        				ST.Push();
        				break;
        				
        			case 2:
        				ST.Pop();
        				break;
        				
        			case 3:
        				if(ST.isEmpty())
        					System.out.println("Stack is Empty ");
        				else
        					System.out.println("Stack is not empty ");
        				break;
        				
        			case 4:
        				if(ST.isFull())
        					System.out.println("Stack is Full ");
        				else
        					System.out.println("Stack is not full ");
        				break;
        				
        			case 5:
        				ST.display();
        				break;
        				
        			case 6:
        				System.out.println("Back to MAIN MENU !! ");
        				break;
        				
    				default:
    					System.out.println("Select a valid option ");
    					break;
        			}
        			
    			}while(cho3 != 6);
    			
    		}
    			break;
    			
    		case 3:
    			System.out.println("Terminating !! ");
    			break;
    			
			default:
				System.out.println("Select a valid option ");
				break;
    		}
        }while(cho != 3);
		
    }
}
