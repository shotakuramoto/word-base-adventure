all: 
	g++ test.cpp CBA.cpp Player.cpp Locations.cpp Forest.cpp NPC.cpp Trader.cpp -std=c++11

clean:
	rm *.gch a.out

CBA: CBA.cpp Player.cpp Locations.cpp
	g++ CBA.cpp Player.cpp Locations.cpp -std=c++11

Player: Player.cpp Locations.cpp 
	g++ Player.cpp Locations.cpp -std=c++11

Locations: Locations.cpp
	g++ Locations.cpp -std=c++11

TestPlayer:
	g++ PlayerTest.cpp Player.cpp -o Player
	bash PlayerBashTest
	
TestCBA:
	g++ CBATest.cpp CBA.cpp Player.cpp Locations.cpp Forest.cpp NPC.cpp Trader.cpp -std=c++11 -o CBA
	bash CBABashTest
	
TestNPC:
	g++ NPCTest.cpp NPC.cpp Player.cpp -o NPC -std=c++11
	bash NPCBashTest

