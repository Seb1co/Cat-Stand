#include "Clock.h"
#include <chrono>

Clock::Clock() {

}

void Clock::start() {
	this->start(this->tps);
}

void Clock::start(unsigned short tps) {
	this->tps = tps;
	this->tpd = tps * 60 * 10; // tps * secs/min * the amount of minutes a day should have
	this->clockThread = std::thread(&Clock::run,this);
}

void Clock::stop() {
	this->tick = 0;
	this->shouldRun = false;
	if (clockThread.joinable()) {
		clockThread.join();
	}
}

void Clock::run() {
	std::chrono::milliseconds interval(1000 / tps); /// 1000 ms in 1 second, basically calculating the interval in ms between the ticks
	auto nextTick = std::chrono::steady_clock::now() + interval;
	while (shouldRun) {
		std::this_thread::sleep_until(nextTick);

		// Game logic here

		this->tick++;
		if (this->tick >= this->tpd) {
			this->tick = 0;
		}
		nextTick += interval;
	}
}