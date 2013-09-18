package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.BombermanMoveState;
import pl.edu.pw.elka.home.sjablon1.model.Destination;
import pl.edu.pw.elka.home.sjablon1.model.Edge;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.Player;
import pl.edu.pw.elka.home.sjablon1.model.PositionDynamic;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents PlayerChangeState event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecutePlayerChangeState extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/** Actual Player data */
	private Player player;
	/** Actual Player position data */
	private PositionDynamic playerPosition;
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		v.visit( this );
	}
	
	/**
	 * Method used to get Player actual data.
	 */
	public void getPlayerData()
	{
		this.player = this.getModel().getPlayerData();
		this.playerPosition = this.getModel().getPlayerPosition();
		
	}
	
	/**
	 * Method used to update Player state.
	 */
	public void updatePlayerState()
	{
		player.setPlayerState(player.getPlayerState().getNextState(player.isChangeDestination()));
	}
	
	/**
	 * Method used to update Player destination.
	 * 
	 * @return false if Player can't move forward.
	 */
	public boolean updatePlayerDestination()
	{
		if(player.getPlayerState() == BombermanMoveState.vertex)
		{	
			playerPosition.setPositionEdge(null);
			playerPosition.setPositionVertex(playerPosition.getDestinationVertex());
			player.setChangeDestination(false);
			
			Vertex newDestination = playerPosition.getPositionVertex();

			if(player.getPlayerDestination() == Destination.Up)
			{
				newDestination = newDestination.getUpDestination();
				playerPosition.setDestinationVertex(newDestination);
			}
			else if(player.getPlayerDestination() == Destination.Down)
			{
				newDestination = newDestination.getDownDestination();
				playerPosition.setDestinationVertex(newDestination);
			}
			else if(player.getPlayerDestination() == Destination.Left)
			{
				newDestination = newDestination.getLeftDestination();
				playerPosition.setDestinationVertex(newDestination);
			}
			else if(player.getPlayerDestination() == Destination.Right)
			{
				newDestination = newDestination.getRightDestination();
				playerPosition.setDestinationVertex(newDestination);
			}
			
			if(newDestination == null || !newDestination.isStateActive())
				return false;
	
		}
		else if(player.getPlayerState() == BombermanMoveState.edgeState1)
		{
			Edge positionEdge = this.getModel().getPlayerPositionEdge(playerPosition.getPositionVertex(),
					playerPosition.getDestinationVertex());
			playerPosition.setPositionVertex(null);
			playerPosition.setPositionEdge(positionEdge);
			return true;
		}
		
		return true;
	}
	
	
	/**
	 * Method used to update Game Model.
	 */
	public void updateGameModel()
	{
		this.getModel().updatePlayerData(player, playerPosition);
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
}
