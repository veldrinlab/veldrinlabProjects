package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.SwingUtilities;

import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.utility.Pair;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents NewGame event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteNewGame extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** GameBoard dimension data */
	private Pair dimensionPair;
	/** GameBoard structure data */
	private char[][] boardStructure;
	
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setView(view);
		this.setModel(model);
		v.visit( this );
	}
	
	/**
	 * Method used to get Model data.
	 */
	public void getModelData()
	{
		dimensionPair = this.getModel().getBoardDimension();
		boardStructure = this.getModel().getBoardStructure(dimensionPair.getX(), dimensionPair.getY());
		
	}
	
	/**
	 * Method used to execute New game.
	 */
	public void executeNewGame()
	{
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				view.displayNewGame(dimensionPair.getX(), dimensionPair.getY(), boardStructure);

			}
		});
		
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
