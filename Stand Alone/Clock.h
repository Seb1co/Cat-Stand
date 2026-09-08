#pragma once
class Clock
{
public:
	Clock();
	const unsigned short tps = 60;
	const unsigned int	 tpd = 86400;  // 60()
	unsigned int		 tick = 0;
private:
};