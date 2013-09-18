package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Explosion;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.ExplosionEndEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents ExplosionChangeState event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteExplosionChangeState extends ExecuteClass
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
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		this.setBlockingEventQueue(blockingEventQueue);
		v.visit( this );
	}
	
	/**
	 * Method used to get Explosion data.
	 */
	public void getExplosionData()
	{
		 explosionArray = this.getModel().getExplosionArray();
	}
	
	/**
	 * Method used to update Explosion state.
	 */
	public void updateExplosionState()
	{
		for(int i=0; i<explosionArray.length; i++)
		{
			if(explosionArray[i]!=null)
			{
				explosionArray[i].setExplosionState(explosionArray[i].getExplosionState().getNextState());
				if(explosionArray[i].getExplosionState() == ExplosionState.End)
				{
					this.getBlockingEventQueue().add(new ExplosionEndEvent(this));
				}
			}
		}
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
