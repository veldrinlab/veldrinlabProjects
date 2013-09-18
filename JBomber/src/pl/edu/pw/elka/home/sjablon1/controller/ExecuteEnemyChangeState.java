package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.BombermanMoveState;
import pl.edu.pw.elka.home.sjablon1.model.Destination;
import pl.edu.pw.elka.home.sjablon1.model.Edge;
import pl.edu.pw.elka.home.sjablon1.model.Enemy;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.PositionDynamic;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents EnemyChangeState event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteEnemyChangeState extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/** Actual Enemy data */
	private Enemy enemy;
	/** Actual Enemy position data */
	private PositionDynamic enemyPosition;
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		v.visit( this );
	}
	
	/**
	 * Method used to get Enemy actual data.
	 */
	public void getEnemyData()
	{
		this.enemy = this.getModel().getEnemyData();
		this.enemyPosition = this.getModel().getEnemyPosition();
		
	}
	
	/**
	 * Method used to update Enemy state.
	 */
	public void updateEnemyState()
	{
		enemy.setEnemyState(enemy.getEnemyState().getNextState(enemy.isChangeDestination()));
	}
	
	/**
	 * Method used to update Enemy destination.
	 * 
	 * @return false if Enemy can't move forward.
	 */
	public boolean updateEnemyDestination()
	{
		if(enemy.getEnemyState() == BombermanMoveState.vertex)
		{	
			enemyPosition.setPositionEdge(null);
			enemyPosition.setPositionVertex(enemyPosition.getDestinationVertex());
			enemy.setChangeDestination(false);
			
			Vertex newDestination = enemyPosition.getPositionVertex();
			
			if(enemy.getEnemyDestination() == Destination.Up)
			{
				newDestination = newDestination.getUpDestination();
				enemyPosition.setDestinationVertex(newDestination);
			}
			else if(enemy.getEnemyDestination() == Destination.Down)
			{
				newDestination = newDestination.getDownDestination();
				enemyPosition.setDestinationVertex(newDestination);
			}
			else if(enemy.getEnemyDestination() == Destination.Left)
			{
				newDestination = newDestination.getLeftDestination();
				enemyPosition.setDestinationVertex(newDestination);
			}
			else if(enemy.getEnemyDestination() == Destination.Right)
			{
				newDestination = newDestination.getRightDestination();
				enemyPosition.setDestinationVertex(newDestination);
			}
			
			if(newDestination == null || !newDestination.isStateActive())
				return false;
	
		}
		else if(enemy.getEnemyState() == BombermanMoveState.edgeState1)
		{
			Edge positionEdge = this.getModel().getEnemyPositionEdge(enemyPosition.getPositionVertex(),
					enemyPosition.getDestinationVertex());
			enemyPosition.setPositionVertex(null);
			enemyPosition.setPositionEdge(positionEdge);
			return true;
		}
		
		return true;
	}
	
	
	/**
	 * Method used to update Game Model.
	 */
	public void updateGameModel()
	{
		this.getModel().updateEnemyData(enemy, enemyPosition);
	}
	
	/**
	 * @return the model
	 */
	public Model getModel()
	{
		return model;
	}

	/**
	 * @param model the model to set
	 */
	public void setModel(Model model)
	{
		this.model = model;
	}

	/**
	 * @return the enemy
	 */
	public Enemy getEnemy()
	{
		return enemy;
	}

	/**
	 * @param enemy the enemy to set
	 */
	public void setEnemy(Enemy enemy)
	{
		this.enemy = enemy;
	}

	/**
	 * @return the enemyPosition
	 */
	public PositionDynamic getEnemyPosition()
	{
		return enemyPosition;
	}

	/**
	 * @param enemyPosition the enemyPosition to set
	 */
	public void setEnemyPosition(PositionDynamic enemyPosition)
	{
		this.enemyPosition = enemyPosition;
	}


}
