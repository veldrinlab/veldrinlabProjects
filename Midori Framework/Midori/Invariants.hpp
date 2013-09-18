#ifndef INVARIANTS_HPP
#define INVARIANTS_HPP

namespace Midori
{
	struct Invariants
	{
		float area;
		float centerX;
		float centerY;
		float M1;
		float M2;
		float M3;
		float M4;
		float M5;
		float M6;
		float M7;
		float M8;
		float M9;
		float M10;

		Invariants()
		{
			area = 0.0f;
			centerX = 0.0f;
			centerY = 0.0f;
			M1 = 0.0f;
			M2 = 0.0f;
			M3 = 0.0f;
			M4 = 0.0f;
			M5 = 0.0f;
			M6 = 0.0f;
			M7 = 0.0f;
			M8 = 0.0f;
			M9 = 0.0f;
			M10 = 0.0f;
		}
	};
}
#endif
