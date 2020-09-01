package Collections;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.Scanner;

import javax.swing.Spring;

class _PriorityQueue {
	PriorityQueue<Integer> pq=new PriorityQueue<>();
	Scanner sc = new Scanner(System.in);
	
	public void add()
	{
		System.out.println("\nEnter Number: ");
		int num = sc.nextInt();
		pq.add(num);
		System.out.println("Added : "+num);
	}
	
	public int remove()
	{
		int num = pq.remove();
		return num; 
	}
}

class _Stack {
	Stack<Integer> s=new Stack<>();
	Scanner sc = new Scanner(System.in);
	
	void push(int cho) {
		s.push(cho);
	}
	
	int pop() {
		int num = s.pop();
		return num;
	}
	
	int peek() {
		int num = s.peek();
		return num;
	}
}

class _LinkedList {
	LinkedList<Integer> ll = new LinkedList<>();
	Scanner sc = new Scanner(System.in);
	
	public void add(int num){
		ll.add(num);
	}
	
	public int remove(int num1){
		int num = ll.remove(num1);
		return num;
	}
	
	public int getFirst(){
		int num = ll.getFirst();
		return num;
	}
	
	public int getLast(){
		int num = ll.getLast();
		return num;
	}
}

class _ArrayList {
	ArrayList<Integer> al=new ArrayList<>();
	Scanner sc = new Scanner(System.in);
	
	public void add(int num){
		al.add(num);
	}
	
	public int remove(int num) {
		int num1 = al.remove(num);
		return num1;
	}
	
	public int size(){
		int siz = al.size();
		return siz;
	}
}

class _HashMap {
	HashMap<String, Integer> hm = new HashMap<>();
	Scanner sc = new Scanner (System.in);
	
	public void put(){
		System.out.println("\nEnter Key");
		sc.next();
		String key=sc.nextLine();
		System.out.println("\nEnter Value: ");
		int value=sc.nextInt();
		hm.put(key, value);
	}
	
	public int remove(String key){
		return hm.remove(key);
	}
	
	public int size(){
		return hm.size();
	}
	
	public int hashCode(){
		return hm.hashCode();
	}
}

public class Collections {
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int choice;
		
		_PriorityQueue q1 = new _PriorityQueue();
		_Stack q2 = new _Stack();
		_LinkedList q3 = new _LinkedList();
		_ArrayList q4 = new _ArrayList();
		_HashMap q5 = new _HashMap();

		do
		{
			System.out.println("Enter your choice: \n1. Queue\n2. Stack\n3. Linked List\n4. ArraList\n5. Map\n6. Exit");
			choice=sc.nextInt();
			
			switch(choice)
			{
			case 1:
			
				System.out.println("\n1. Enqueue\n2. Dequeue\n3. EXIT");
				choice = sc.nextInt();
				
				switch(choice)
				{
				case 1:
					q1.add();
					break;
					
				case 2:
					System.out.println("\nRemoved element:=>"+q1.remove());
					break;

				case 3:
					System.out.println("\nBack to MAIN MENU ");
					break;
					
				default:
					System.out.println("Select a valid option ");
					break;
				}
				break;
				
			case 2:
				System.out.println("\n1. Push\n2. Pop\n3. Top\n4. EXIT");
				choice=sc.nextInt();
				
				switch(choice)
				{
				case 1:
					System.out.println("\nEnter Number: ");
					int num = sc.nextInt();
					q2.push(num);
					break;
				
				case 2:
					System.out.println("\nPopped elemet:=> "+q2.pop());
					break;
				
				case 3:
					System.out.println("\nStack top: "+q2.peek());
					break;
				
				case 4:
					System.out.println("\nBack to MAIN MENU ");
					break;
					
				default:
					System.out.println("Select a valid option ");
					break;
				}
				break;
				
			case 3:

				System.out.println("\n====Linked LIST =====\n1. ADD\n2. Remove\n3. First\n4. Last\n5. EXIT");
				choice=sc.nextInt();
				
				switch(choice)
				{
				case 1:
					System.out.println("\nEnter Number: ");
					q3.add(new Integer(sc.nextInt()));
					break;
				
				case 2:
					System.out.println("\nEnter element to remove: ");
					int num = sc.nextInt();
					System.out.println("]nRemoved element:"+q3.remove(num));
					break;
				
				case 3:
					System.out.println("\nFirst Element: "+q3.getFirst());
					break;
				
				case 4:
					System.out.println("\nLast Element: "+q3.getLast());
					break;
				
				case 5: 
					System.out.println("\nBack to MAIN MENU ");
					break;
					
				default:
					System.out.println("Select a valid option ");
					break;
				}
				break;
				
			case 4:
				System.out.println("\n====ARRAY LIST ========\n1. add\n2. delete\n3. size\n4. Exit");
				choice = sc.nextInt();
				
				switch(choice){
				case 1:
					int num = sc.nextInt();
					q4.add(num);
					break;
					
				case 2:
					System.out.println("Which INDEX num do you want to remove ? ");
					int index = sc.nextInt();
					
					System.out.println("Removed element : "+q4.remove(index));
					break;
					
				case 3:
					System.out.println("\nSize: "+q4.size());
					break;
					
				case 4:
					System.out.println("\nBack to MAIN MENU ");
					break;
					
				default:
					System.out.println("Select a valid option ");
					break;	
				}
				
				break;

			case 5:
				System.out.println("\n===== Hash Map=====\n1. Insert\n2. Remove\n3. Size\n4. Hash code\n5. Exit");
				choice = sc.nextInt();
				
				switch(choice)
				{
				case 1:
					q5.put();
					System.out.println("\nRecord Insserted");
					break;
					
				case 2:
					System.out.println("\nRemoved element (roll):"+q5.remove("roll"));
					break;
					
				case 3:
					System.out.println("\nSize: "+q5.size());
					break;
					
				case 4:
					System.out.println("\nHashcode Value for this map: "+q5.hashCode());
					break;
					
				case 5:
					System.out.println("\nBack to MAIN MENU ");
					break;
					
				default:
					System.out.println("Select a valid option ");
					break;	
				}
				
				break;
				
			case 6:
				System.out.println("\nTERMINATING !! ");
				break;
				
			default:
				System.out.println("Select a valid option ");
				break;
			}
		}while(choice!=6);
	}
}
