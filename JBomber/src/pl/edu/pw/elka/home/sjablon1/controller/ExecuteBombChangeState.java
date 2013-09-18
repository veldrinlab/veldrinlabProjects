package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Bomb;
import pl.edu.pw.elka.home.sjablon1.model.BombExploadingState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.BombBlowUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents BaombChangeState execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteBombChangeState extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;	
	/** Array of Bomb on GameBoard */
	private Bomb[] bombArray;
	
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
	 * Method used to get Bomb data.
	 */
	public void getBombData()
	{
		 bombArray = this.getModel().getBombArray();
	}
	
	/**
	 * Method used to update Bomb state.
	 */
	public void updateBombState()
	{	
		for(int i=0; i<bombArray.length; i++)
		{
			if(bombArray[i]!=null)
			{
				bombArray[i].setBombState(bombArray[i].getBombState().getNextState());
				if(bombArray[i].getBombState() == BombExploadingState.Blow)
				{
					this.getBlockingEventQueue().add(new BombBlowUpEvent(this));
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
