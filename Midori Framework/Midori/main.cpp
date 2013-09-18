#include "NintendoIdentifier.hpp"

using namespace Midori;
using namespace std;

int main(int argc, char* argv[])
{
	Configuration::getInstance()->configureEngine("config.lua");
	NintendoIdentifier* identifier = new NintendoIdentifier();
	prepareIdentifier(identifier);

	string name = string(*Configuration::getInstance()->getInput());
	setInputImage(identifier,name);

	renderInput(identifier);
	calculatePatternsInvariants();
	performSegmentation(identifier);
	renderSegmentationResult(identifier);

	calculateSegmentsInvariants(identifier);
	identifySegmentsInvariants(identifier);
	calculateResultData(identifier);

	renderResult(identifier);
	releaseResource(identifier);
}
