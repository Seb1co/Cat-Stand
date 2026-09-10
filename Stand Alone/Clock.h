#pragma once
#include <thread>
class Clock
{
public:
	Clock();
	void start();
	void start(unsigned short tps);
	void stop();
	std::thread				clockThread;
	bool					shouldRun	= true;

	unsigned short			tps			= 20;
	unsigned int			tpd			= 28800;  // 20(tps) * 60(secs) * 24(minutes)
	unsigned int			tick		= 0;
private:
	void run();
};