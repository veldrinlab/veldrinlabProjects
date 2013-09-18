package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Enumeration that defines animation state of bomb from plant to blow. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public enum BombExploadingState
{
	Planted 
	{
		@Override
		public BombExploadingState getNextState()
		{
			return BombExploadingState.NearBlow;
		}
	},
	NearBlow 
	{
		@Override
		public BombExploadingState getNextState()
		{
			return BombExploadingState.AlmostBlow;
		}
	}, 
	AlmostBlow 
	{
		@Override
		public BombExploadingState getNextState()
		{
			return BombExploadingState.Blow;
		}
	},
	Blow 
	{
		@Override
		public BombExploadingState getNextState()
		{
			return null;
		}
	};
	
	/***
	 * Abstract method of State pattern implemented by BombExploadinfState, use to get next state
	 * 
	 * @return next BombExploadingState state
	 */
	public abstract BombExploadingState getNextState();
}
