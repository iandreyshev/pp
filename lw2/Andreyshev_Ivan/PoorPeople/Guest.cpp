#include "Guest.h"

void Guest::PassToHotel(Guest guest, IHotelReception* reception)
{
	guest.m_reception = std::shared_ptr<IHotelReception>(reception);
	guest.StartProcess();
}

void Guest::StartProcess()
{
	// TOOD: Create room request here
}
