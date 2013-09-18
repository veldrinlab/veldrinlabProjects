package pl.edu.pw.elka.home.sjablon1.view;

import java.util.concurrent.BlockingQueue;

import javax.swing.JButton;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.CreditsButtonListener;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.CreditsEvent;


/**
 * Class represents object of CreditsButton that generate CreditsEvent. It is one of
 * four buttons from MenuButtonPanel.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class CreditsButton extends JButton
{
	
	/**List of objects listeners*/
	private EventListenerList listenerList;

	/**
	 * Default constructor of CreditsButton object. It creates instance of CreditsButton class
	 * with custom backgroundImage, and add additional Listener for CreditsEvent which is fired
	 * by actionPerformed method of JButton
	 */
	public CreditsButton()
	{
		super("   Credits   ");
		this.setDefaultCapable(false);
		listenerList = new EventListenerList();
		this.addCreditsButtonListener(new CreditsButtonListener());
		
	}
		
	/**
	 * Method that allows classes to register for CreditsEvents
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addCreditsButtonListener(final CreditsButtonListener listener)
	{ 
		listenerList.add(CreditsButtonListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for CreditsEvent
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeCreditsButtonListener(final CreditsButtonListener listener) 
	{ 
		listenerList.remove(CreditsButtonListener.class, listener); 
	}
	
	/**
	 * Method that fire defined CreditsEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireCreditsEvent(final CreditsEvent event, BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==CreditsButtonListener.class) 
			{ 
				((CreditsButtonListener)listeners[i+1]).creditsEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}

}
