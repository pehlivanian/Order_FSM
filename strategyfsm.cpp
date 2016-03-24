#include "strategyfsm.hpp"


#include <algorithm>
#include <functional>

namespace strategy_fsm {
    
    const char* state_names[] = {
	OOM,
	FLOAT_SENT,
	FLOAT_ACKED,
	FLOAT_REJECTED,
	CXL_SENT,
	CXL_ACKED,
	CXL_REJECTED,
	MODIFY_SENT,
	MODIFY_ACKED,
	MODIFY_REJECTED,
	FILLED 
    };

    const char* event_names[] = {
        // Order Message Events
	FLOAT_SENT_EV,
        FLOAT_REJECT_EV,
	FLOAT_ACK_EV,
	CXL_SENT_EV,
	CXL_REJECT_EV,
	CXL_ACK_EV,
	MODIFY_SENT_EV,
	MODIFY_REJCECT_EV,
	MODIFY_ACK_EV,
	PARTIAL_FILL_EV,
	FILL_EV,
	// Market Data Events
	BIDPRC_CHG_EV,
	BIDSZE_CHG_EV,
	ASKPRC_CHG_EV,
	ASKSZE_CHG_EV,
	TRADE_EV,
	// Wall Clock Events
	SECOND_BAR_E,
	MINUTE_BAR_EV,
	OPEN_EV,
	LIQUIDATE_EV,
	OPEN_EV,
	CLOSE_EV,
	// User Events
	KILL_ALL_EV,
	LIQUIDATE_MODE_EV 
    };

#define nop &SignalStrategy::nop
#define err &SignalStrategy::err
#define ccx &SignalStrategy::modify
#define af &SignalStrategy::ackFloat
#define uq &SignalStrategy::updateQuote
#define fq &SignalStrategy::fillQuote
#define kq &SignalStrategy::killQuote
#define r_0 &SignalStrategy::region_0Update
#define r_1 &SignalStrategy::region_1Update
#define r_2 &SignalStrategy::region_2Update
#define r_3 &SignalStrategy::region_3Update

   FSM<SignalStrategy, STATES, EVENTS>::ActionFn acts[NSTATES][NEVENTS] = 
     {
	// 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23
	/*OOM*/            {,,,,,,,,,,,,,,,,,,,,,,};
	/*FLOAT_SENT*/     {,,,,,,,,,,,,,,,,,,,,,,};
	/*FLOAT_ACKED*/    {,,,,,,,,,,,,,,,,,,,,,,};
	/*FLOAT_REJECTED*/ {,,,,,,,,,,,,,,,,,,,,,,};
	/*CXL_SENT*/       {,,,,,,,,,,,,,,,,,,,,,,};
	/*CXL_ACKED*/      {,,,,,,,,,,,,,,,,,,,,,,};
	/*CXL_REJECTED*/   {,,,,,,,,,,,,,,,,,,,,,,};
	/*MODIFY_SENT*/    {,,,,,,,,,,,,,,,,,,,,,,};
	/*MODIFY_ACKED*/   {,,,,,,,,,,,,,,,,,,,,,,};
	/*MODIFY_REJECTED*/{,,,,,,,,,,,,,,,,,,,,,,};
	/*FILLED*/         {,,,,,,,,,,,,,,,,,,,,,,};
     };
   
  FSM< SignalStrategy, STATES, EVENTS >::ActionFn acts[NSTATES][NEVENTS} =  {
	// 1, 2, 3, 4,  5, 6, 7, 8, 9, 10,11,12,13,14
    { nop,nop,nop,nop,nop,nop,nop,nop,nop,nop,r_0,r_1,r_2,r_3 };	//0
    { nop,nop,nop,nop,nop,nop, af,err,err,err,r_0,r_1,r_2,r_3 };	//1
    {  uq, uq, uq, uq,nop, err,err,us, fq, kq,r_0,r_1,r_2,r_3};		//2
    { nop,nop,nop,nop,nop,nop,nop,nop,nop, ca,r_0,r_1,r_2,r_3 };	//3
    { nop,nop,nop,nop,nop,nop,nop,nop,nop,nop,r_0,r_1,r_2,r_3 };	//4
    { nop,nop,nop,nop,nop,nop,nop,nop,nop,nop,r_0,r_1,r_2,r_3 };	//5
    };

#undef nop
#undef err
#undef ccx
#undef af
#undef uq
#undef fq
#undef kq
#undef r_0
#undef r_1
#undef r_2
#undef r_3

} // namespace stategy_fsm


using namespace strategy_fsm;

void SignalStrategy:: nop() {
}

void SignalStrategy::err() {
}
void SignalStrategy::modify() { 
}

void SignalStrategy::ackFloat() {
}

void SignalStrategy::updateQuote() {
}

void SignalStrategy::fillQuote() {
}

void SignalStrategy::killQuote() {
}

void SignalStrategy::region_0Update() {
}

void SignalStrategy::region_1Update() {
}

void SignalStrtategy::region_2Update() {
}

void SignalStrategy::region_3Update() {
}

#undef
