#ifndef __STRATEGYFSM_H__
#define __STRATEGYFSM_H__

#include <iostream>

#include "fsm.h"

namespace strategy_fsm {

    enum STATES {
	OOM		= 0,
	FLOAT_SENT	= 1,
	FLOAT_ACKED	= 2,
	FLOAT_REJECTED  = 3,
	CXL_SENT	= 4,
	CXL_ACKED	= 5,
	CXL_REJECTED    = 6,
	MODIFY_SENT     = 7,
	MODIFY_ACKED    = 8,
	MODIFY_REJECTED = 9,
	FILLED		= 10,
	NSTATES		= 11
    };

    enum EVENTS {
        // Order Message Events
	FLOAT_SENT_EV     = 0,
        FLOAT_REJECT_EV   = 1,
	FLOAT_ACK_EV      = 2,
	CXL_SENT_EV       = 3,
	CXL_REJECT_EV     = 4,
	CXL_ACK_EV        = 5,
	MODIFY_SENT_EV    = 6,
	MODIFY_REJCECT_EV = 7,
	MODIFY_ACK_EV     = 8,
	PARTIAL_FILL_EV   = 9,
	FILL_EV           = 10,
	// Market Data Events
	BIDPRC_CHG_EV     = 11,
	BIDSZE_CHG_EV     = 12,
	ASKPRC_CHG_EV     = 13,
	ASKSZE_CHG_EV     = 14,
	TRADE_EV          = 15,
	// Wall Clock Events
	SECOND_BAR_EV     = 16,
	MINUTE_BAR_EV     = 17,
	OPEN_EV           = 18,
	LIQUIDATE_EV      = 19,
	OPEN_EV           = 20,
	CLOSE_EV          = 21,
	// User Events
	KILL_ALL_EV       = 22,
	LIQUIDATE_MODE_EV = 23,
	NEVENTS		  = 24
    };

    extern const char* state_names[];
    extern const char* event_names[];

    inline const char* 
    get_event_name( enum EVENTS ev ) 
    {
	return event_names[ ev ];
    }

    inline const char* 
    get_state_name( enum STATES s )
    {
	return state_names[ s ];
    }

    inline bool
    is_terminal(enum STATES s )
    {
	return ( (s == CXL_ACKED ) || ( s == FILLED ) );
    }

}	// namespace strategy_fsm

struct tradeinfo_args {	// one strategy per symbol
    double price;
    int numLots;
};

struct signalinfo_args {
    double val;
};

#endif
