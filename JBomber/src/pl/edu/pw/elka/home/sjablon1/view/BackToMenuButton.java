package pl.edu.pw.elka.home.sjablon1.view;

import java.util.concurrent.BlockingQueue;
import javax.swing.JButton;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.BackToMenuButtonListener;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.BackToMenuEvent;


/**
 * Class represents object of BackToMenuButton that generate BackToMenuEvent. It is used to back to Menu
 * View after entering options or credits view.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BackToMenuButton extends JButton
{	
	/**List of objects listeners*/
	private EventListenerList listenerList;
	
	/**
	 * Default constructor of BackToMenuButton object. It creates instance of BackToMenuButton class
	 * with custom backgroundImage, and add additional Listener for BackToMenuEvent which is fired
	 * by actionPerformed method of JButton
	 */
	public BackToMenuButton()
	{
		super("   BackToMenu  ");
		listenerList = new EventListenerList();
		this.addBackToMenuButtonListener(new BackToMenuButtonListener());
		
	}
		
	/**
	 * Method that allows classes to register for BackToMenuEvents
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addBackToMenuButtonListener(final BackToMenuButtonListener listener)
	{ 
		listenerList.add(BackToMenuButtonListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for BackToMenuEvent
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeBackToMenuButtonListener(final BackToMenuButtonListener listener) 
	{ 
		listenerList.remove(BackToMenuButtonListener.class, listener); 
	}
	
	/**
	 * Method that fire defined BackToMenuEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireBackToMenuEvent(final BackToMenuEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==BackToMenuButtonListener.class) 
			{ 
				((BackToMenuButtonListener)listeners[i+1]).backToMenuEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
}
