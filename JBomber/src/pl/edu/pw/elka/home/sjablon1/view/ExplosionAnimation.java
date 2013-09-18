package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.LinkedList;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.utility.Pair;
import pl.edu.pw.elka.home.sjablon1.view.event.ExplosionChangeStateEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.ExplosionChangeStateListener;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents ExplosionAnimation view. There are one of static animation, Explosion start only on
 * GameGraph Vertex.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionAnimation extends Animation
{
	/** List of objects listeners*/
	private EventListenerList listenerList;
	/** Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** LinkedList of explosion range elements depends on Explosion power level */
	private LinkedList<Pair> explosionRange;
	
	/**
	 * Default constructor of ExplosionAnimation object.
	 * 
	 * @param explosionSpriteScheetFileName name of file contains animation SpriteSheet
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public ExplosionAnimation(final String explosionSpriteScheetFileName,ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
        this.setBackground(Color.WHITE);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
      
		this.setAnimatingSprite(new Sprite(explosionSpriteScheetFileName));
		
		this.setBlockingEventQueue(blockingEventQueue);
		this.setListenerList(new EventListenerList());
		this.addExplosionChangeStateListener(new ExplosionChangeStateListener());
		this.setAnimationRolling(false);
	}
	
	@Override
	/**
	 * Method used to start animation.
	 */
	public void startAnimation()
	{
		this.setAnimationRolling(true);
		this.runAnimation();
		
	}

	@Override
	/**
	 * Method used to stop animation.
	 */
	public void stopAnimation()
	{
		this.setAnimationRolling(false);
	}

	@Override
	/**
	 * Method defines what parameters change in each animationCycle. 
	 */
	public void animationCycle()
	{
		/** Static animation only change states, when reach end - fireEndExlosionEvent */
	}


	
	@Override
	/**
	 * Override method that paints Animation Frame.
	 * 
	 * @param g is Graphics context. 
	 */
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D)g;
        
        Image drawSource = this.getAnimatingSprite().getSpriteSheet();
        
        int srcX1 = this.getAnimatingSprite().getSpritePositionX();
        int srcY1 = this.getAnimatingSprite().getSpritePositionY();
        int srcX2 = srcX1 + this.getAnimatingSprite().getSpriteWidth();
        int srcY2 = srcY1 + this.getAnimatingSprite().getSpriteHeight();

        
        LinkedList<Pair> e = this.getExplosionRange();
        for(int i = 0; i<e.size(); i++)
        {
        	Pair position = e.get(i);
        	int destX1 = position.getX();
        	int destY1 = position.getY();
        	int destX2 = destX1 + this.getAnimatingSprite().getSpriteWidth();
        	int destY2 = destY1 + this.getAnimatingSprite().getSpriteHeight();
        	g2d.drawImage(drawSource,destX1,destY1,destX2,destY2,srcX1,srcY1,srcX2,srcY2,this);
        }
    	Toolkit.getDefaultToolkit().sync();
    	g.dispose();
    }
	
	/**
	 * Method that runs animation
	 */
	public void runAnimation()
	{
		animationCycle();
	    repaint();
	}
	
	/**
	 * Method that allows classes to register for ExplosionChangeStateListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addExplosionChangeStateListener(final ExplosionChangeStateListener listener)
	{ 
		listenerList.add(ExplosionChangeStateListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for ExplosionChangeStateListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeExplosionChangeStateListener(final ExplosionChangeStateListener listener) 
	{ 
		listenerList.remove(ExplosionChangeStateListener.class, listener); 
	}
	
	/**
	 * Method that fire defined ExplosionChangeStateEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireExplosionChangeStateEvent(final ExplosionChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==ExplosionChangeStateListener.class) 
			{ 
				((ExplosionChangeStateListener)listeners[i+1]).explosionChangeStateEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * @param listenerList the listenerList to set
	 */
	public void setListenerList(final EventListenerList listenerList)
	{
		this.listenerList = listenerList;
	}

	/**
	 * @return the listenerList
	 */
	public EventListenerList getListenerList()
	{
		return listenerList;
	}


	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	public void setBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}

	/**
	 * @return the blockingEventQueue
	 */
	public ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

	/**
	 * @param explosionRange the explosionRange to set
	 */
	public void setExplosionRange(final LinkedList<Pair> explosionRange)
	{
		this.explosionRange = explosionRange;
	}

	/**
	 * @return the explosionRange
	 */
	public LinkedList<Pair> getExplosionRange()
	{
		return explosionRange;
	}

}