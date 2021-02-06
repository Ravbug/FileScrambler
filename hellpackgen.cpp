#include "Scrambler.hpp"
#include <cxxopts.hpp>

using namespace std;
using namespace std::filesystem;

int main(int argc, char** argv){
	struct settings{
		path name;
		vector<string> skip = {};
		bool invert = false;
		bool penultimate = false;
		bool recursive = false;
	};
#define TRANSPARENTS "lava","water","barrier","beacon","bamboo","bed","bell","brewing","bubble","cactus","cake","campfire","carpet","cauldron","chain","chest","chorus","cobweb","cocoa","compost","conduit","dragon","enchant","rod","pot","glass","grind","honey","bar","ladder","lantern","lily","scaff","pickle","cutter","bush","egg","door","gate","banner","coral","wheat","potato","carrot","beet","gateway","portal","sprout","wart","root","sapling","sea","sign","structure","stem","reed","torch","vine","rail","dust","wire","ice","leaves","daisy","dandelion","peony","poppy","orchid","allium","bluet","tulip","rose","mushroom","fungus","fern"
	settings ops[] = {
		{
			"sounds/block",{},false,true,true
		},
		{
			"sounds/enchant",{},false,true,true
		},
		{
			"sounds/entity",{},false,true,true
		},
		{
			"sounds/item",{},false,true,true
		},
		{
			"sounds/mob",{},false,true,true
		},
		{
			"sounds/ui",{},false,true,true
		},
		{
			"textures/particle"
		},
		{
			"textures/painting"
		},
		{
			"textures/models/armor"
		},
		{
			"textures/mob_effect"
		},
		{
			"textures/item",{"clock","compass"}
		},
		//opaques only
		{
			"textures/block",{TRANSPARENTS,"fire","command","missing","magma","destroy" }
		},
		//transparents only
		{
			"textures/block",{TRANSPARENTS},true
		},
		{
			"sounds/random"
		},
		{
			"sounds/step"
		},
		{
			"sounds/records"
		},
		{
			"sounds/dig"
		},
		{
			"sounds/note"
		},
	};
	
	for(const auto& config : ops){
		Scrambler s(config.name,config.skip,config.invert,config.penultimate,config.recursive);
		s.scramble();
	}
		
	
	return 0;
}
