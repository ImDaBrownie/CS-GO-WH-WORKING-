//
//  main.cpp
//  Wall
//
//  for csgo wall hack
//  special edition
//
//  Created by sheep on 16/5/14.
//  Copyright © 2016年 nadp. All rights reserved.
//
//  Created by Andre Kalisch on 30.08.16.
//  Copyright © 2016 aKalisch. All rights reserved.
//
//  This project is a fork from csgoGlow published by iseekwonderful:
//  https://github.com/iseekwonderful/csgoGlow
//
//  Edited by Fricker95 on 1/1/20.

/*
 Usage:
	sudo ./Wall [-f <max flash alpha>] [-r <refresh rate>] [-a <glow alpha>] [-g] [-n] [-s] [-t] [-u] [-o] [-h]

	-f <flash alpha>	: Antiflash alpha max amount (default: -1, disable: -1, range: [0-2700])
	-r <refresh rate>	: Refresh rate in microseconds (default: 10000.0)
	-a <glow alpha>		: Glow alpha (default 0.5, range: [0-1])
	-g			: Enables TriggerBot
	-n			: Disables Ranks
	-s			: Enables Spotted on Radar
	-t			: Enable teammate glow
	-u			: Enable weapons/utility/bomb/chicken glow
	-o			: Get new offsets (only use with -insecure launch option flag in CSGO)
	-h			: Display this message

Example:
	example: sudo ./Wall -f 0 -r 10000 -a 0.5 -g -n -s -t -u

Terminate:
	Type "stop" or "exit" or "quit" or "q" and press the Return key or terminate csgo

Rank Reveal:
	Type "ranks" and press the Return key
		- use command-K to clear the screen
		
	If "playerResource: 0x0 failed"
		- use '-n' to disable the rank revealer until the offset is updated
		
TriggerBot:
	Only works in Fullscreen or Fullscreen Windowed
	Still buggy when tabbing out
	Random click up & down times
	
Note:
	1) -o is currently unavailable
	2) use sv_dump_class_info to find more entity classes
*/

#include "Wall.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

void usage(const char* exec) {
	printf("%s\n", cT::print("\nUsage:", cT::fG::green).c_str());
	printf("\tsudo %s [-f <max flash alpha>] [-r <refresh rate>] [-a <glow alpha>] [-g] [-n] [-s] [-t] [-u] [-o] [-h]\n\n", cT::print(exec, cT::fG::yellow).c_str());
	
	printf("\t-f <flash alpha>\t: Antiflash alpha max amount (default: -1, disable: -1, range: [0-2700])\n");
	printf("\t-r <refresh rate>\t: Refresh rate in microseconds (default: 10000.0)\n");
	printf("\t-a <glow alpha>\t\t: Glow alpha (default 0.5, range: [0-1])\n");
	printf("\t-g\t\t\t: Enables TriggerBot\n");
	printf("\t-n\t\t\t: Disables Ranks\n");
	printf("\t-s\t\t\t: Enables Spotted on Radar\n");
	printf("\t-t\t\t\t: Enable teammate glow\n");
	printf("\t-u\t\t\t: Enable weapons/utility/bomb/chicken glow\n");
	printf("\t-o\t\t\t: Get new offsets (only use with -insecure launch option flag in CSGO)\n");
	printf("\t-h\t\t\t: Display this message\n");
	
	printf("%s\n", cT::print("\nExample:", cT::fG::white).c_str());
	printf("\texample: sudo %s -f 0 -r 10000 -a 0.5 -g -n -s -t -u\n", cT::print(exec, cT::fG::yellow).c_str());
	
	printf("%s\n", cT::print("\nTerminate:", cT::fG::red).c_str());
	printf("\tType \"%s\" or \"%s\" or \"%s\" or \"%s\" and press the Return key or terminate csgo\n", cT::print("stop", cT::fG::yellow).c_str(), cT::print("exit", cT::fG::yellow).c_str(), cT::print("quit", cT::fG::yellow).c_str(), cT::print("q", cT::fG::yellow).c_str());
	
	printf("%s\n", cT::print("\nRank Reveal:", cT::fG::white).c_str());
	printf("\tType \"%s\" and press the Return key\n", cT::print("ranks", cT::fG::yellow).c_str());
	printf("\t\t- use %s to clear the screen\n", cT::print("command-K", cT::fG::yellow).c_str());
	printf("\tIf \"%s\"\n", cT::print("playerResource: 0x0 failed", cT::fG::yellow).c_str());
	printf("\t\t- use %s option to disable the rank revealer\n", cT::print("-n", cT::fG::yellow).c_str());
	
	printf("%s\n", cT::print("\nTriggerBot:", cT::fG::white).c_str());
	printf("\tOnly works in %s or %s\n", cT::print("Fullscreen", cT::fG::yellow).c_str(), cT::print("Fullscreen Windowed", cT::fG::yellow).c_str());
	printf("\tStill buggy when tabbing out\n");
	printf("\tRandom click up & down times\n");
	
	printf("%s\n", cT::print("\nNote:", cT::fG::white).c_str());
	printf("\t1) -o is currently unavailable\n");
	printf("\t2) use sv_dump_class_info to find more entity classes\n");
}

int main(int argc, char** argv) {
	
	double refreshRate 	= 10000.0f;
	double maxFlash 	= -1.0f;
	double glowAlpha 	= 0.5f;

	int opt;

	bool triggerBot 	= false;
	bool getOffsets 	= false;
	bool noRanks 		= false;
	bool noTeammates 	= true;
	bool noUtils 		= true;
	bool spotted 		= false;
	
	while ((opt =  getopt(argc, argv, "f:r:a:gnstuoh")) != -1) {
		switch (opt) {
			case 'f':
				try {
					if (strlen(optarg))
						maxFlash = std::stod(optarg);
				} catch (const std::invalid_argument&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is not a number", cT::fG::red).c_str());
					return 0;
				} catch (const std::out_of_range&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is out of range for a double", cT::fG::red).c_str());
					return 0;
				}
				break;
			case 'r':
				try {
					if (strlen(optarg))
						refreshRate = std::stod(optarg);
				} catch (const std::invalid_argument&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is not a number", cT::fG::red).c_str());
					return 0;
				} catch (const std::out_of_range&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is out of range for a double", cT::fG::red).c_str());
					return 0;
				}
				break;
			case 'a':
				try {
					if (strlen(optarg))
						glowAlpha = std::stod(optarg);
				} catch (const std::invalid_argument&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is not a number", cT::fG::red).c_str());
					return 0;
				} catch (const std::out_of_range&) {
					printf("%s%s%s\n", cT::print("Error: ", cT::fG::red).c_str(), optarg, cT::print(" is out of range for a double", cT::fG::red).c_str());
					return 0;
				}
				break;
			case 'g':
				triggerBot = true;
			case 'n':
				noRanks = true;
			case 's':
				spotted = true;
			case 't':
				noTeammates = false;
				break;
			case 'u':
				noUtils = false;
				break;
			case 'o': // temporarily disabled
				getOffsets = true;
				break;
			case 'h':
				usage(argv[0]);
				exit(0);
		}
	}
	
	// removes macOS mouse acceleration
	std::system("defaults write .GlobalPreferences com.apple.mouse.scaling -1");
	std::system("clear");
	
	Wall wall(refreshRate, maxFlash, glowAlpha, noTeammates, noUtils, noRanks, spotted, triggerBot);

	wall.Run();
	
	return 0;
}
