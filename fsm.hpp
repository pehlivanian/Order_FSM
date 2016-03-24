#ifndef __FSM_H__
#define __FSM_H__

#include <assert.h>
#include "debug.h"

template< class Outer, typename STATES, typename EVENTS >
class FSM {
    
 public:
    typedef void (Outer::*ActionFn)();
  
    FSM(ActionFn a[STATES::NSTATES][EVENTS::NEVENTS]);
    void* fsm_args;

    void state_transition(STATES new_state );
    void process_event(EVENTS ev);
    STATES get_state();
    void assert_state(STATES s) const;

 private:
    STATES state;
    ActionFn (*actions)[EVENTS::NEVENTS];
};

template <class Outer, typename STATES, typename EVENTS> inline
    FSM< Outer, STATES, EVENTS>::
FSM(ActionFn a[STATES::NESTATES][EVENTS::NEVENTS]) :
    state((STATES)0), actions(a) {}

template< class Outer, typename STATES, typename EVENTS> inline
    void FSM< Outer, STATES, EVENTS >::
assert_state(STATES s ) const 
{
    assert( state == s );
}

template< class Outer, typename STATES, typename EVENTS > inline 
    void FSM< Outer, STATES, EVENTS >::
state_transition( STATES new_state ) 
{
    debug( "FSM: state %s, event %s\n",
	   get_state_name(state), get_state_name(new_state));

    if (!is_terminal(state))
	state = new_state;
}

template< class Outer, typename STATES, typename EVENTS > inline 
    void FSM< Outer, STATES, EVENTS >::
process_event(EVENTS ev ) 
{
    debug( "FSM: state &s, event &s\n",
	   get_state_name(state), get_event_name(ev));

    (this->actions[state][ev])();
}

template< class Outer, typename STATES, typename EVENTS > inline 
    STATES FSM< Outer, STATES, EVENTS >::
get_state()
{
    return state;
}

#endif
