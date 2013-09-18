package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Explosion;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.PositionStatic;
import pl.edu.pw.elka.home.sjablon1.view.ExplosionAnimation;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents ExplosionEnd event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteExplosionEnd extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;	
	/** Array of Explosion on GameBoard */
	private Explosion[] explosionArray;
	/** Array of Explosion Position */
	private PositionStatic[] explosionPosition;
	/** Array of Explosion Animation */
	private ExplosionAnimation[] explosionAnimationArray;
	
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		this.setView(view);
		v.visit( this );
	}
	
	/**
	 * Method used to get Explosion Data.
	 */
	public void getExplosionData()
	{
		explosionArray = this.getModel().getExplosionArray();
		explosionPosition = this.getModel().getExplosionPositionArray();
		explosionAnimationArray = this.getView().getExposionAnimationArray();
	}
	
	/**
	 * Method used to execute Explosion End Event
	 * 
	 * @return index of Explosion Collision detector.
	 */
	public int executeExplosionEnd()
	{
		for(int i = 0; i<explosionArray.length; i++)
		{
			if(explosionArray[i] != null && explosionArray[i].getExplosionState() == ExplosionState.End)
			{

				explosionAnimationArray[i].stopAnimation();
				explosionAnimationArray[i].setVisible(false);
				explosionAnimationArray[i] = null;
				explosionArray[i] = null;
				explosionPosition[i] = null;
				this.getModel().decreaseExplosionNumber();
				this.getModel().updateExplosionData(explosionPosition, explosionArray);
				return i;
			}
		}
		return -1;
	}

	/**
	 * @param model the model to set
	 */
	public void setModel(Model model)
	{
		this.model = model;
	}

	/**
	 * @return the model
	 */
	public Model getModel()
	{
		return model;
	}

	/**
	 * @param view the view to set
	 */
	public void setView(View view)
	{
		this.view = view;
	}

	/**
	 * @return the view
	 */
	public View getView()
	{
		return view;
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

}
