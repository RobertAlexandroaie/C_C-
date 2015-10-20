/*
 * Created by SharpDevelop.
 * User: info
 * Date: 30.10.2007
 * Time: 9:47 AM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Windows.Forms; 
using System.IO; 

namespace Delegate_CA
{
	public class Manager
	{
		
	}
	
	public class Email
	{
		
	}
class Set 
{ 
	private Object[] items; 
	public Set(Int32 numItems) 
	{ 
		items = new Object[numItems]; 
		for (Int32 i = 0; i < numItems; i++) 
			items[i] = i; 
	}
	
	// Definim tipul FeedBack. (delegate)
	// ATENTIUNE! Tipul se defineste in cadrul clasei Set
	// In fapt este un prototip de functie (metoda).
 
	public delegate void Feedback(Object value, 
				Int32 item, 
				Int32 numItems); 

	// 
	// Definim metoda ce are un parametru de tip FeedBack
	//
	public void ProcessItems(Feedback feedback) 
	{ 
		for (Int32 item = 0; item < items.Length; item++) 
		{ 
			if (feedback != null) 
			{ 
				//
				// Daca s-a specificat o functie callback, 
				// atunci o apelam.
				//
				feedback(items[item], item + 1, items.Length); 
			}
			else
			{
				Console.WriteLine("Nu s-a specificat o metoda.");
			}
		}  
	} 
}

class App 
{ 
	static void Main() 
	{ 
		StaticCallbacks(); 
		InstanceCallbacks(); 
		Console.ReadLine();
	} 

	static void StaticCallbacks() 
	{ 
	
		// Creem un tablou cu 5 elemente de tip Set
		
		Set setOfItems = new Set(5); 
		
		// Procesam articolele fara a furniza o metoda callback
		
		setOfItems.ProcessItems(null); 
		Console.WriteLine("S-a terminat apelul pentru cazul cand nu am furnizat o metoda callbak");
		
		// delegate anonim
		setOfItems.ProcessItems(delegate
		                        {
		                        	Console.WriteLine("Delegate anonim");
		                        }
		                       );
		//
		// Procesam articolele si furnizam metoda 
		// callback FeedbackToConsole
		// Se apeleaza ProcessItems din clasa Set in care se furnizeaza
		// metoda ce va fi apelata.
		//
		setOfItems.ProcessItems(new Set.Feedback(App.FeedbackToConsole)); 
		Console.WriteLine("S-a executat FeedBackToConsole"); 

		// Procesam articolele fara a furniza o alta metoda callback

		setOfItems.ProcessItems(new Set.Feedback(App.FeedbackToMsgBox)); 
		Console.WriteLine("S-a executat FeedBackToMsgBox"); 

		// Procesam articolele, si folosim doua metode callback:
		// FeedbackToConsole si FeedbackToMsgBox.
		// Pentru fiecare articol se apeleaza ambele metode.
		// Se creaza o lista de metode callback. 

		Set.Feedback fb = null; 
		fb += new Set.Feedback(App.FeedbackToConsole); 
		fb += new Set.Feedback(App.FeedbackToMsgBox); 
		setOfItems.ProcessItems(fb); 
		Console.WriteLine("S-a executat un lant de metode"); 
	}
	 //
	 // este private
	 //
	static void FeedbackToConsole(Object value, Int32 item, Int32 numItems) 
	{ 
		Console.WriteLine("Processing item {0} of {1}: {2}.",item, numItems, value); 
	} 
 
	//
	// este private
	//

	static void FeedbackToMsgBox( Object value, Int32 item, Int32 numItems) 
	{
		MessageBox.Show(String.Format("Processing item {0} of {1}: {2}.",item, numItems, value)); 
	} 
	
	static void InstanceCallbacks() 
	{ 
		// Creaza o multime cu 5 elemente. 
		Set setOfItems = new Set(5); 
		
		// Proceseaza articolele, si apeleaza 
		// metoda callback FeedbackToFile. 
		
		App appobj = new App(); 
		setOfItems.ProcessItems(new Set.Feedback(appobj.FeedbackToFile)); 
		Console.WriteLine(); 
	}
	
	//
	// este private
	//
	
	void FeedbackToFile( Object value, Int32 item, Int32 numItems) 
	{ 
		StreamWriter sw = new StreamWriter("Status", true); 
		sw.WriteLine("Processing item {0} of {1}: {2}.", item, numItems, value); 
		sw.Close(); 
	}
}
}
