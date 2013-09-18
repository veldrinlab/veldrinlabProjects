package pl.edu.pw.elka.home.sjablon1.view;

import java.util.concurrent.BlockingQueue;

import javax.swing.JButton;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.ExitGameButtonListener;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.ExitGameEvent;


/**
 * Class represents object of ExitGameButton that generate ExitGameEvent. It is one of
 * four buttons from MenuButtonPanel.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExitGameButton extends JButton
{
	/**List of objects listeners*/
	private EventListenerList listenerList;

	/**
	 * Default constructor of ExitGameButton object. It creates instance of ExitGameButton class
	 * with custom backgroundImage, and add additional Listener for ExitGameEvent which is fired
	 * by actionPerformed method of JButton
	 */
	public ExitGameButton()
	{
		super("Exit Game");
		listenerList = new EventListenerList();
		this.addExitGameButtonListener(new ExitGameButtonListener());	
	}
		
	/**
	 * Method that allows classes to register for ExitGameEvents
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addExitGameButtonListener(final ExitGameButtonListener listener)
	{ 
		listenerList.add(ExitGameButtonListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for ExitGameEvent
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeExitGameButtonListener(final ExitGameButtonListener listener) 
	{ 
		listenerList.remove(ExitGameButtonListener.class, listener); 
	}
	
	/**
	 * Method that fire defined ExitGameEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireExitGameEvent(final ExitGameEvent event, BlockingQueue<GameEvent> blockingEventQueue)
	{	
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==ExitGameButtonListener.class) 
			{ 
				((ExitGameButtonListener)listeners[i+1]).exitGameEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
}