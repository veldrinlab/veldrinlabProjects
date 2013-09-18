package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.HashMap;
import java.util.Map;
import java.util.Timer;
import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.*;
import pl.edu.pw.elka.home.sjablon1.view.*;
import pl.edu.pw.elka.home.sjablon1.view.event.*;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.*;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.*;
import pl.edu.pw.elka.home.sjablon1.view.event.player.*;

/**
 * Class defines one of main class of Game MVC architecture - the Controller Unit. Controller
 * receives Event from View and contact with Model and View to execute Events. Controller Unit
 * works in own thread receiving Event from BlockingQueue - connection with View Unit. Controller
 * works until it receives ExitGameEvent.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Controller
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/**Event witch controller had taken from BlockingQueue and try to execute*/
	private GameEvent eventOccurred;
	/** Object of ControllerVisitor to Visit accepted Visitable class */
	private ControllerVisitor visitor;	
	/** Map of connection between occurred Event and Execute visitable class */
	private Map<Class<? extends GameEvent>, ExecuteClass> executeMap;
	/** Time quantum exceeded data */
	private boolean timeExceeded;
	
	/**
	 * Default constructor of Controller object.
	 * 
	 * @param model is Game MVC model
	 * @param view is Game View model
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public Controller(Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		this.setView(view);
		this.setArrayBlockingEventQueue(blockingEventQueue);
		this.setVisitor(new ControllerVisitor(blockingEventQueue));
		this.initializeExecuteMap();
		this.timeExceeded = false;
		
	}
	
	/**
	 * Method used to set Game Timer.
	 */
	public void setGameTimer()
	{
		Timer timer = new Timer();
		TimeQuantumExceeded timerTask = new TimeQuantumExceeded(this,timer);
		timer.schedule(timerTask, 1000);
	}
	
	
	/**
	 * Main method of Controller Unit thread. take Events from Event Queue and
	 * execute it.
	 * 
	 * @throws InterruptedException
	 */
	public void run()
	{
		this.setGameTimer();
		
		while(true)
		{
			try
			{
				if(!timeExceeded && !blockingEventQueue.isEmpty())
				{
					eventOccurred = blockingEventQueue.take();
					this.executeMap.get(eventOccurred.getClass()).accept(this.getVisitor(), 
						this.getModel(), this.getView(), this.getBlockingEventQueue());
				}
			 
			}
			catch (InterruptedException e)
			{
				System.out.println("Taking Event from Queue failed!");
				e.printStackTrace();
				System.exit(0);
			}
	
		}
	}
	
	/**
	 * Method used to initialize Execute Map to avoid using reflection in application.
	 */
	public void initializeExecuteMap()
	{
		executeMap = new HashMap<Class<? extends GameEvent>, ExecuteClass>();
		
		executeMap.put(NewGameEvent.class, new ExecuteNewGame());
		executeMap.put(OptionsEvent.class, new ExecuteOptions());
		executeMap.put(CreditsEvent.class, new ExecuteCredits());
		executeMap.put(BackToMenuEvent.class, new ExecuteBackToMenu());
		executeMap.put(ExitGameEvent.class, new ExecuteExitGame());
		
		executeMap.put(PlayerMoveUpEvent.class, new ExecutePlayerMoveUp());
		executeMap.put(PlayerMoveDownEvent.class, new ExecutePlayerMoveDown());
		executeMap.put(PlayerMoveLeftEvent.class, new ExecutePlayerMoveLeft());
		executeMap.put(PlayerMoveRightEvent.class, new ExecutePlayerMoveRight());
		executeMap.put(PlayerStopEvent.class, new ExecutePlayerStop());
		executeMap.put(PlayerChangeStateEvent.class, new ExecutePlayerChangeState());
		executeMap.put(PlayerPlantBombEvent.class, new ExecutePlayerPlantBomb());
		
		executeMap.put(EnemyMoveUpEvent.class, new ExecuteEnemyMoveUp());
		executeMap.put(EnemyMoveDownEvent.class, new ExecuteEnemyMoveDown());
		executeMap.put(EnemyMoveLeftEvent.class, new ExecuteEnemyMoveLeft());
		executeMap.put(EnemyMoveRightEvent.class, new ExecuteEnemyMoveRight());
		executeMap.put(EnemyStopEvent.class, new ExecuteEnemyStop());
		executeMap.put(EnemyChangeStateEvent.class, new ExecuteEnemyChangeState());
		executeMap.put(EnemyPlantBombEvent.class, new ExecuteEnemyPlantBomb());
		
		executeMap.put(BombBlowUpEvent.class, new ExecuteBombBlowUp());
		executeMap.put(BombChangeStateEvent.class, new ExecuteBombChangeState());
		executeMap.put(ExplosionStartEvent.class, new ExecuteExplosionStart());
		executeMap.put(ExplosionEndEvent.class, new ExecuteExplosionEnd());
		executeMap.put(ExplosionChangeStateEvent.class, new ExecuteExplosionChangeState());
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
	public void setArrayBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
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
	 * @param eventOccurred the eventOccurred to set
	 */
	public void setEventOccurred(GameEvent eventOccurred)
	{
		this.eventOccurred = eventOccurred;
	}

	/**
	 * @return the eventOccurred
	 */
	public GameEvent getEventOccurred()
	{
		return eventOccurred;
	}

	/**
	 * @param visitor the visitor to set
	 */
	public void setVisitor(ControllerVisitor visitor)
	{
		this.visitor = visitor;
	}

	/**
	 * @return the visitor
	 */
	public ControllerVisitor getVisitor()
	{
		return visitor;
	}

	/**
	 * @param timeExceeded the timeExceeded to set
	 */
	public void setTimeExceeded(boolean timeExceeded)
	{
		this.timeExceeded = timeExceeded;
	}

	/**
	 * @return the timeExceeded
	 */
	public boolean isTimeExceeded()
	{
		return timeExceeded;
	}

}
