package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Enumeration that defines Bomberman moving states.
 * @author Szymon Jablonski
 * @version 1.0
 */
public enum BombermanMoveState
{
	vertex
	{
		@Override
		public BombermanMoveState getNextState(final boolean changeDestination)
		{
			return BombermanMoveState.edgeState1;	
		}
	},
	
	edgeState1 
	{
		@Override
		public BombermanMoveState getNextState(final boolean changeDestination)
		{
			if(!changeDestination)
				return BombermanMoveState.edgeState2;
			
			return BombermanMoveState.vertex;
		}
	},
	
	edgeState2 
	{
		@Override
		public BombermanMoveState getNextState(final boolean changeDestination)
		{
			if(!changeDestination)
				return BombermanMoveState.edgeState3;
			
			return BombermanMoveState.edgeState1;
		}
	},
	
	edgeState3 
	{
		@Override
		public BombermanMoveState getNextState(final boolean changeDestination)
		{
			if(!changeDestination)
				return BombermanMoveState.edgeState4;
			
			return BombermanMoveState.edgeState2;
		}
	},
	edgeState4 
	{
		@Override
		public BombermanMoveState getNextState(final boolean changeDestination)
		{
			if(!changeDestination)
				return BombermanMoveState.vertex;
			
			return BombermanMoveState.edgeState3;
		}
	};
	
	/**
	 * Abstract method of State pattern implemented by BombemrmanMoveState, use to get next state
	 * 
	 * @param changeDestination is true when Player changes destination on Edge, then method return
	 * 		  previous State
	 * @return next move state
	 */
	public abstract BombermanMoveState getNextState(final boolean changeDestination);
}
