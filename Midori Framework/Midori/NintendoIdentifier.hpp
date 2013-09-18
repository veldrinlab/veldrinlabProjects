#ifndef NINTENDOIDENTIFIER_HPP
#define NINTENDOIDENTIFIER_HPP

#include <vector>

#include "NintendoShaders.hpp"
#include "NintendoFrames.hpp"
#include "Segment.hpp"

namespace Midori
{
	struct NintendoIdentifier
	{
		Window app;
		bool isRunning;
		View view;
		Texture inputTexture;
		NintendoShaders shaders;
		NintendoFrames frames;
		Image image;
		std::vector<Segment*> redSegments;
		std::vector<Segment*> greenSegments;
		std::vector<Segment*> blueSegments;
		std::vector<Segment*> yellowSegments;
		Invariants yPattern;
		Invariants nPattern;
		FrameBuffer result;
		AyumiEngine::AyumiMath::Vector3D min;
		AyumiEngine::AyumiMath::Vector3D max;
		bool foundObject;
	};

	void prepareIdentifier(NintendoIdentifier* identifier);
	void setInputImage(NintendoIdentifier* identifier, const std::string& name);
	void prepareNintendoShaders(NintendoShaders* shaders);
	void prepareNintendoFrames(NintendoFrames* frames);
	void performSegmentation(NintendoIdentifier* identifier);
	void clasifySegments(NintendoIdentifier* identifier, FrameBuffer* frame, std::vector<Segment*>* segments);
	void performBoundaryConditionTest(NintendoIdentifier* identifier, std::vector<Segment*>* segments);
	void divideSegments(NintendoIdentifier* identifier, FrameBuffer* frame, std::vector<Segment*>* segments);
	void calculatePatternsInvariants();
	void calculateInvariants(Invariants* inv, GLuint tex);
	void calculateSegmentsInvariants(NintendoIdentifier* identifier);
	void identifySegmentsInvariants(NintendoIdentifier* identifier);
	void calculateResultData(NintendoIdentifier* identifier);
	void renderInput(NintendoIdentifier* identifier);
	void renderSegmentationResult(NintendoIdentifier* identifier);
	void renderSegment(NintendoIdentifier* identifier, Segment* segment);
	void renderResult(NintendoIdentifier* identifier);
	void releaseResource(NintendoIdentifier* identifier);
}
#endif
